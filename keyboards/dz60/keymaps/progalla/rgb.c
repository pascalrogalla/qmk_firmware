#include "rgb.h"
#ifdef RGBLIGHT_ENABLE

void matrix_init_user(void) {
    enabled = rgblight_config.enable;
    mode    = rgblight_config.mode;
    hue     = rgblight_config.hue;
    sat     = rgblight_config.sat;
    val     = rgblight_config.val;
};

bool caps_toggle = false;
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK) && !caps_toggle) {
        enabled = rgblight_config.enable;
        mode    = rgblight_get_mode();
        hue     = rgblight_get_hue();
        sat     = rgblight_get_sat();
        val     = rgblight_get_val();

        if (enabled) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_red_at(BOTTOM_LEFT_RGB);
        } else {
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom_off();
            rgblight_sethsv_red_at(BOTTOM_LEFT_RGB);
        }
        caps_toggle = true;
    } else if (caps_toggle) {
        if (enabled) {
            rgblight_mode_noeeprom(mode);
            rgblight_sethsv_noeeprom(hue, sat, val);
        } else {
            rgblight_mode_noeeprom(mode);
            rgblight_sethsv_noeeprom(hue, sat, val);
            rgblight_disable_noeeprom();
        }

        caps_toggle = false;
    }
};
#endif
