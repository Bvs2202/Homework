
#include <stdio.h>

#define N 5 

int main()
{
    int arr[N][N] = {0};
    int i = 0, k = 0, x = 0;
    int step = 0, flag = 0;

    while (x != N * N)
    {
        arr[i][k] = ++x;

        flag = 0;
        if (i == step && k != N - 1 - step)
            k++;
        else if (k == N - 1 - step && i != N - 1 - step)
            i++;
        else if (k != step && i == N - 1 - step)
            k--;
        else if (k == step & i != step + 1)
        {
            flag = 1;
            i--;
        }
        if (i == step + 1 && k == step && flag == 1)
            step++;
    }

    for (int ii = 0; ii < N; ii++)
    {
        for (int kk = 0; kk < N; kk++)
        {
            printf("%-2d ", arr[ii][kk]);
        }
        printf("\n");
    }
}
