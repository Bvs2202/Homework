#include <stdio.h>

#define N 3 

int main()
{
    int arr[N][N] = {0};
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            arr[i][k] = ++count;
            printf(" %2d", arr[i][k]);
        }
        printf("\n");
    }
}
