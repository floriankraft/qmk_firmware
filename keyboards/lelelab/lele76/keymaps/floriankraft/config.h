#pragma once
#define OLED_IC OLED_IC_SH1106
// #define OLED_DISPLAY_CUSTOM

#undef OLED_TIMEOUT_ENABLE
#define OLED_UPDATE_INTERVAL 50
#define OLED_SCROLL_TIMEOUT 0
#define OLED_DISABLE_TIMEOUT 5

#define F_SCL 400000UL

#define TASK_TIME_LIMIT 1

#define ENCODER_MAP_KEY_DELAY 40
#define TAP_CODE_DELAY 40
