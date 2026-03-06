#include <Arduino.h>
#include <BleKeyboard.h>
#include <NimBLEDevice.h>

BleKeyboard bleKeyboard("ESP32-Music-Remote", "Espressif", 100);

// #define __DEBUG

#define BTN_PREV       7
#define BTN_PLAY_PAUSE 9
#define BTN_NEXT       8

bool lastBtnPrevState = HIGH;
bool lastBtnPlayPauseState = HIGH;
bool lastBtnNextState = HIGH;

void setup() {
  #ifdef __DEBUG
  Serial.begin(115200);
  #endif

  pinMode(BTN_PREV, INPUT_PULLUP);
  pinMode(BTN_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(BTN_NEXT, INPUT_PULLUP);

  #ifdef __DEBUG
  Serial.println("Starting BLE work!");
  #endif

  NimBLEDevice::init("ESP32-Remote");
  NimBLEDevice::setSecurityAuth(true, false, false);
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    if(digitalRead(BTN_PLAY_PAUSE) == LOW && lastBtnPlayPauseState == HIGH) {
      #ifdef __DEBUG
      Serial.println("Sending: Play/Pause");
      #endif

      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      lastBtnPlayPauseState = LOW;
      delay(100);
    } else {
      lastBtnPlayPauseState = digitalRead(BTN_PLAY_PAUSE);
    }

    if(digitalRead(BTN_NEXT) == LOW && lastBtnNextState == HIGH) {
      #ifdef __DEBUG
      Serial.println("Sending: Vol Up");
      #endif

      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      lastBtnNextState = LOW;
      delay(100);
    } else {
      lastBtnNextState = digitalRead(BTN_NEXT);
    }

    if(digitalRead(BTN_PREV) == LOW && lastBtnPrevState == HIGH) {
      #ifdef __DEBUG
      Serial.println("Sending: Vol Down");
      #endif

      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      lastBtnPrevState = LOW;
      delay(100);
    } else {
      lastBtnPrevState = digitalRead(BTN_PREV);
    }

    bleKeyboard.releaseAll();
  }
}