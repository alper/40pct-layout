/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,---------------------------------------------------------------------------------------------------.
   * | Esc       |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I      |   O  |   P  |    Bksp     |
   * |-----------+------+------+------+------+-------------+------+----------+------+------+-------------|
   * | Ctrl/Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K      |   L  |   ;  |     "       |
   * |-----------+------+------+------+------+------|------+------+----------+------+------+-------------|
   * | Shift/Esc |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,      |   .  |   /  | Shift/Enter |
   * |-----------+------+------+------+------+------+------+------+----------+------+------+-------------|
   * | Tab       | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI/Left | Down |  Up  |    Right    |
   * `---------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,                  KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,                  KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,               KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT),
    KC_TAB,               KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   MT(MOD_RGUI, KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Dvorak
   * ,---------------------------------------------------------------------------------------------------.
   * | Esc       |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C      |   R  |   L  | Bksp        |
   * |-----------+------+------+------+------+-------------+------+----------+------+------+-------------|
   * | Ctrl/Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T      |   N  |   S  | /           |
   * |-----------+------+------+------+------+------|------+------+----------+------+------+-------------|
   * | Shift/Esc |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W      |   V  |   Z  | Shift/Enter |
   * |-----------+------+------+------+------+------+------+------+----------+------+------+-------------|
   * | Tab       | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI/Left | Down |  Up  | Right       |
   * `---------------------------------------------------------------------------------------------------'
   */
  [_DVORAK] = LAYOUT_planck_mit(
    KC_ESC,               KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,    KC_F,    KC_G,    KC_C,                  KC_R,    KC_L,    KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A,    KC_O,    KC_E,    KC_U,  KC_I,    KC_D,    KC_H,    KC_T,                  KC_N,    KC_S,    KC_SLSH,
    KC_LSFT,              KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,    KC_B,    KC_M,    KC_W,                  KC_V,    KC_Z,    MT(MOD_RSFT, KC_ENT),
    KC_TAB,               KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,      RAISE,   MT(MOD_RGUI, KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______,     _______,      _______,    KC_MFFD,    KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------.
   * |   `       |   1     |      2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |-----------+---------+---------+------+------+-------------+------+------+------+------+------|
   * | Del       |  F1     |  F2     |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |-----------+---------+---------+------+------+------|------+------+------+------+------+------|
   * |           |  F7     |  F8     |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
   * |-----------+---------+---------+------+------+------+------+------+------+------+------+------|
   * | AppSwitch | PrevTab | NextTab |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `----------------------------------------------------------------------------------------------'
   */
   [_RAISE] = LAYOUT_planck_mit(
    KC_GRV,         KC_1,                     KC_2,                     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,         KC_F1,                    KC_F2,                    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______,        KC_F7,                    KC_F8,                    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    LGUI(KC_GRAVE), LGUI(LSFT(KC_LBRC)),  LGUI(LSFT(KC_RBRC)),  _______, _______, _______,          _______, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset|Debug |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |AGnorm|AGswap|Qwerty|      |Dvorak|      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_mit(
    _______, QK_RBT,  DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  _______, DVORAK,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
