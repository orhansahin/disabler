#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = fopen("test.txt", "r");
	printf("sa");
	if(!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;	
	}

	int c; //note: int, not char, required to handle EOF
	while((c = fgetc(fp)) != EOF) {
		putchar(c);
	}

	if(ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");

	fclose(fp);

	return EXIT_SUCCESS;
}
