#include "akari.h"

//added by xc 
bool is_alt_tab_active = false; // Super Alt Tab Code
uint16_t alt_tab_timer = 0;
#ifdef VIA_ENABLE
    enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
      ATABF = USER00, //Alt tab forwards
      ATABR //Alt tab reverse
    };
#else
    enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
      ATABF = SAFE_RANGE, //Alt tab forwards
      ATABR //Alt tab reverse
    };
#endif
//ended by xc

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("0\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_NO,  KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8, KC_F9,  KC_F10,   KC_F11,  KC_F12,  KC_PSCR,  KC_HOME,
		KC_NO,  KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,  KC_9,    KC_0,  KC_MINS,  KC_EQL,  KC_BSLS,   KC_DEL,
		KC_NO,  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,  KC_O,    KC_P,  KC_LBRC, KC_RBRC,  KC_BSPC,  KC_PGUP,
		KC_NO, KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,  KC_NO,   KC_J,   KC_K,  KC_L, KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGDN,
		KC_NO, KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_H,   KC_M,KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,             KC_UP,   KC_END,
		KC_NO, KC_LCTL,KC_LGUI,KC_LALT,         KC_SPC,  MO(1),   KC_N, KC_SPC,       KC_RCTL,           KC_RGUI,   KC_LEFT,KC_DOWN,KC_RIGHT),
		

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

//void matrix_scan_user(void) {
//}


//below added by xc replace above part 2
void matrix_scan_user(void) { //run whenever user matrix is scanned
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
//above added by xc part 2


//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  return true;
//}

//below added by xc part 3
bool process_record_user(uint16_t keycode, keyrecord_t *record) { //Actions to override existing key behaviours
    switch (keycode) { //For super alt tab keycodes
    case ATABF: //Alt tab forwards
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ATABR: //Alt tab reverse
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_LSHIFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_TAB);
      }
      break;
    }
    return true;
};
//above by xc part 3

// void encoder_update_user(uint8_t index, bool clockwise) 
// {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 2));
//         }
//         } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 2));
//     	}} else if (index == 2) { /* 3 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 0));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 2));
//     	}} else if (index == 3) { /* 4 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 0, 11));
//     	}} else if (index == 4) { /* 5 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 1, 11));
//     	}} else if (index == 5) { /* 6 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 2, 11));
//     	}} else if (index == 6) { /* 7 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 9));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 11));
//     	}} else if (index == 7) { /* 8 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 3));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 5));
//     	}} else if (index == 8) { /* 9 encoder */
//         if (clockwise) {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 6));
//         } else {
//             tap_code(dynamic_keymap_get_keycode(biton32(layer_state), 3, 8));
//     	}
// 	}
// }

bool encoder_update_user(uint8_t index, bool clockwise) 
{
    if (index == 0) { /* 1 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

    else if (index == 1) { /* 2 encoder */
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 0}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 0}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});
        	} 
        	else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 2}, .pressed = true, .time = (timer_read() | 1)  /* time should not be 0 */});
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 2}, .pressed = false, .time = (timer_read() | 1)  /* time should not be 0 */});  
            }
    }

	return true;
}

/*
// 以下为RGB灯效分层设置：--------------------------------------------------------------------------------
// Light LEDs 0 to 6 in YELLOW when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_WHITE});
// Light LEDs 0 to 6 in RED when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_RED});
// Light LEDs 6 to 11 in GREEN when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_GREEN});
// Light LEDs 12 to 17 in BLUE when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_BLUE});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	my_capslock_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer       
    // Overrides other layers
);

void keyboard_post_init_user(void)
{    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state)
{    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}


bool led_update_user(led_t led_state)
{
   rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// 以上为RGB灯效分层设置：--------------------------------------------------------------------------------
*/


layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case 0:
			rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
			break;
		case 1:
			rgb_matrix_mode(RGB_MATRIX_CYCLE_SPIRAL);
			break;
		case 2:
			rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
			break;
		case 3:
			rgb_matrix_mode(RGB_MATRIX_RAINBOW_BEACON);
			break;
		case 4:
			rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
			break;
		default:
			rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
	}
	return state;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}