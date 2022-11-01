#include "stdio.h"
#include "string.h"
#include "f2.h"

// ALPHA    = 1
// NUM      = 2
// NONE     = 4

typedef enum
{
    ALL_ALPHA = 0x11,
    HIGH_ALPHA_LOW_NUM = 0x12,
    HIGH_NUM_LOW_ALPHA = 0x21,
    ALL_NUM = 0x22,
    ALL_NONE = 0x44,
    ONLY_HIGH_IS_NONE = 0x40,
    ONLY_LOW_IS_NONE = 0x04
} Priority_t;

static unsigned char is_alpha(unsigned int sym)
{
    return ((sym >= 'a') && (sym <= 'z'));
}

static Priority_t check_priority_type(unsigned int prereq_h, unsigned int prereq_l)
{
    Priority_t type = 0x00;

    if (is_alpha(prereq_h))
    {
        type |= 0x10;
    }
    else if (prereq_h == (unsigned int)-1)
    {
        type |= 0x40;
    }
    else
    {
        type |= 0x20;
    }

    if (is_alpha(prereq_l))
    {
        type |= 0x01;
    }
    else if (prereq_h == (unsigned int)-1)
    {
        type |= 0x04;
    }
    else
    {
        type |= 0x02;
    }

    // if one of them is none return which one (high or low or all)
    if (type & ALL_NONE)
    {
        return type & ALL_NONE;
    }

    return type;
}

typedef enum
{
    UP = 1,
    DOWN = -1,
} PriorityDir_t;

static void shift_priorities(int priorities[], unsigned int numCourses, unsigned int priority, PriorityDir_t Dir)
{
    unsigned char isBaseAlpha = is_alpha(priority);

    for (unsigned int loopIndex = 0; loopIndex < numCourses; loopIndex++)
    {
        unsigned char p = priorities[loopIndex];

        if((Dir == UP) && (p < priority)) {
            priorities[loopIndex] += isBaseAlpha? is_alpha(p): 1;
        } else if ((Dir == DOWN) && (p > priority)) {
            priorities[loopIndex] -= isBaseAlpha? is_alpha(p): 1;
        } else {
            // p has no priority yet
        }
    }

}   

void f2_solve(unsigned int numCourses, unsigned int prerequesites[][2], unsigned int prereq_length)
{
    unsigned char ret = 1;
    unsigned int fail_index;
    int priorities[numCourses];
    memset(priorities, -1, numCourses * sizeof(priorities[0]));

    Priority_t priority_type;

    int final_priorities = numCourses / 2;
    char temp_priorities = (('z' - 'a') / 2) + 'a';
    unsigned int prereq_h = prerequesites[0][1];
    unsigned int prereq_l = prerequesites[0][0];
    priorities[prereq_l] = final_priorities++;
    priorities[prereq_h] = final_priorities++;

    for (size_t i = 1; i < prereq_length; i++)
    {
        prereq_h = prerequesites[i][1];
        prereq_l = prerequesites[i][0];


        priority_type = check_priority_type(priorities[prereq_h], priorities[prereq_l]);

        switch (priority_type)
        {
        case ALL_ALPHA:
        case ALL_NUM:
        {
            // check if the same order set as before
            if (priorities[prereq_h] < priorities[prereq_l])
            {
                // wrong -> break
                ret = 0;
                fail_index = i;
                i = prereq_length;
            }
        }

        break;
        case ALL_NONE:
        {
            priorities[prereq_l] = temp_priorities++;
            priorities[prereq_h] = temp_priorities++;
        }
        break;
        case ONLY_HIGH_IS_NONE:
        case HIGH_ALPHA_LOW_NUM:
        {
            unsigned char pl = priorities[prereq_l];
            shift_priorities(priorities, numCourses, pl, DOWN);
            priorities[prereq_h] = pl + 1;

        }
        break;
        case ONLY_LOW_IS_NONE:
        case HIGH_NUM_LOW_ALPHA:
        {
            unsigned char ph = priorities[prereq_h];
            shift_priorities(priorities, numCourses, ph, UP);
            priorities[prereq_l] = priorities[prereq_h] - 1;
        }
        break;
        default:
            break;
        }
    }

    printf("%s", (ret?"true\n":"false ->\t"));
    if(ret == 0) {
        printf("because [%d, %d] at index (%d)\n", prereq_l, prereq_h, fail_index);
    }
}