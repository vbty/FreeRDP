/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * FreeRDP Windows Server
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <winpr/tchar.h>
#include <winpr/windows.h>

#include "wf_interface.h"

#include "wfreerdp.h"

int main(int argc, char* argv[])
{
	int index;
	wfServer* server;

	server = wfreerdp_server_new();

	//handle args
	index = 1;
	//first the args that will cause the program to terminate
	if (strcmp("--list-screens", argv[index]) == 0)
	{
		printf("Detecting screens...\n");
		get_screen_info();
		return 0;
	}

	if (argc == 2)
		server->port = (DWORD) atoi(argv[1]);

	printf("Starting server\n");

	wfreerdp_server_start(server);

	WaitForSingleObject(server->thread, INFINITE);

	printf("Stopping server\n");

	wfreerdp_server_stop(server);
	wfreerdp_server_free(server);

	return 0;
}
