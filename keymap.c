#include QMK_KEYBOARD_H
#define _base 0
#define _extend 1


// tap dance time
#define TAPPING_TERM 150

// Declarations Macro
enum custom_keycodes {
  M_integra = SAFE_RANGE,
  M_impassenet
};


// Declarations Tap Dance
enum {
  td_e = 0,
  td_a,
  td_i,
  td_c,
  td_exp
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_base] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,\
		  KC_TAB,        KC_Q,     KC_W,     TD(td_e),  KC_R,  KC_T,  KC_Y,    KC_U,  TD(td_i),    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,\
			OSL(1),        TD(td_a),     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,\
		  KC_LSFT,       KC_Z,     KC_X,     TD(td_c),  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,\
		  KC_LCTL,       TD(td_exp),  KC_LALT,                KC_SPC,                KC_RALT,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_extend] = LAYOUT_65_ansi_blocker( /* extend */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_MUTE,\
		  KC_TRNS,       RGB_TOG,  RGB_MOD, KC_TRNS,  RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,    KC_VOLU,\
			_______,       KC_TRNS,    RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_VOLD,\
		  KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          _______,  _______,\
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

// fonction tap dance e accent
void e_accent (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count){
    case 1:
      tap_code(KC_E);
      break;
    case 2:
      unicode_input_start();
      register_hex( 0x00E9 );
      unicode_input_finish();
      break;
    case 3:
      unicode_input_start();
      register_hex( 0x00E8 );
      unicode_input_finish();
      break;
  }
}

// fonction tap dance i accent
void i_accent (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count){
    case 1:
      tap_code(KC_I);
      break;
    case 2:
      unicode_input_start();
      register_hex( 0x00EE );
      unicode_input_finish();
      break;
  }
}

// fonction tap dance a accent
void a_accent (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count){
    case 1:
      tap_code(KC_A);
      break;
    case 2:
      unicode_input_start();
      register_hex( 0x00E0 );
      unicode_input_finish();
      break;
  }
}

// fonction tap dance c cedille
void c_cedi (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count){
    case 1:
      tap_code(KC_C);
      break;
    case 2:
      unicode_input_start();
      register_hex( 0x00E7 );
      unicode_input_finish();
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [td_a] = ACTION_TAP_DANCE_FN(a_accent),
    [td_e] = ACTION_TAP_DANCE_FN(e_accent),
    [td_i] = ACTION_TAP_DANCE_FN(i_accent),
    [td_c] = ACTION_TAP_DANCE_FN(c_cedi),
    [td_exp] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_MYCM),
};


// Definitions Macro 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case M_integra:
      if (record->event.pressed) {
        SEND_STRING("xxxx");
      } else {
		  // when keycode M_integra is released
      }
      break;
    case M_impassenet:
      if (record->event.pressed) {
		    SEND_STRING("xxxx" SS_TAP(X_ENTER));
      } else {
		  // when keycode M_impassenet is released
      }
      break;
  }
  return true;
}
