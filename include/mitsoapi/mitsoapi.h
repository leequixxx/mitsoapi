#ifndef HEADER_MITSOAPI_H
#define HEADER_MITSOAPI_H
/**************************************************************************************************
 *
 *                  _____ ______   ___  _________  ________  ________  ________  ________  ___
 * Project         |\   _ \  _   \|\  \|\___   ___\\   ____\|\   __  \|\   __  \|\   __  \|\  \
 *                 \ \  \\\__\ \  \ \  \|___ \  \_\ \  \___|\ \  \|\  \ \  \|\  \ \  \|\  \ \  \
 *                  \ \  \\|__| \  \ \  \   \ \  \ \ \_____  \ \  \\\  \ \   __  \ \   ____\ \  \
 *                   \ \  \    \ \  \ \  \   \ \  \ \|____|\  \ \  \\\  \ \  \ \  \ \  \___|\ \  \
 *                    \ \__\    \ \__\ \__\   \ \__\  ____\_\  \ \_______\ \__\ \__\ \__\    \ \__\
 *                     \|__|     \|__|\|__|    \|__| |\_________\|_______|\|__|\|__|\|__|     \|__|
 *                                                   \|_________|
 *
 * Copyleft (Ɔ) 2020  Misha Vorobeychikov <mail@leequixxx.space>
 *
 * Mitsoapi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mitsoapi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mitsoapi.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************************************/

#define MITSOAPI_BASE_URL "https://mitso.by"

/**
 * Descriptor of mitsoapi
 */
typedef struct mitsoapi MITSOAPI;

/**
 * Create descriptor of mitsoapi with default base url
 * @return descriptor of mitsoapi
 */
MITSOAPI* mitsoapi_init();

/**
 * Create descriptor of mitsoapi with given base url
 * @param url base
 * @return instance of mitsoapi
 */
MITSOAPI* mitsoapi_init_with_base_url(const char* url);

/**
 * Free allocated memory by mitsoapi descriptor
 * @param m mitsoapi descriptor
 */
void mitsoapi_destroy(MITSOAPI* m);

#endif //HEADER_MITSOAPI_H
