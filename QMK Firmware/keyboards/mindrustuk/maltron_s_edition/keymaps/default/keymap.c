// Copyright 2022 Mehmet Can (@MindrustUK)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
  SW_LAY = SAFE_RANGE,
  SW_LALT,
  SW_LCTL,
  SW_LHSH
};

enum Layers {
  LAYER_BASE = 0,
  LAYER_NUM = 1,
  LAYER_GERMAN = 2,
  LAYER_MEDIA = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_maltron_8x16(
        //COL_0     COL_1    COL_2    COL_3    COL_4    COL_5   COL_6    COL_7    COL_8     COL_9    COL_10         COL_11   COL_12   COL_13    COL_14    COL_15
        KC_NO,      KC_PSCR, KC_F12,  KC_F11,  KC_F10,  KC_F9,  KC_F8,   KC_F7,   KC_F6,    KC_F5,   KC_F4,         KC_F3,   KC_F2,   KC_F1,    KC_ESC,   KC_LGUI, // ROW 0
        KC_NO,      KC_GRV,  KC_RBRC, KC_LBRC, KC_TAB,  KC_NO,  KC_NO,   SW_LAY,  KC_NO,    KC_NO,   KC_NO,         KC_NO,   KC_NUM,  KC_SCRL,  KC_NO,    KC_LOPT, // ROW 1
        KC_NO,      KC_0,    KC_9,    KC_8,    KC_7,    KC_6,   KC_ALGR, KC_NO,   KC_NO,    KC_NO,   KC_NO,         KC_MPLY, KC_VOLU, KC_VOLD,  KC_MUTE,  KC_TAB,  // ROW 2
        KC_NO, 	    KC_5,    KC_4,    KC_3,    KC_2,    KC_1,   KC_QUOT, KC_RCTL, SW_LCTL,  KC_NO,   KC_NO,         KC_HOME, KC_PGUP, KC_INS,   KC_PAUS,  KC_PEQL, // ROW 3
        KC_NUBS,    KC_Q,    KC_B,    KC_P,    KC_M,    KC_G,   KC_X,    SW_LALT, KC_BSPC,  KC_UP,   KC_LGUI,       KC_END,  KC_PGDN, KC_DEL,   KC_BSPC,  KC_PPLS, // ROW 4
        KC_UNDS,    KC_R,    KC_L,    KC_O,    KC_D,    KC_F,   KC_J,    KC_NO,   KC_RGHT,  KC_DOWN, KC_LEFT,       KC_PSLS, KC_P9,   KC_P8,    KC_P7,    KC_PENT, // ROW 5
        KC_CIRC,    KC_N,    KC_H,    KC_E,    KC_T,    KC_A,   KC_S,    KC_DOT,  KC_I,     KC_ENT,  KC_CAPS,       KC_PAST, KC_P6,   KC_P5,    KC_P4,    KC_PDOT, // ROW 6
        KC_SLSH,    KC_V,    KC_W,    KC_K,    KC_C,    KC_Y,   KC_Z,    KC_COMM, KC_SPC,   KC_U,    OSM(MOD_LSFT), KC_PMNS, KC_P3,   KC_P2,    KC_P1,    KC_P0    // ROW 7
    ),
    [LAYER_NUM] = LAYOUT_maltron_8x16(
        //COL_0 COL_1   COL_2   COL_3   COL_4   COL_5   COL_6   COL_7   COL_8     COL_9    COL_10   COL_11   COL_12   COL_13    COL_14    COL_15
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 0
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  SW_LAY, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 1
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 2
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 3
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 4
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 5
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 6
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO    // ROW 7
    ),
    [LAYER_GERMAN] = LAYOUT_maltron_8x16(
        //COL_0 COL_1   COL_2   COL_3   COL_4   COL_5   COL_6   COL_7   COL_8     COL_9    COL_10   COL_11   COL_12   COL_13    COL_14    COL_15
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 0
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  SW_LAY, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 1
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 2
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 3
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 4
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 5
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 6
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO    // ROW 7
    ),
  [LAYER_MEDIA] = LAYOUT_maltron_8x16(
        //COL_0 COL_1   COL_2   COL_3   COL_4   COL_5   COL_6   COL_7   COL_8     COL_9    COL_10   COL_11   COL_12   COL_13    COL_14    COL_15
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 0
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  SW_LAY, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 1
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 2
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 3
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 4
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 5
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   // ROW 6
		KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO    // ROW 7
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SW_LAY:
      if (record->event.pressed) { 
        uprintf("Layer Switch Pushed\n");

        if(IS_LAYER_ON(LAYER_BASE)){
          uprintf("Moving to Num\n");
          layer_move(LAYER_NUM);
        }

        else if(IS_LAYER_ON(LAYER_NUM)){
          uprintf("Moving to German\n");
          layer_move(LAYER_GERMAN);
        }

        else if(IS_LAYER_ON(LAYER_GERMAN)){
          uprintf("Moving to Media\n");
          layer_move(LAYER_MEDIA);
        }

        else if(IS_LAYER_ON(LAYER_MEDIA)){
          uprintf("Moving to Base\n");
          layer_move(LAYER_BASE);
        }
      }
      break;
    
    case SW_LALT:
      if (record->event.pressed) {
        static bool lalt_state = false;
        lalt_state = !lalt_state;
        uprintf("LH ALT Switch Pushed\n");
        if (lalt_state) {   // Hold LH ALT
          writePinLow(B5);
          register_code(KC_LALT);
        } else {    // Release LH ALT
          writePinHigh(B5);
          unregister_code(KC_LALT);
        }
      }
      break;

    case SW_LCTL:
      if (record->event.pressed) {
        static bool lctl_state = false;
        lctl_state = !lctl_state;
        uprintf("Left Hand CTRL Switch Pushed\n");
        // Clear one shot mod
        if (lctl_state) {   // Hold LH CTL
          writePinLow(B12);
          register_code(KC_LCTL);
        } else {    // Release LH CTL
          writePinHigh(B12);
          unregister_code(KC_LCTL);
        }
      }
      break;
  
    case SW_LHSH:
      if (record->event.pressed) {
        static bool lhsh_state = false;
        lhsh_state = !lhsh_state;
        uprintf("Left Hand Shift Switch Pushed\n");
        // Clear one shot mod
        if (lhsh_state) {   // Hold LH Shift
          writePinLow(B6);
          register_code(KC_LSFT);
        } else {    // Release LH Shift
          writePinHigh(B6);
          unregister_code(KC_LSFT);
        }
      }
      break;
  }
  
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif 

  return true;
};

// Runs whenever there is a layer state change.
// This is used to toggle the layer LED indicators.
uint32_t layer_state_set_user(uint32_t state) {

  // LEDs are active low
  writePinHigh(B15);
  writePinHigh(B4);

  uint8_t layer = biton32(state);
  switch (layer) {
    case 0:
      break;
    case 1:
      writePinLow(B15);
      break;
    case 2:
      writePinLow(B4);
      break;
    case 3:
      writePinLow(B15);
      writePinLow(B4);
      break;
  }

  return state;
};


bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        writePin(B13, !led_state.num_lock);
        writePin(B7, !led_state.caps_lock);
        writePin(B14, !led_state.scroll_lock);
    }
    return res;
}

// LED indicators used for one shot keys
void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    uprintf("Oneshot Shift active");
    writePinLow(B6);
  }
  if (!mods) {
    uprintf("Oneshot mods off");
    writePinHigh(B6);
  }
}
