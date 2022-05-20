#include "invert.h"

void invert(char* text, int start, int end)
{
	int half_size = (end - start)/2;
	char buf;
	for(int counter=0;counter<half_size+1;counter++)
	{
		buf = text[start+counter];
		text[start+counter] = text[end-counter];
		text[end-counter] = buf;
	}
}
