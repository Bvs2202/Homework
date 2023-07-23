#include "operations.h"
#include <stdio.h>

int main (void)
{
    int a, b;
    int result;
    int n;

    do
    {
        printf("\nВведите номер операции:\n");
        printf("1 - сложение\n");
        printf("2 - вычитание\n");
        printf("3 - умножение\n");
        printf("4 - деление\n");
        printf("5 - выход\n\n");
        printf("Операция: ");

        scanf("%d", &n);

        if (n == 5)
            break;

        printf("Введите два числа: ");
        scanf("%d %d", &a, &b);

        switch(n)
        {
            case 1:
                result = add(a, b);
                break;
            case 2:
                result = sub(a, b);
                break;
            case 3:
                result = mul(a, b);
                break;
            case 4:
                result = div(a, b);
                break;
            default:
                printf("Введина неверная операция.\n");
        }

        if (n > 0 && n < 5)
            printf("Результат : %d\n", result);

        n = 0;
    }
    while(1);

    return 0;
}