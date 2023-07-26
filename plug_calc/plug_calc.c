#include <stdio.h>
#include <dlfcn.h>

int main (void)
{
    int a, b;
    int result;
    int n;
    int (*func_ptr)(int a, int b);
    void *handle;

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
                handle = dlopen("./lib/libadd.so", RTLD_NOW);
                func_ptr = dlsym(handle, "add");
                result = (*func_ptr)(a, b);
                break;
            case 2:
                handle = dlopen("./lib/libsub.so", RTLD_NOW);
                func_ptr = dlsym(handle, "sub");
                result = (*func_ptr)(a, b);
                break;
            case 3:
                handle = dlopen("./lib/libmul.so", RTLD_NOW);
                func_ptr = dlsym(handle, "mul");
                result = (*func_ptr)(a, b);
                break;
            case 4:
                handle = dlopen("./lib/libdiv.so", RTLD_NOW);
                func_ptr = dlsym(handle, "div");
                result = (*func_ptr)(a, b);
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