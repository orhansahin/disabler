#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "inc/xinput.h"


void device_get()
{
	char buffer[32];
	snprintf(buffer, sizeof(buffer), "xinput > device_list.txt");
	system(buffer);
}

char device_find_id(FILE *fp)
{
	char line[256];
	char *device_id = NULL;

    while (fgets(line, sizeof(line), fp))
	{
		device_id = strstr(line, "G2Touch");
		if(device_id)
		{
			device_id = strstr(line, "id=");
			printf("%s", line);
			printf("%p\n", device_id);
			device_id += 3;
			printf("id: %c\n", *device_id);
			return *device_id;
		}

		if(isdigit(device_id))
		{
			perror(NULL);
		}
    }

	return 'Q';
}

int device_disable(char id)
{
	char *binary_path = "/usr/bin/xinput";
	char *arg1 = "disable";
	execl(binary_path, binary_path, arg1, &id, (char*)NULL);
	return 0;
}

/*************************
int charTo_int(char key)
{
	return (key - '0');
}
**************************/

