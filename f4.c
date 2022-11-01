#include "stdio.h"
#include "string.h"
#include "f4.h"

void f4_solve(unsigned char root[], unsigned int length)
{
    unsigned char max_levels = 0;
    for (unsigned int len = length; len;)
    {
        max_levels += len & 0x01;
        len >>= 1;
    }

    unsigned int answerSize = length + max_levels;
    unsigned char answer[answerSize];

    memset(answer, '\0', length + max_levels);

    unsigned char level_size = 1;

    for (unsigned int rootIndex = 0, answerIndex = 0; rootIndex < length;)
    {
        for (unsigned int levelIndex = 0; levelIndex < level_size; levelIndex++)
        {
            if (root[rootIndex] != '\0')
            {
                answer[answerIndex++] = root[rootIndex];
            }
            rootIndex++;
        }

        answer[answerIndex++] = '#';
        level_size <<= 1;
    }

    printf("[");
    if (answerSize > 0)
    {

        for (unsigned int loopIndex = 0; answer[loopIndex] != '\0'; loopIndex++)
        {
            if (answer[loopIndex] != '#')
            {
                printf("%d, ", answer[loopIndex]);
            }
            else
            {
                printf("#, ");
            }
        }
    }
    printf("]\n");
}