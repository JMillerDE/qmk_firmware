/* Copyright 2022 @ Jeremy MIller(https://github.com/jmillerde/qmk_firmware)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGB_MATRIX_ENABLE
#	define RGB_MATRIX_STARTUP_MODE 1
#	define RGB_DISABLE_WHEN_USB_SUSPENDED
#	define CAPS_LOCK_INDICATOR_COLOR RGB_CORAL
#	define FN_LAYER_COLOR RGB_BLUE
#	define RGB_LAYER_COLOR RGB_PURPLE
#	define NUMPAD_LAYER_COLOR RGB_GOLD
#endif