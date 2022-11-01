#include "stdio.h"

#include "f1.h"
#include "f2.h"
#include "f3.h"
#include "f4.h"
#include "f5.h"
#include "f6.h"

int main()
{

    printf("/************************* F1 *************************/\r\n");
    f1_solve(10);

    printf("/************************* F2 *************************/\r\n");
    unsigned int prerequisites[][2] = {{1, 0}};
    f2_solve(2, prerequisites, sizeof(prerequisites) / sizeof(prerequisites[0]));

    unsigned int prerequisites2[][2] = {{1, 0}, {0, 1}};
    f2_solve(2, prerequisites2, sizeof(prerequisites2) / sizeof(prerequisites2[0]));

    unsigned int prerequisites3[][2] = {{2, 0}, {0, 4}, {3, 1}, {2, 4}, {4, 1}, {3, 2}, {3, 0}, {4, 3}, {2, 1}, {3, 1}, {1, 0}};
    f2_solve(5, prerequisites3, sizeof(prerequisites3) / sizeof(prerequisites3[0]));

    unsigned int prerequisites4[][2] = {{2, 0}, {0, 4}, {3, 1}, {2, 4}, {4, 1}, {3, 2}, {3, 0}, {3, 4}, {2, 1}, {3, 1}, {0, 1}};
    f2_solve(5, prerequisites4, sizeof(prerequisites4) / sizeof(prerequisites4[0]));

    printf("/************************* F3 *************************/\r\n");
    {

        unsigned int nums[] = {2, 3, 1, 2, 4, 3};
        f3_solve(7, nums, sizeof(nums) / sizeof(nums[0]));

        unsigned int nums2[] = {1, 4, 4};
        f3_solve(4, nums2, sizeof(nums2) / sizeof(nums2[0]));

        unsigned int nums3[] = {1, 1, 1, 1, 1, 1, 1, 1};
        f3_solve(11, nums3, sizeof(nums3) / sizeof(nums3[0]));
    }

    printf("/************************* F4 *************************/\r\n");
    unsigned char root[] = {1, 2, 3, 4, 5, '\0', 7};
    f4_solve(root, sizeof(root));

    unsigned char root2[] = {};
    f4_solve(root2, sizeof(root2));

    printf("/************************* F5 *************************/\r\n");
    {

        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        f5_solve(nums, sizeof(nums) / sizeof(nums[0]));

        int nums2[] = {5, 4, -1, 7, 8};
        f5_solve(nums2, sizeof(nums2) / sizeof(nums2[0]));

        int nums3[] = {1};
        f5_solve(nums3, sizeof(nums3) / sizeof(nums3[0]));
    }

    printf("/************************* F6 *************************/\r\n");
    unsigned int matrix[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    f6_solve((int **)matrix, 3, 3);
    printf("\r\n");
    unsigned int matrix2[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    f6_solve((int **)matrix2, 3, 4);
    return 0;
}