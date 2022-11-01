#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "f6.h"

static unsigned int **mat;
static unsigned int mat_row_index = 0;
static unsigned int mat_col_index = 0;
static void print_mat(unsigned int x, unsigned int n)
{
    for (unsigned int i = 0; i < x; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            printf("%d, ", mat[i][j]);
        }
        printf("\r\n");
    }
}
static void zero_row_col(unsigned int x, unsigned int n)
{

    unsigned int indexes[x * n][2];
    unsigned int last_index = 0;
    
    for (unsigned int i = 0; i < x; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if ((mat[i][j] == 0))
            {
                indexes[last_index][0] = i;
                indexes[last_index][1] = j;
                last_index++;
            }
        }
    }

    for (unsigned int i = 0; i < last_index; i++)
    {
        unsigned int col = indexes[i][1];
        for (unsigned int z = 0; z < x; z++)
        {
            mat[z][col] = 0;
        }

        unsigned int row = indexes[i][0];
        for (unsigned int z = 0; z < n; z++)
        {
            mat[row][z] = 0;
        }
    }
}

void f6_solve(int **m, unsigned int x, unsigned int n)
{
    {
        unsigned int matrix[x][n];
        memcpy(matrix, m, x * n * sizeof(int));

        mat = (unsigned int **)malloc(sizeof(int *) * x);
        for (unsigned int i = 0; i < x; i++)
        {
            mat[i] = (int *)malloc(sizeof(int) * n);
            memcpy(mat[i], matrix[i], sizeof(int) * n);
        }
    }

    zero_row_col(x, n);
    print_mat(x, n);
}