#ifndef HEADER_MITSOAPI_FETCH_AND_PARSE_HTML_H
#define HEADER_MITSOAPI_FETCH_AND_PARSE_HTML_H
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
#include <gumbo.h>

#include <mitsoapi/mitsoapi.h>

/**
 * Fetch page by concrete url and parse it
 * @param m mitsoapi descriptor
 * @param url of page
 * @return parsed structure
 */
GumboOutput* mitsoapi_fetch_and_parse_html(MITSOAPI* m, const char* url);

/**
 * Fetch page by path of base url and parse it
 * @param m mitsoapi descriptor
 * @param path to page
 * @return parsed structure
 */
GumboOutput* mitsoapi_fetch_and_parse_html_with_base_url(MITSOAPI* m, const char* path);

#endif /* HEADER_MITSOAPI_FETCH_AND_PARSE_HTML_H */
