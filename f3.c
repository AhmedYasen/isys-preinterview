#include "stdio.h"

#include "f3.h"

static unsigned int sum_subarr(unsigned int m[], unsigned int start, unsigned int end)
{
    unsigned int sum = m[start ++];
    while (start <= end)
    {
        sum += m[start++];
    }
    return sum;
}

void f3_solve(unsigned int target, unsigned int m[], unsigned int length)
{
    unsigned int min_window = 0;
    for (unsigned int window = 0; window < length; window++)
    {

        unsigned int sum = sum_subarr(m, 0, window);
        for (unsigned int start = 0, end = window; end < length; start++, end++)
        {
            if (sum >= target)
            {
                min_window = window + 1;
                window = length;
                end = length;
            }
            else
            {
                sum = sum - m[start] + m[end + 1];
            }
        }
    }

    printf("%d\n", min_window);
}