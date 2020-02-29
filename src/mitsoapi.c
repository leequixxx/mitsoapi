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
#include <mitsoapi/mitsoapi.h>
#include <mitsoapi/error.h>
#include <curl/curl.h>
#include <stdlib.h>

#include "mitsoapi_structure.h"

MITSOAPI* mitsoapi_init()
{
	return mitsoapi_init_with_base_url(MITSOAPI_BASE_URL);
}

MITSOAPI* mitsoapi_init_with_base_url(const char* url)
{
	curl_global_init(CURL_GLOBAL_ALL);

	MITSOAPI* m = malloc(sizeof(struct mitsoapi));
	m->curl = curl_easy_init();
	m->base_url = url;
	m->last_html = malloc(sizeof(struct mitsoapi_html_str));

	if (!m->curl)
	{
		mitsoapi_last_error = MITSOAPI_ERROR_CURL_INIT;

		return NULL;
	}

	mitsoapi_last_error = MITSOAPI_ERROR_NOTHING;

	return m;
}

void mitsoapi_destroy(MITSOAPI* m)
{
	curl_easy_cleanup(m->curl);
	mitsoapi_reset_mitsoapi_last_html(m);
	free(m);

	curl_global_cleanup();
	mitsoapi_last_error = MITSOAPI_ERROR_NOTHING;
}
