#ifndef CONFIG_USER_H
#define CONFIG_USER_H
#define FORCE_NKRO
#define TAPPING_TERM               200
#define USB_MAX_POWER_CONSUMPTION  100
#define MOUSEKEY_DELAY             100
#define MOUSEKEY_INTERVAL          10
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_TIME_TO_MAX       0
#define MOUSEKEY_WHEEL_MAX_SPEED   4
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#define ENCODER_RESOLUTION         4
#define MIDI_BASIC
#define B5_AUDIO
#define B6_AUDIO
#define B7_AUDIO
#define C4_AUDIO
#define C5_AUDIO
#define C6_AUDIO
#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define LAYER_LOCK_ON_SOUND \
    E__NOTE(_C4),         \
    E__NOTE(_G4),
    #define LAYER_LOCK_OFF_SOUND \
    E__NOTE(_G4),         \
    E__NOTE(_C4),
    #define PUSH_SOUND \
    E__NOTE(_B3),
    #define ADJUST_ON_SOUND \
    E__NOTE(_C4 ),
    #define ADJUST_OFF_SOUND \
    E__NOTE(_A4 ),
    /* #define STARTUP_SONG SONG(PLANCK_SOUND) */
    // #define STARTUP_SONG SONG(NO_SOUND)
    /* #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \ */
    /*                               SONG(COLEMAK_SOUND), \ */
    /*                               SONG(DVORAK_SOUND), \ */
    /*                               SONG(PLOVER_SOUND) \ */
    /*                             } */
#endif
#endif
