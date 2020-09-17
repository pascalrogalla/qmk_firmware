#pragma once

#define TAPPING_TERM 190

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif  // RGBLIGHT_ENABLE

// ----------
#define C_LOCK_DEVICE LGUI(LCTL(KC_U))
#define C_RS_GRAVE RSFT_T(KC_GRAVE)
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))
#define BOTTOM_LEFT_RGB 15

#define HSV_OFF 0, 0, 0
#define rgblight_sethsv_noeeprom_off() rgblight_sethsv_noeeprom(HSV_OFF);

#define KC_FNDN LT(FUNCTION1, KC_DOWN)
#define KC_LCRT LCTL_T(KC_RIGHT)
#define KC_LALFT LALT_T(KC_LEFT)
#define KC_LSUP LSFT_T(KC_UP)

// ----------
