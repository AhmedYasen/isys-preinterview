#include "stdio.h"
#include "f5.h"

static unsigned int max_number_index(int nums[], unsigned int length) {
    unsigned int max_index = 0;

    for (unsigned int i = 1; i < length; i++)
    {
        if(nums[max_index] < nums[i]) {
            max_index = i;
        }
    }
    
    return max_index;
}

void f5_solve(int nums[], unsigned int length) {
    unsigned int max_index = max_number_index(nums, length);

    int max_sum = nums[max_index];
    int sum = nums[max_index];

    for (unsigned int i = max_index + 1; i < length; i++)
    {
        sum += nums[i];

        if(sum > max_sum) {
            max_sum = sum;
        }
    }


    sum = nums[max_index];

    for (int i = max_index - 1; i >= 0 ; i--)
    {
        sum += nums[i];

        if(sum > max_sum) {
            max_sum = sum;
        }
    }
    
    printf("%d\n", max_sum);
}