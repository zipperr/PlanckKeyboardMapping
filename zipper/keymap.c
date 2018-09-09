#include "planck.h"
#include "action_layer.h"
#include "muse.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _US_QWERTY,
  _JIS_QWERTY,
  _US_LOWER,
  _US_RAISE,
  _JIS_LOWER,
  _JIS_RAISE,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  US_QWERTY = SAFE_RANGE,
  JIS_QWERTY,
  JIS_QUOT,
  JIS_SCLN
};

enum user_macro {
  US_EMHL,
  US_KHKR,
  JIS_EMHL,
  JIS_KHKR
};

#define M_US_EMHL MACROTAP(US_EMHL)
#define M_US_KHKR MACROTAP(US_KHKR)
#define M_JIS_EMHL MACROTAP(JIS_EMHL)
#define M_JIS_KHKR MACROTAP(JIS_KHKR)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty(US配列)
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
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    MOUSE,   KC_LCTL, KC_LALT, KC_LGUI, M_US_EMHL, KC_SPC, KC_SPC, M_US_KHKR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower(US配列)
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  |  |   |  ~   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |  \  |   `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_US_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise(US配列)
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_US_RAISE] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Qwerty(JIS配列)
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | "    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOUSE | Ctrl | Alt  | GUI  |Lower |             |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_JIS_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    JIS_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH,  JIS_QUOT,
    MOUSE,   KC_LCTL, KC_LALT, KC_LGUI, M_JIS_EMHL, KC_SPC, KC_SPC, M_JIS_KHKR, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),

/* Lower(JIS配列)
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  |  |   |  ~   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |  \  |   `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_JIS_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS,
    _______, _______, _______, _______, _______, _______, _______, _______, JP_LCBR, JP_RCBR, JP_PIPE, JP_TILD,
    _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, JP_YEN,  JP_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise(JIS配列)
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_JIS_RAISE] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, JP_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|  US  | JIS  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TERMon|TERMof|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | HOME |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,      KC_F10,  KC_F11,  KC_F12,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, US_QWERTY, JIS_QWERTY, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON,   TERM_OFF,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,   KC_HOME,    KC_PGDN, KC_PGUP, KC_END
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Btn1 | Btn2 |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | WhUP | WhDN |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     lshift = false;

    switch (keycode) {
        case US_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_US_QWERTY);
            }
            return false;
            break;
        case JIS_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_JIS_QWERTY);
            }
            return false;
            break;
        case JIS_QUOT:
            if (record->event.pressed) {
                lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
                register_code(KC_LSFT);
                if (lshift) {
                    register_code(KC_LSFT);
                    register_code(KC_2);
                    unregister_code(KC_2);
                    unregister_code(KC_LSFT);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_7);
                    unregister_code(KC_7);
                    unregister_code(KC_LSFT);
                }
            }
            return false;
            break;
        case JIS_SCLN:
            if (record->event.pressed) {
                lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
                if (lshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    register_code(KC_QUOT);
                    unregister_code(KC_QUOT);
                    if (lshift) register_code(KC_LSFT);
                } else {
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                }
            }
            return false;
            break;
    }
    return true;
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
