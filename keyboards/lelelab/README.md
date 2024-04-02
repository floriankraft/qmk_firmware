# README LeleLab Y2K

## Status

**Folder lele76**

-   Original sources obtained through Discord channel, but build failed to build in the beginning.
-   Compiling succeeds now, but keyboard will not function with this firmware.
-   Keyboard is connecting and disconnecting to/from OS over and over again.
-   Debugging would be needed to see what code is causing the issue.

**Folder lele76_florian**

-   My personal attempt to build a very basic firmware based on the most recent QMK files.
-   Compiling succeeds, but not working with the keyboard right now.
-   Pressing keys has no effect right now. Not sure if the keyboard even started to work.

**Folder lele76_minimal**

-   Based on lele76, removed just everything except the absolutely necessary pieces.
-   This is the smallest build I can imagine.
-   It is working but without any extras like RGB or OLED.

**Folder lele76_orig**

-   Another set of sources, also obtained through the LeleLab Discord channel.
-   Nothing changed from my side.
-   No plans for that right now.

## How to Build

## Useful commands

Replace the following parameters with the actual keyboard and keymap path.

**Build**

```bash
qmk compile -kb lelelab/lele76 -km default
```

**Keymap Overview**

Show keymap as defined in info.json.

```bash
qmk info -kb lelelab/lele76 -km default -l
```
