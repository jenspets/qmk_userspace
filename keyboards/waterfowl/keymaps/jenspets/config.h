#pragma once

#ifdef MOUSEKEY_ENABLE
     // The default is 100
#    define MOUSEKEY_WHEEL_INTERVAL 50
     // The default is 40
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

#ifdef ENCODER_ENABLE
#define ENC_LR 0       // Left and right
#define ENC_VOLUME 1   // Volume knob
#define ENC_PAGE_UD 2  // Page up and page down
#define ENC_UD 3       // Up and down
#endif

#define NO_QWERTY
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
