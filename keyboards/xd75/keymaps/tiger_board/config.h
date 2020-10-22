/* Copyright 2017 Benjamin Kesselring
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

// place overrides here

#undef DESCRIPTION
#define DESCRIPTION     XD75Am 15x5 ortholinear keyboard

#undef BACKLIGHT_ON_STATE
#define BACKLIGHT_ON_STATE 1
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 15

#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6

#define RGBLIGHT_SPLIT
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 15 // units to step when in/decreasing hue
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 15 // units to step when in/decresing saturation
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 15 // units to step when in/decreasing value (brightness)