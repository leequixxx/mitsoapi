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
#include <mitsoapi/core/http/fetch/fetch_and_parse_html.h>
#include <mitsoapi/error.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "../../../mitsoapi_structure.h"

void mitsoapi_last_html_append_zero(MITSOAPI* m);

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata);

GumboOutput* mitsoapi_fetch_and_parse_html(MITSOAPI* m, const char* url)
{
	CURLcode res;
	curl_easy_reset(m->curl);
	curl_easy_setopt (m->curl, CURLOPT_URL, url);
	curl_easy_setopt (m->curl, CURLOPT_SSL_VERIFYHOST, false);
	curl_easy_setopt (m->curl, CURLOPT_SSL_VERIFYPEER, false);
	curl_easy_setopt (m->curl, CURLOPT_SSL_VERIFYSTATUS, false);
	curl_easy_setopt (m->curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt (m->curl, CURLOPT_WRITEDATA, m);
	mitsoapi_reset_mitsoapi_last_html(m);

	res = curl_easy_perform(m->curl);
	if (res != CURLE_OK)
	{
		printf(curl_easy_strerror(res));
		mitsoapi_last_error = MITSOAPI_ERROR_CURL_PERFORM;
		return NULL;
	}
	mitsoapi_last_html_append_zero(m);

	GumboOutput* output = gumbo_parse(m->last_html->html_text);

	mitsoapi_reset_mitsoapi_last_html(m);

	mitsoapi_last_error = MITSOAPI_ERROR_NOTHING;

	return output;
}

GumboOutput* mitsoapi_fetch_and_parse_html_with_base_url(MITSOAPI* m, const char* path)
{
	char url[strlen(MITSOAPI_BASE_URL) + strlen(path) + 1];
	strcpy(url, MITSOAPI_BASE_URL);
	strcat(url, path);

	return mitsoapi_fetch_and_parse_html(m, url);
}

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata)
{
	MITSOAPI* m = userdata;
	size_t realsize = size * nmemb;

	if (!m->last_html)
	{
		m->last_html = malloc(sizeof(struct mitsoapi_html_str));
		m->last_html->html_text = malloc(realsize);
		m->last_html->size = realsize;

		memcpy(m->last_html->html_text, ptr, realsize);
	}
	else
	{
		m->last_html->html_text = realloc(m->last_html->html_text, m->last_html->size + realsize);
		memcpy(m->last_html->html_text + m->last_html->size, ptr, realsize);
		m->last_html->size += realsize;
	}

	return size * nmemb;
}

void mitsoapi_last_html_append_zero(MITSOAPI* m)
{
	if (m->last_html)
	{
		m->last_html->html_text = realloc(m->last_html->html_text, m->last_html->size + 1);
		m->last_html->html_text[m->last_html->size] = '\0';
		m->last_html->size++;
	}
}
