## Phoneutria's Keychron Q2 keymap (ANSI rev_0111)
The key mapping is based on my needs and preferances.
- The RGB is a tweaked version of the code created by mkillewald for the orgicional Keychron Q1:
	- https://github.com/mkillewald/qmk_firmware/tree/mkillewald/keyboards/keychron/q1/rev_0100/keymaps/mkillewald


## Features:
- On macOS, F3 opens Mission Control and F4 opens Launchpad without needing to configure shortcuts in System Preferences
- RGB lighting turns off when the computer sleeps
- Caps Lock RGB indicator
    - the Caps Lock key will light when Caps Lock is enabled with the following options:
        - #define CAPS_LOCK_INDICATOR_COLOR [color] in config.h to set the backlight color used for the indicator when Caps Lock is enabled (default: RGB_PINK)
        - Fn+Y will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit keycaps/legends. (default: off)
        - Fn+U will toggle lighting all the alpha keys when Caps Lock is enabled. (default: off)
		- Fn+I will toggle lighting on home home row (caps, a, s, d, f, g, h, j, k, l, ;, ', enter). (default: off)

- Dynamic Fn layer RGB indicator
    - When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
        - #define FN_LAYER_COLOR [color] in config.h to set a static color for defined keys (default: RGB_MAGENTA)
		- #define RGB_LAYER_COLOR [color] in config.h to set a static color for defined keys (default: RGB_PURPLE)
		- #define NUMPAD_LAYER_COLOR [color] in config.h to set a static color for defined keys (default: RGB_GOLD)
        - Fn+H will toggle lighting the defined Fn layer keys with the static color set with FN_LAYER_COLOR	(default: off)
		- Fn+J will toggle lighting the defined Fn layer keys with the static color set with RGB_LAYER_COLOR (default: off)
		- Fn+K will toggle lighting the defined Fn layer keys with the static color set with NUMPAD_LAYER_COLOR	(default: off)
		- Fn+; will toggle turning on or off the KC_TRNS defined keys in the keymap (default: off)
		- Fn+' will toggle turning on or off the KC_NO defined keys in the keymap (default: off)
		
- All custom keycodes can be moved to different keys in VIA by using the ANY key with the following keycodes:
	- USER00 (default: Fn+Rctl+4) macOS Mission Control
	- USER01 (default: Fn+Rctl+3) macOS Launchpad
    - USER02 (default: Fn+Y) Caps Lock light tab toggle
	- USER03 (default: Fn+U) Caps Lock light alphas toggle
    - USER04 (default: Fn+I) Caps Lock light home row toggle
    - USER05 (default: Fn+J) FN Layer color toggle
    - USER06 (default: Fn+K) RGB Layer color toggle
	- USER07 (default: Fn+L) Numpad Layer color toggle
	- USER08 (default: Fn+;) Transparent keys color toggle
	- USER09 (default: Fn+') Unmapped keys color toggle
	- USER10 KC_TASK LGUI(KC_TAB)
    - USER11 KC_WAVE S(KC_GRV)
	- USER12 KC_FLXP LGUI(KC_E)

RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

Please make sure to save any customizations you have made in VIA to a .json file before flashing the firmware. Sometimes it has been necessary to re-apply those changes in VIA after flashing the firmware. If that is the case, you will most likely need to manually add the USER00 through USER05 custom keycodes after loading your customizations from the saved .json file. Then re-save a new .json file which will have your previous customizations and the custom keycodes for future use as needed.
    
#### USE AT YOUR OWN RISK

## Changelog:

v1.0.0  March 23, 2022
- Initial release adding a home row caps lock indication
- The keymap is based on my preferances and my functional needs

v1.0.1  March 29, 2022
- Added in the unmapped key functionality and keymapping