#include QMK_KEYBOARD_H
#define _base 0
#define _extend 1
// definition unicode pour accent
#define UC_EA UC(0x00E9)
#define UC_EG UC(0x00E8)
#define UC_EC UC(0x00EA)
#define UC_AA UC(0x00E0)
#define UC_CC UC(0x00E7)
#define UC_IP UC(0x00EF)

// tap dance time
#define TAPPING_TERM 200

// Declarations Macro
enum custom_keycodes {
  M_integra = SAFE_RANGE,
  M_impassenet
};


// Declarations Tap Dance
enum {
  td_e,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_base] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,\
		  KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,\
			OSL(1),        KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,\
		  KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,\
		  KC_LCTL,       TD(td_e),  KC_LALT,                KC_SPC,                KC_RALT,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_extend] = LAYOUT_65_ansi_blocker( /* extend */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_MUTE,\
		  KC_TRNS,       RGB_TOG,  RGB_MOD, UC_EA,  RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, UC_IP, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,    KC_VOLU,\
			_______,       UC_AA,    RGB_SPD, KC_TRNS,UC_EG, UC_EC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_VOLD,\
		  KC_LSFT,       KC_TRNS,  KC_TRNS, UC_CC,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          _______,  _______,\
		  KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   _______,          KC_TRNS,  M_impassenet,     _______,  M_integra),
};
// Unicode input Linux
void matrix_init_user(void)
{
  set_unicode_input_mode(UC_LNX);
}

void matrix_scan_user(void)
{
  //user matrix
}

// Action Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
  [td_e] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_MYCM),
};


// Definitions Macro 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case M_integra:
      if (record->event.pressed) {
        SEND_STRING("xxxxx");
      } else {
		  // when keycode M_integra is released
      }
      break;
    case M_impassenet:
      if (record->event.pressed) {
		    SEND_STRING("xxxxx" SS_TAP(X_ENTER));
      } else {
		  // when keycode M_impassenet is released
      }
      break;
  }
  return true;
}
