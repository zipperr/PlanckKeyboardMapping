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
#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif
#endif
