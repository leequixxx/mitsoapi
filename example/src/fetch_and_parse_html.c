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
#include <mitsoapi/core/http/fetch/fetch_and_parse_html.h>
#include <gumbo.h>
#include <stdio.h>

#include "../include/fetch_and_parse_html.h"

void print_node(GumboNode* node, int level)
{
	if (node->type != GUMBO_NODE_ELEMENT)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		printf("\t");
	}
	printf("%s", gumbo_normalized_tagname(node->v.element.tag));
	if (node->v.element.tag == GUMBO_TAG_OPTION)
	{
		if (node->v.element.children.length != 1)
		{
			printf(" > <empty>\n");
		}
		else
		{
			GumboNode* text = node->v.element.children.data[0];
			GumboAttribute* attribute_value = gumbo_get_attribute(&node->v.element.attributes, "value");
			printf(" > (value=\"%s\") %s\n", attribute_value->value, text->v.text.text);
		}
	}
	else
	{
		printf("\n");
	}

	for (int i = 0; i < node->v.element.children.length; i++)
	{
		print_node(node->v.element.children.data[i], level + 1);
	}
}

void mitsoapi_example_fetch_and_parse_html()
{
	MITSOAPI* m = mitsoapi_init();

	GumboOutput* output = mitsoapi_fetch_and_parse_html_with_base_url(m, MITSOAPI_EXAMPLE_FETCH_AND_PARSE_HTML_PATH);

	print_node(output->root, 0);

	mitsoapi_destroy(m);
}
