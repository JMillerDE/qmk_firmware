/* Copyright 2022 @ Firehawk84 (https://github.com/Firehawk84/qmk_firmware)
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

enum layers{
    MAC_BASE,
    WIN_BASE,
    _ML1,
    _WL1,
    _RGB,
	_NP
};

bool get_caps_lock_light_tab(void);
bool get_caps_lock_light_alphas(void);
bool get_caps_lock_light_home_row(void);
bool get_fn_layer_enable(void);
bool get_rgb_layer_enable(void);
bool get_numpad_layer_enable(void);
bool get_transparent_keys_off(void);
bool get_unmapped_keys_off(void);