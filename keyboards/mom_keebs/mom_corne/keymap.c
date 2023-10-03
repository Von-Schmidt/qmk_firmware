#include QMK_KEYBOARD_H

// typedef union {
//     uint32_t raw;
//     struct {
//         uint8_t base_hue :8;
//         uint8_t base_sat :8;
//         uint8_t base_val :8;
//     };
//     
// } user_config_t;

// user_config_t user_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


#define ESC_CTL LCTL_T(KC_ESC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAV)
#define CZECH MO(_CZECH)
#define ALT_SPC LALT_T(KC_SPC)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _NAV,
    _CZECH
};

enum underglow_functions {
    RGBPLUS = SAFE_RANGE,
    RGBMINU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTZ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Z,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,KC_SFTENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,        NAV,   RAISE,   CZECH
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL, RGB_TOG, RGB_HUI, RGB_SAI, RGBPLUS, RGBMINU,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_ASTR, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, RGB_MOD, RGB_HUD, RGB_SAD, RGBMINU,   RESET,                      KC_MINS,    KC_1,    KC_2,    KC_3,  KC_EQL,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,        NAV,   RAISE,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_BSLS, KC_PIPE,KC_KP_PLUS,KC_CIRC,_______,                      _______, _______, _______, _______, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_ASTR,                      KC_LPRN, KC_RPRN,  KC_EQL,  KC_DLR, _______, KC_EXLM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_UNDS, KC_HASH, KC_AMPR,   KC_AT, KC_PERC,                      _______, _______, KC_QUES, _______, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,       NAV, _______,  CZECH
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      _______, KC_PGUP, KC_HOME,  KC_END, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                     _______,KC_PGDOWN, _______, _______, _______, KC_SFTENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, ALT_SPC,    _______,   RAISE,   CZECH
                                      //`--------------------------'  `--------------------------'
  ),

    [_CZECH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD,RALT(KC_2),RALT(KC_3),RALT(KC_4),RALT(KC_5),RALT(KC_6),         RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),RALT(KC_LBRC),KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, RALT(KC_SCLN), RALT(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_SFTENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,        NAV,   RAISE, _______
                                      //`--------------------------'  `--------------------------'
  )

};

// void keyboard_post_init_user(void) {
//     user_config.raw = eeconfig_read_user();
//     // if(user_config.layer_rgb) {
//         rgblight_enable_noeeprom();
//         rgblight_mode_noeeprom(1);
//         rgblight_sethsv_noeeprom(user_config.base_hue,user_config.base_sat,user_config.base_val);
//     // } 
// }
uint8_t val_personal = 100;

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBPLUS:
            if(record->event.pressed) {
                val_personal = val_personal + 10;
            }
            break;
        case RGBMINU:
            if(record->event.pressed) {
                val_personal = val_personal - 10;

            }
            break;
    }
    return true;
}


// This changes backlight color depending on which layer is currently in use.
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _RAISE:
                rgb_matrix_sethsv_noeeprom(30, 200, val_personal);
                break;
            case _LOWER:
                rgb_matrix_sethsv_noeeprom(130, 30, val_personal);
                break;
            case _NAV:
                rgb_matrix_sethsv_noeeprom(5, 230, val_personal);
                break;
            case _CZECH:
                rgb_matrix_sethsv_noeeprom(150, 200, val_personal);
                break;
            default:
                rgb_matrix_sethsv(0, 0, val_personal); // base is white
                break;
        }
//    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_left())
    return OLED_ROTATION_180;  // flips the display 180 to see it from my side
  return rotation;
}

const char *read_logo(void);
void oled_task_user(void){
    switch (biton32(layer_state)){
        case _QWERTZ:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _CZECH:
            oled_write_ln_P(PSTR("CZECH"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
  //now print logo
  oled_write(read_logo(), false);
  
}
#endif
