#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "config_common.h"
extern keymap_config_t keymap_config;

enum planck_layers {
    _US_QWERTY,
    _US_LOWER,
    _US_RAISE,
    _JIS_QWERTY,
    _JIS_LOWER,
    _JIS_RAISE,
    _ADJUST
};

enum planck_keycodes {
    US_QWERTY = SAFE_RANGE,
    US_LOWER,
    US_RAISE,
    JIS_QWERTY,
    JIS_LOWER,
    JIS_RAISE,
    JIS_QUOT,
    JIS_SCLN,
    MAIL
};

#define ADJUST MO(_ADJUST)
#define VOLD LALT(LSFT(KC_VOLD))
#define VOLU LALT(LSFT(KC_VOLU))
#define NKRO_TOG MAGIC_TOGGLE_NKRO
#define CTL_TAB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Adjust| Ctrl | Alt  | GUI  |Lower |             |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_US_QWERTY] = LAYOUT_planck_grid(
            KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
            CTL_TAB, KC_A,     KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
            KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
            ADJUST,  KC_LCTRL, KC_LALT, KC_LGUI, US_LOWER, KC_SPC, KC_SPC, US_RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
            ),
    [_JIS_QWERTY] = LAYOUT_planck_grid(
            KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,
            CTL_TAB, KC_A,     KC_S,    KC_D,    KC_F,      KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    JIS_SCLN, KC_ENT,
            KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  JIS_QUOT,
            ADJUST,  KC_LCTRL, KC_LALT, KC_LGUI, JIS_LOWER, KC_SPC, KC_SPC, JIS_RAISE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
            ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_US_LOWER] = LAYOUT_planck_grid(
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
            _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, VOLD,    VOLU,    KC_MPLY
            ),
    [_JIS_LOWER] = LAYOUT_planck_grid(
            JP_TILD, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______,
            _______, _______, _______, _______, _______, _______, _______, JP_UNDS, JP_PLUS, JP_LCBR, JP_RCBR, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_PIPE,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, VOLD,    VOLU,    KC_MPLY
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
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, VOLD,    VOLU,    KC_MPLY
            ),
    [_JIS_RAISE] = LAYOUT_planck_grid(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
            _______, _______, _______, _______, _______, _______, _______, KC_MINS, JP_EQL,  JP_LBRC, JP_RBRC, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_YEN,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, VOLD,    VOLU,    KC_MPLY
            ),

    /* Adjust
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | US   |RClick|  Up  |LClick|      |      | Left | Down |  Up  |Right |      | NKRO |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | JIS  | Left | Down |  Up  |      |      | WhDN |LClick|RClick| WhUP |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Reset |Audio |Click |Music |      |             |      | HOME |Pg Dn |Pg Up | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
            KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
            US_QWERTY,  KC_BTN2, KC_MS_U, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, NKRO_TOG,
            JIS_QWERTY, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_D, KC_BTN1, KC_BTN2, KC_WH_U, _______, MAIL,
            RESET,      AU_TOG,  CK_TOGG, MU_TOG,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
            )};

#ifdef AUDIO_ENABLE
float tone_layer_on[][2] = SONG(ONE_UP_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t pressed_time;
    static bool is_shift = false;
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        is_shift = record->event.pressed;
        return true;
    }

    switch (keycode) {
        case US_QWERTY:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_layer_on);
#endif
                set_single_persistent_default_layer(_US_QWERTY);
            }
            return false;
            break;
        case JIS_QWERTY:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_layer_on);
#endif
                set_single_persistent_default_layer(_JIS_QWERTY);
            }
            return false;
            break;
        case US_RAISE:
            if (record->event.pressed) {
                pressed_time = timer_read();
                layer_on(_US_RAISE);
                update_tri_layer(_US_LOWER, _US_RAISE, _ADJUST);
            } else {
                layer_off(_US_RAISE);
                update_tri_layer(_US_LOWER, _US_RAISE, _ADJUST);
                if (timer_elapsed(pressed_time) < TAPPING_TERM) {
                    register_code(JP_HENK);
                    unregister_code(JP_HENK);
                    register_code(KC_LANG1);
                    unregister_code(KC_LANG1);
                }
            }
            return false;
            break;
        case JIS_LOWER:
            if (record->event.pressed) {
                pressed_time = timer_read();
                layer_on(_JIS_LOWER);
                update_tri_layer(_JIS_LOWER, _JIS_RAISE, _ADJUST);
            } else {
                layer_off(_JIS_LOWER);
                update_tri_layer(_JIS_LOWER, _JIS_RAISE, _ADJUST);
                if (timer_elapsed(pressed_time) < TAPPING_TERM) {
                    register_code(JP_MHEN);
                    unregister_code(JP_MHEN);
                    register_code(KC_LANG2);
                    unregister_code(KC_LANG2);
                }
            }
            return false;
            break;
        case JIS_RAISE:
            if (record->event.pressed) {
                pressed_time = timer_read();
                layer_on(_JIS_RAISE);
                update_tri_layer(_JIS_LOWER, _JIS_RAISE, _ADJUST);
            } else {
                layer_off(_JIS_RAISE);
                update_tri_layer(_JIS_LOWER, _JIS_RAISE, _ADJUST);
                if (timer_elapsed(pressed_time) < TAPPING_TERM) {
                    register_code(JP_HENK);
                    unregister_code(JP_HENK);
                    register_code(KC_LANG1);
                    unregister_code(KC_LANG1);
                }
            }
            return false;
            break;
        case JIS_QUOT:
            if (record->event.pressed) {
                if (is_shift) {
                    register_code(KC_LSFT);
                    register_code(KC_2);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_7);
                }
            } else {
                unregister_code(KC_2);
                unregister_code(KC_7);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
        case JIS_SCLN:
            if (record->event.pressed) {
                if (is_shift) {
                    unregister_code(KC_LSFT);
                    register_code(KC_QUOT);
                } else {
                    register_code(KC_SCLN);
                }
            } else {
                unregister_code(KC_SCLN);
                unregister_code(KC_QUOT);
            }
            return false;
            break;
        case MAIL:
            if (record->event.pressed) {
                SEND_STRING("zipperr@i.softbank.jp")
            }
            return false;
            break;
    }
    return true;
}
