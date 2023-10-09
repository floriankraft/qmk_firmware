# Readme LeleLab Y2K 76

## Useful commands

Show keymap as defined in info.json:

```bash
qmk info -kb lelelab/lele76_orig -km default -l
```

## Open issues

-   [ ] ✘ Moved app version from `DEVICE_VER` in `config.h` to `usb.device_version` in `info.json`.
    -   The `info.json` introduces constraint that version needs to match `^[0-9]{1,2}\\.[0-9]\\.[0-9]$`.
    -   Old version was `0x0390` and new version is now `3.9.0` which might not be an exact representation.
