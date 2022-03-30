## JMillerDE's Keychron Q2 keymap (ANSI rev_0111)
The key mapping is based on my needs and preferances.
- The RGB is a tweaked version of the code created by mkillewald for the original Keychron Q1 75% Keyboard:
	- https://github.com/mkillewald/qmk_firmware/tree/mkillewald/keyboards/keychron/q1/rev_0100/keymaps/mkillewald


## Features:
- On macOS, Fn+E opens Mission Control and Fn+R opens Launchpad without needing to configure shortcuts in System Preferences
- RGB lighting turns off when the computer sleeps
- Caps Lock RGB indicator
    - the Caps Lock key will light when Caps Lock is enabled with the following options:
        - #define CAPS_LOCK_INDICATOR_COLOR [color] in config.h to set the backlight color used for the indicator when Caps Lock is enabled (default: RGB_PINK)
        - Fn+Rctl+I will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit keycaps/legends.            (default: off)
        - Fn+Rctl+O will toggle lighting all the alpha keys when Caps Lock is enabled.                                                      (default: off)
		- Fn+Rctl+P will toggle lighting on home home row when Caps Lock is enabled (caps, a, s, d, f, g, h, j, k, l, ;, ', enter).         (default: on)

- Dynamic Fn layer RGB indicator
    - When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
        - #define FN_LAYER_COLOR [color] in config.h to set a static color for defined keys                          (default: RGB_MAGENTA)
		- #define RGB_LAYER_COLOR [color] in config.h to set a static color for defined keys                         (default: RGB_PURPLE)
		- #define NUMPAD_LAYER_COLOR [color] in config.h to set a static color for defined keys                      (default: RGB_GOLD)
        - Fn+Rctl+H will toggle lighting the defined Fn layer keys with the static color set with FN_LAYER_COLOR	 (default: off)
		- Fn+Rctl+J will toggle lighting the defined Fn layer keys with the static color set with RGB_LAYER_COLOR    (default: off)
		- Fn+Rctl+K will toggle lighting the defined Fn layer keys with the static color set with NUMPAD_LAYER_COLOR (default: off)
		- Fn+Rctl+; will toggle turning on or off the KC_TRNS defined keys in the keymap                             (default: on)
		- Fn+Rctl+' will toggle turning on or off the KC_NO defined keys in the keymap                               (default: off)
		
- I have VIA disabled for the Keychron Q2, VIA doesn't seem to recognize the keyboard yet. However, all custom keycodes can be moved to different keys in VIA if you enable it by using the ANY key with the following keycodes:
	- USER00 (default: Fn+E) macOS Mission Control
	- USER01 (default: Fn+R) macOS Launchpad
    - USER02 (default: Fn+Rctl+Y) Caps Lock light tab toggle
	- USER03 (default: Fn+Rctl+U) Caps Lock light alphas toggle
    - USER04 (default: Fn+Rctl+I) Caps Lock light home row toggle
    - USER05 (default: Fn+Rctl+J) FN Layer color toggle
    - USER06 (default: Fn+Rctl+K) RGB Layer color toggle
	- USER07 (default: Fn+Rctl+L) Numpad Layer color toggle
	- USER08 (default: Fn+Rctl+;) Transparent keys color toggle
	- USER09 (default: Fn+Rctl+') Unmapped keys color toggle
	- USER10 KC_TASK LGUI(KC_TAB)
    - USER11 KC_WAVE S(KC_GRV)
	- USER12 KC_FLXP LGUI(KC_E)

RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

Please make sure to save any customizations you have made in VIA to a .json file before flashing the firmware. Sometimes it has been necessary to re-apply those changes in VIA after flashing the firmware. If that is the case, you will most likely need to manually add the USER00 through USER05 custom keycodes after loading your customizations from the saved .json file. Then re-save a new .json file which will have your previous customizations and the custom keycodes for future use as needed.

## Keymapping:
Note: I used "LAYOUT_ansi_67" in my keymap, it will only modify the knob press (Knob).
- However, if you want you can use LAYOUT_ansi_ALL instead and supply knob turning left and knob turning right binds.

All Layers
- Turn Knob Left (default: volume decrease)
- Turn Knob Right (default: volume increase)

Base layer rebinds from stock (Both Mac and Windows):
- Delete (default: Home)
- Home	 (default: End)

Layer "_ML1" (Fn Key) (Toggle Switch set to MAC :: "MAC_BASE" [Layer 0])
- Fn+Esc  (default: `)
- Fn+1    (default: F1)
- Fn+2    (default: F2)
- Fn+3    (default: F3)
- Fn+4    (default: F4)
- Fn+5    (default: F5)
- Fn+6    (default: F6)
- Fn+7    (default: F7)
- Fn+8    (default: F8)
- Fn+9    (default: F9)
- Fn+0    (default: F10)
- Fn+-    (default: F11)
- Fn+=    (default: F12)
- Fn+Back (default: Delete)
- Fn+Q    (default: Brightness Increase)
- Fn+W    (default: Brightness Decrease)
- Fn+E    (default: Mission Control)
- Fn+R    (default: Launchpad)
- Fn+T    (default: )
- Fn+Caps (default: Lock Caps)
- Fn+Knob (default: Sleep)
- Fn+Home (default: Page Up)   				[stock delete key]
- Fn+End  (default: Page Down) 				[stock home key]
- Fn+Rctl (default: RGB Layer)

Layer "_WL1" (Fn Key) (Toggle Switch set to WIN :: "WIN_BASE" [Layer 1])
- Fn+Esc  (default: `)
- Fn+1    (default: F1)
- Fn+2    (default: F2)
- Fn+3    (default: F3)
- Fn+4    (default: F4)
- Fn+5    (default: F5)
- Fn+6    (default: F6)
- Fn+7    (default: F7)
- Fn+8    (default: F8)
- Fn+9    (default: F9)
- Fn+0    (default: F10)
- Fn+-    (default: F11)
- Fn+=    (default: F12)
- Fn+Back (default: Delete)
- Fn+Tab  (default: Browser Favorites)
- Fn+Q    (default: Browser Home)
- Fn+E    (default: Browser Back)
- Fn+R    (default: Browser Forward)
- Fn+T    (default: Browser Refreash)
- Fn+Y    (default: Browser Search)
- Fn+Caps (default: Lock Caps)
- Fn+Knob (default: Sleep)
- Fn+Home (default: Page Up)   				[stock delete key]
- Fn+End  (default: Page Down) 				[stock home key]
- Fn+Rctl (default: RGB Layer)

Layer "_RGB" (Fn+Rctl Keys :: Accessed from both the MAC_BASE and WIN_BASE layers)
- Fn+Rctl+Esc (default: ~)
- Fn+Rctl+1    (default: F13)
- Fn+Rctl+2    (default: F14)
- Fn+Rctl+3    (default: F15)
- Fn+Rctl+4    (default: F16)
- Fn+Rctl+5    (default: F17)
- Fn+Rctl+6    (default: F18)
- Fn+Rctl+7    (default: F19)
- Fn+Rctl+8    (default: F20)
- Fn+Rctl+9    (default: F21)
- Fn+Rctl+0    (default: F22)
- Fn+Rctl+-    (default: F23)
- Fn+Rctl+=    (default: F24)
- Fn+Rctl+Tab  (default: RGB Toggle)
- Fn+Rctl+Q    (default: RGB Mode Forward)
- Fn+Rctl+E    (default: RGB Hue Reverse)
- Fn+Rctl+R    (default: RGB Saturation Increase)
- Fn+Rctl+T    (default: RGB Brightness Increase)
- Fn+Rctl+Y    (default: RGB Effect Speed Increase)
- Fn+Rctl+I    (default: Toggle Caps Lock Tab Indicator)
- Fn+Rctl+O    (default: Toggle Caps Lock Alphas Indicator)
- Fn+Rctl+P    (default: Toggle Caps Lock Home Row Indicator)
- Fn+Rctl+A    (default: RGB Mode Decrease)
- Fn+Rctl+S    (default: RGB Hue Decrease)
- Fn+Rctl+D    (default: RGB Saturation Decrease)
- Fn+Rctl+F    (default: RGB Brightness Decrease)
- Fn+Rctl+H    (default: RGB Effect Speed Decrease)
- Fn+Rctl+J    (default: Toggle the FN Layer static color)
- Fn+Rctl+K    (default: Toggle the RGB layer static color)
- Fn+Rctl+L    (default: Toggle the Numpad layer static color)
- Fn+Rctl+;    (default: Toggle the Transparent key lighting on or off)
- Fn+Rctl+'    (default: Toggle the Unmapped key lighting on or off)
- Fn+Rctl+Z    (default: Change RGB Mode to 'Plain')						[Default Mode with rgb_matrix_sethsv(80, 207, 111)]
- Fn+Rctl+X    (default: Change RGB Mode to 'Breathe')
- Fn+Rctl+C    (default: Change RGB Mode to 'Rainbow')
- Fn+Rctl+V    (default: Change RGB Mode to 'Swirl')
- Fn+Rctl+B    (default: Change RGB Mode to 'Snake')
- Fn+Rctl+N    (default: Change RGB Mode to 'Knight Rider')
- Fn+Rctl+M    (default: Change RGB Mode to 'Christmas')
- Fn+Rctl+,    (default: Change RGB Mode to 'Gradient')
- Fn+Rctl+.    (default: Change RGB Mode to 'Test')
- Fn+Rctl+Knob (default: Power)
- Fn+Rctl+Home (default: Insert)       										[stock delete key]
- Fn+Rctl+End  (default: Print Screen) 										[stock home key]
- Fn+Rctl+Ralt (default: Numpad Layer)

Layer "_RGB" (Fn+Rctl+Ralt Keys :: Accessed from the RGB layer)
- Fn+Rctl+Ralt+Esc      (default: Left Parentheses)
- Fn+Rctl+Ralt+1        (default: Right Parentheses)
- Fn+Rctl+Ralt+2		(default: Caret) 								[X raised to the power of Y]
- Fn+Rctl+Ralt+3        (default: Numpad Multiply)
- Fn+Rctl+Ralt+4        (default: Numpad Divide)
- Fn+Rctl+Ralt+Tab      (default: Numppad Minus)
- Fn+Rctl+Ralt+Q        (default: Numpad 6)
- Fn+Rctl+Ralt+W        (default: Numpad 7)
- Fn+Rctl+Ralt+E        (default: Numpad 8)
- Fn+Rctl+Ralt+R        (default: Numpad 9)
- Fn+Rctl+Ralt+Caps     (default: Numpad Minus)
- Fn+Rctl+Ralt+A        (default: Numpad 2)
- Fn+Rctl+Ralt+S        (default: Numpad 3)
- Fn+Rctl+Ralt+D        (default: Numpad 4)
- Fn+Rctl+Ralt+F        (default: Numpad 5)
- Fn+Rctl+Ralt+RShift   (default: Numpad Equal)
- Fn+Rctl+Ralt+Z        (default: Numpad 0)
- Fn+Rctl+Ralt+X        (default: Numpad 1)
- Fn+Rctl+Ralt+C        (default: Numpad Dot)							[Decemial Point]
- Fn+Rctl+Ralt+V        (default: Numpad Comma)
- Fn+Rctl+Ralt+LCtl     (default: Less Than)
- Fn+Rctl+Ralt+LGUI     (default: Greater Than)
- Fn+Rctl+Ralt+LAlt     (default: Numpad Enter)
- Fn+Rctl+Ralt+Knob     (default: Calculator)
- Fn+Rctl+Ralt+Home     (default: Num Lock)       						[stock delete key]
- Fn+Rctl+Ralt+End      (default: Scroll Lock) 							[stock home key]


#### USE AT YOUR OWN RISK

## Changelog:

v1.0.0  March 23, 2022
- Initial release adding a home row caps lock indication
- The keymap is based on my preferances and my functional needs

v1.0.1  March 29, 2022
- Added in the unmapped key functionality and keymapping

v1.0.2  March 30, 2022
- Changed the keymapping to use the tilda (~) character with hitting the Fn+Rctl+Esc key combination
- Added KC_TRNS to the spacebar on the Fn+Rctl (_RGB) layer.