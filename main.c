#include "inc/xinput.h"

int main()
{
	char id;
	
	device_get();
	FILE *fp = fopen("device_list.txt", "r");

	if(!fp)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	id = device_find_id(fp);
	device_disable(id);
    fclose(fp);

	return 0;
}

/************
versions
xinput : 1.6.2
XI     : 2.3
*************/