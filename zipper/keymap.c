#include "planck.h"
#include "action_layer.h"
#include "muse.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _US_QWERTY,
  _US_LOWER,
  _US_RAISE,
  _JIS_QWERTY,
  _JIS_LOWER,
  _JIS_RAISE,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  US_QWERTY = SAFE_RANGE,
  JIS_QWERTY,
  JIS_QUOT,
  JIS_SCLN,
  EEPROM
};

enum user_macro {
  US_EMHL,
  US_KHKR,
  JIS_EMHL,
  JIS_KHKR
};

#define US_LOWER MACROTAP(US_EMHL)
#define US_RAISE MACROTAP(US_KHKR)
#define JIS_LOWER MACROTAP(JIS_EMHL)
#define JIS_RAISE MACROTAP(JIS_KHKR)
#define MOUSE MO(_MOUSE)
#define CTL_TAB CTL_T(KC_TAB)
#define VOLD LT(_MOUSE, KC_VOLD)
#define VOLU CTL_T(KC_VOLU)
#define GUI_ON MAGIC_UNNO_GUI
#define GUI_OFF MAGIC_NO_GUI
#define NKRO_ON MAGIC_HOST_NKRO
#define NKRO_OFF MAGIC_UNHOST_NKRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | "    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOUSE | Ctrl | Alt  | GUI  |Lower |             |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 
[_US_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,        KC_Q, KC_W,    KC_E,    KC_R,      KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,
    CTL_TAB,       KC_A, KC_S,    KC_D,    KC_F,      KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_ENT,
    OSM(MOD_LSFT), KC_Z, KC_X,    KC_C,    KC_V,      KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  KC_QUOT,
    VOLD,          VOLU, KC_LALT, KC_LGUI, US_LOWER,  KC_SPC, KC_SPC, US_RAISE,  KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),
[_JIS_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,        KC_Q, KC_W,    KC_E,    KC_R,      KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,
    CTL_TAB,       KC_A, KC_S,    KC_D,    KC_F,      KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    JIS_SCLN, KC_ENT,
    OSM(MOD_LSFT), KC_Z, KC_X,    KC_C,    KC_V,      KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  JIS_QUOT,
    VOLD,          VOLU, KC_LALT, KC_LGUI, JIS_LOWER, KC_SPC, KC_SPC, JIS_RAISE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_US_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),
[_JIS_LOWER] = LAYOUT_planck_grid(
    JP_TILD, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______, JP_UNDS, JP_PLUS, JP_LCBR, JP_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_US_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),
[_JIS_RAISE] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, JP_EQL,  JP_LBRC, JP_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_YEN,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |AGS on|TERMon|Aud on|MIDIon|Mus on|NKROon|GUIon | US   |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |AGSoff|TERMof|Audoff|MIDIof|Musoff|NKROof|GUIoff| JIS  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |MUcycl|      |             |      | HOME |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,    KC_F3,   KC_F4,  KC_F5,   KC_F6,    KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,
    AG_SWAP, TERM_ON,  AU_ON,   MI_ON,  MU_ON,   NKRO_ON,  GUI_ON,  US_QWERTY,  _______, _______, _______, _______,
    AG_NORM, TERM_OFF, AU_OFF,  MI_OFF, MU_OFF,  NKRO_OFF, GUI_OFF, JIS_QWERTY, _______, _______, _______, _______,
    RESET,   _______,  _______, MU_MOD, _______, _______,  _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Btn1 | Btn2 |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | ACL2 | ACL1 | ACL0 |      |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | WhUP | WhDN |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,
    _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______,
    US_QWERTY, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
)
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(default_layer_state)) {
        case _US_QWERTY:
            state = update_tri_layer_state(state, _US_LOWER, _US_RAISE, _ADJUST);
            break;
        case _JIS_QWERTY:
            state = update_tri_layer_state(state, _JIS_LOWER, _JIS_RAISE, _ADJUST);
            break;
        }
    return state;
}

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(STARTUP_SOUND);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

static bool is_shift_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        is_shift_pressed = record->event.pressed;
        return true;
    }

    switch (keycode) {
        case US_QWERTY:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(tone_qwerty);
                #endif
                set_single_persistent_default_layer(_US_QWERTY);
            }
            return false;
            break;
        case JIS_QWERTY:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(tone_qwerty);
                #endif
                set_single_persistent_default_layer(_JIS_QWERTY);
            }
            return false;
            break;
        case JIS_QUOT:
            if (is_shift_pressed) {
                if (record->event.pressed) {
                    register_code(KC_2);
                } else {
                    unregister_code(KC_2);
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_LSFT);
                    register_code(KC_7);
                } else {
                    unregister_code(KC_7);
                    unregister_code(KC_LSFT);
                }
            }
            return false;
            break;
        case JIS_SCLN:
            if (is_shift_pressed) {
                if (record->event.pressed) {
                    unregister_code(KC_LSFT);
                    register_code(KC_QUOTE);
                } else {
                    unregister_code(KC_QUOTE);
                    register_code(KC_LSFT);
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_SCLN);
                } else {
                    unregister_code(KC_SCLN);
                }
            }
            return false;
            break;
        case EEPROM:
            eeconfig_init();
            return false;
            break;
    }
    return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    switch(id) {
        case US_EMHL:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _US_LOWER );
        case US_KHKR:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _US_RAISE );
        case JIS_EMHL:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _JIS_LOWER );
        case JIS_KHKR:
            return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _JIS_RAISE );
        };
        return MACRO_NONE;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case US_RAISE:
    case US_LOWER:
    case JIS_RAISE:
    case JIS_LOWER:
      return false;
    default:
      return true;
  }
}

#ifdef AUDIO_ENABLE
    void startup_user()
    {
        wait_ms(20);
        PLAY_SONG(tone_startup);
    }

    void shutdown_user()
    {
        PLAY_SONG(tone_goodbye);
        wait_ms(150);
        stop_all_notes();
    }

    void music_on_user(void)
    {
        music_scale_user();
    }

    void music_scale_user(void)
    {
        PLAY_SONG(music_scale);
    }
#endif
