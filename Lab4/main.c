#include <stdio.h>
#include <string.h>
#include "invert.h"

int main(int args, char* argv[])
{
	const int max_size = 100000;
    	char text[max_size+1];
	int str_count;
	int text_size;
	int start=0;

    	scanf("%[^\t]s", text);
	
	text_size = strlen(text);
	
	invert(text, 1, 0);

	for(int counter=0;counter<text_size;counter++)
	{
		if(text[counter] == '\n')
		{
			invert(text, start, counter-1);
			start = counter+1;

		}
	}	
	
	FILE *file = fopen("result.txt", "w");

	int results = fputs(text, file);
	if (results == EOF) {
    		printf("fputs error");
	}
	fclose(file);
	
    	return 0;
}


