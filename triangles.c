#include <stdio.h>

#define N 5 

int main()
{
    int arr[N][N] = {0};

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (i + k <= N - 2)
            {
                arr[i][k] = 0;
                printf("%d ", arr[i][k]);
            }
            else
            {
                arr[i][k] = 1;
                printf("%d ", arr[i][k]);
            }
        }
        printf("\n");
    }
}