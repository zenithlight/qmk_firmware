#include QMK_KEYBOARD_H

enum custom_keycodes {
    GUIL_L = SAFE_RANGE,
    GUIL_R,
    A_GRAVE,
    E_GRAVE,
    E_ACCNT,
};



enum layers {
    _BASE,
    _EXTEND,
    _CIRCUMFLEX,
    _LMODS,
    _RMODS,
};

#define EXTD OSL(_EXTEND)
#define CIRC OSL(_CIRCUMFLEX)
#define LMODS MO(_LMODS)
#define RMODS MO(_RMODS)

#define ACCENT_CIRCUMFLEX 0x0302

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   #  |   «  |   »  |   "  |   -  |   +  |                    |   *  |   /  |   =  |   (  |   )  |  $   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   @  |   À  |   J  |   O  |   É  |   B  |                    |   F  |   D  |   L  |   '  |   Q  |  X   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   I  |   E  |  [U] |   ,  |-------.    ,-------|   P  |  [T] |   S  |   R  |   N  |  ^   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  TAB |   K  |   Y  |   È  |   .  |   W  |-------|    |-------|   G  |   C  |   M  |   H  |   V  |  Z   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | EXTD | MODS | LSft | /Space  /       \Enter \  |BackSP| MODS | EXTD |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
     */

    [_BASE] = LAYOUT(
        KC_HASH, GUIL_L , GUIL_R , KC_DQUO, KC_MINS, KC_PLUS,                   KC_ASTR, KC_SLSH, KC_EQL , KC_LPRN, KC_RPRN, KC_DLR ,
        KC_AT  , A_GRAVE, KC_J   , KC_O   , E_ACCNT, KC_B   ,                   KC_F   , KC_D   , KC_L   , KC_QUOT, KC_Q   , KC_X   ,
        KC_ESC , KC_A   , KC_I   , KC_E   , KC_U   , KC_COMM,                   KC_P   , KC_T   , KC_S   , KC_R   , KC_N   , CIRC   ,
        KC_TAB , KC_K   , KC_Y   , E_GRAVE, KC_DOT , KC_W   , KC_NO  , KC_NO  , KC_G   , KC_C   , KC_M   , KC_H   , KC_V   , KC_Z   ,
                          EXTD   , LMODS  , KC_LSFT, KC_SPC ,                   KC_ENT , KC_BSPC, RMODS  , EXTD
    ),

    /* EXTEND
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |   \  |      |   [  |   ]  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   <  |   >  |   Œ  |      |      |                    |      |   {  |   }  |      |      |   |  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Æ  |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
     */

    [_EXTEND] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* CIRCUMFLEX
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   %  |   {  |   }  |   [  |   ]  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   _  |-------.    ,-------|   |  |   &  |      |   \  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   =  |      |   <  |   >  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
     */

    [_CIRCUMFLEX] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PERC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS,                   KC_PIPE, KC_AMPR, KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EQL , KC_TRNS, KC_LT  , KC_GT  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* LMODS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   #  |   «  |   »  |   "  |   -  |   +  |                    |   *  |   /  |   =  |   (  |   )  |  $   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   @  |   À  |   J  |   O  |   É  |   B  |                    |   %  |   {  |   }  |   [  |   ]  |  X   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   I  |   E  |   U  |   ,  |-------.    ,-------|   |  |   &  |   S  |   \  |   Ñ  |  ◌̈   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  TAB |   Z  |   Y  |   È  |   .  |   K  |-------|    |-------|   G  |   C  |   M  |   H  |   V  |  W   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | MODS | LSft | /Space  /       \Enter \  |BackSP| MODS |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
     */

    [_LMODS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* RMODS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   #  |   «  |   »  |   "  |   -  |   +  |                    |   *  |   /  |   =  |   (  |   )  |  $   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   @  |   À  |   J  |   O  |   É  |   B  |                    |   %  |   {  |   }  |   [  |   ]  |  X   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   A  |   I  |   E  |   U  |   ,  |-------.    ,-------|   |  |   &  |   S  |   \  |   Ñ  |  ◌̈   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  TAB |   Z  |   Y  |   È  |   .  |   K  |-------|    |-------|   G  |   C  |   M  |   H  |   V  |  W   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | MODS | LSft | /Space  /       \Enter \  |BackSP| MODS |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
     */

    [_RMODS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_NO  , KC_NO  , KC_LSFT, KC_SPC ,                   KC_ENT , KC_BSPC, KC_NO  , KC_NO
    ),
};

bool is_layer_on(uint8_t layer) {
    return (layer_state & (1UL << layer)) > 0;
}

void send_accented_char(uint32_t base_char, uint32_t accent) {
    register_unicode(base_char);
    register_unicode(accent);
    register_unicode(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    bool shift_pressed = mod_state & MOD_MASK_SHIFT;

    if (is_layer_on(_CIRCUMFLEX)) {
        switch(keycode) {
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    uint32_t base_char = keycode - KC_A + (shift_pressed ? 'A' : 'a');
                    send_accented_char(base_char, ACCENT_CIRCUMFLEX);
                    return false;
                }
        }
    }

    switch (keycode) {
        case GUIL_L:
            if (record->event.pressed) {
                send_unicode_string("«");
            }
            return false;
        case GUIL_R:
            if (record->event.pressed) {
                send_unicode_string("»");
            }
            return false;
        case E_ACCNT:
            if (record->event.pressed) {
                if (shift_pressed) {
                    send_unicode_string("É");
                } else {
                    send_unicode_string("é");
                }
            }
            return false;
        case E_GRAVE:
            if (record->event.pressed) {
                if (shift_pressed) {
                    send_unicode_string("È");
                } else {
                    send_unicode_string("è");
                }
            }
            return false;
        case A_GRAVE:
            if (record->event.pressed) {
                if (shift_pressed) {
                    send_unicode_string("À");
                } else {
                    send_unicode_string("à");
                }
            }
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
    rgb_matrix_sethsv(0, 128, 128);
    rgb_matrix_set_color_all(0, 0, 255);
};
