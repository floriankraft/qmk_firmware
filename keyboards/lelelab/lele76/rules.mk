MCU = atmega32a
F_CPU = 16000000
BOOTLOADER = usbasploader

MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_KEYCODE_ENABLE = no

LTO_ENABLE = yes

OLED_DRIVER = ssd1306
OLED_IC = OLED_IC_SH1106