# AGENTS.md — esp32-c3-bt-media-control

Generic rules for this PlatformIO project. Project-specific notes in this
project's own non-README `.md` files (TODO.md etc.) override this file.

## Step 0: read the notes first
    find . \( -name lib -o -name .pio -o -name .git \) -prune -o -type f -iname '*.md' ! -iname 'README*' -print | sort
Read each file fully before touching code. README.md may be skimmed after.
If there is no such file, say so and work from the code; do not invent a structure.

## Project facts
- PlatformIO env: esp32-c3-devkitc-02 (see platformio.ini for board/platform/framework)
- Do not assume an upload port, baud, or OTA method: read platformio.ini and the code.

## Rules
- Never edit `lib/` (third-party). Edit only `src/` and `include/` unless the project notes say otherwise.
- Back up a file before editing it, and show the diff afterwards.
- If information is missing, ask or run a read-only check. Do not guess code, pins, or structure you have not seen.
- No secrets in code or docs: credentials live in credentials.h / env vars; never print their values.
- After any code change, verify with `platformio run -e esp32-c3-devkitc-02` and report RAM/Flash from the build output.

## Mesh (only if this project joins the ESP-NOW mesh)
- Read `../esp-now-ota-master/MESH-HANDOFF.md` first. In it: Decided = user confirmed, Proposed = NOT agreed, Open = unanswered. Never treat Proposed/Open as decisions.
- At the END of a mesh task: update MESH-HANDOFF.md (move items, append to "Task log").
