#ifndef __UTILS_H
#define __UTILS_H

void copyArrays(const bool* src, bool* dst, int size);
int findPointerInArray(const void* lookFor, void** lookIn, int size);
void closeGaps(int start, void** arr ,int& originalSize);

#endif