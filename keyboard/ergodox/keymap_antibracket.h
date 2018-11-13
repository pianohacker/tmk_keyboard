#include <action_layer.h>
#include <action_util.h>

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        RBRC,1,   2,   3,   4,   5,   FN2,
        TAB, Q,   W,   E,   R,   T,   MYCM,
        CAPS,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   ENT,
        LGUI,GRV, PGDN,PGUP,LALT,
                                      FN8, VOLU,
                                           VOLD,
                                 FN7, FN1, ESC,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             BSPC,Y,   U,   I,   O,   P,   LBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             ENT, N,   M,   COMM,DOT, SLSH,RSFT,
                       RALT,LEFT,DOWN,UP,  RGHT,
        MUTE,FN8,
		FN5,
        TAB, FN1, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,PGUP,BSPC,UP,  DEL, PGDN,FN4,
        TRNS,HOME,LEFT,DOWN,RGHT,END,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 FN7, TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, FN3,
             TRNS,MINS,7,   8,   9,   TRNS,TRNS,
                  DOT, 4,   5,   6,   ESC, TRNS,
             TRNS,0,   1,   2,   3,   TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,ENT
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN0,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 3: steno
        // left hand
        TRNS,F24, F24, F24, F24, F24, TRNS,
        TRNS,LANG5,INT1,LANG4,INT2,LANG2,TRNS,
        TRNS,LANG5,LANG3,INT4,INT5,LANG2,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN4, TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 INT6,LANG1,TRNS,
        // right hand
             TRNS,F24, F24, F24, F24, F24, TRNS,
             TRNS,LANG2,SELECT,F14,F16,F18,F20,
                  LANG2,EXECUTE,F15,F17,F19,F23,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        FN6, INT3,MENU
    ),

    KEYMAP(  // layer 4: mouse
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,
        TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,
        TRNS,WH_L,WH_D,WH_U,WH_R,ACL1,ACL2,
        TRNS,TRNS,TRNS,TRNS,ACL0,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,
                  TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,
             ACL0,ACL1,WH_L,WH_D,WH_U,WH_R,TRNS,
                       ACL2,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
	START_STENO,
	END_STENO,
	LCTRL_BSPACE,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(1),                      // FN1 - switch to Layer1
    ACTION_LAYER_SET(2, ON_PRESS),                  // FN2 - push Layer2
    ACTION_LAYER_SET(3, ON_PRESS),                  // FN3 - push Layer3
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN4 - push Layer0
    ACTION_FUNCTION(START_STENO),
    ACTION_FUNCTION(END_STENO),
	ACTION_FUNCTION(LCTRL_BSPACE),
    ACTION_LAYER_MOMENTARY(4),                      // FN1 - switch to Layer1
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt) {
	extern uint32_t layer_state;

	switch (id) {
		case TEENSY_KEY:
			if (!event->event.pressed) return;

			clear_keyboard();
			print("\n\nJump to bootloader... ");
			_delay_ms(250);
			bootloader_jump(); // should not return
			print("not supported.\n");
			break;

		case START_STENO:
			if (!event->event.pressed) return;

			clear_keyboard();
			default_layer_set(8);
			ergodox_right_led_3_on();
			keyboard_nkro = true;
			break;

		case END_STENO:
			if (!event->event.pressed) return;

			clear_keyboard();
			default_layer_set(0);
			ergodox_right_led_3_off();
			keyboard_nkro = false;
			break;
		
		case LCTRL_BSPACE:
			if (event->event.pressed) {
				if (layer_state & 2) {
					add_key(KC_BSPACE);
				} else {
					add_mods(MOD_BIT(KC_LCTRL));
				}
			} else {
				del_key(KC_BSPACE);
				del_mods(MOD_BIT(KC_LCTRL));
			}
			send_keyboard_report();
			break;
    }
}
