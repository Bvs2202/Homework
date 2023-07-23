#include <stdio.h>

#define N 5

int main()
{
    int arr[N] = {1, 2, 3, 4 ,5};
    int tmp;

    printf("source: ");
    for (int i = 0; i < N; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    printf("inverse: ");
    for (int i = 0; i <= N / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[N - 1 - i]; 
        arr[N - i - 1] = tmp;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}