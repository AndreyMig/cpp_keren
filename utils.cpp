#include "utils.h"

void copyArrays(const bool* src, bool* dst, int size)
{
	for(int i = 0; i < size; i++)
		dst[i] = src[i];
}

int findPointerInArray(const void* lookFor, void** lookIn, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(lookIn[i] == lookFor)
			return i;
	}
	return -1;
}

void closeGaps(int start, void** arr ,int& originalSize)
{
	for(int i = start+1; i < originalSize; i++)
		arr[i-1] = arr[i];
	originalSize--;
}
