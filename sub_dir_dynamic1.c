#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

#define SIZE_BUFF 128

typedef struct subcriber
{
    char *surename;
    char *first_name;
    char *midle_name;
    uint64_t number;
    struct subcriber *next;
} SUBSCRIBER;


int del_subscriber(struct subcriber **my_subcriber, char *sn, char *fn, char *mn, uint64_t num)
{
    int flag_found = 0;
    struct subcriber *prev;
    struct subcriber *curr;

    /*for (struct subcriber *curr = my_subcriber; curr != NULL; curr = curr->next)
    {
        if (sn != NULL)
            flag_found = 0;
            if (strcmp(curr->surename, sn) == 0)
                flag_found = 1;
            
        if (fn != NULL)
            flag_found = 0;
            if (strcmp(, fn) == 0)
                flag_found = 1;
            
        if (mn != NULL)
            flag_found = 0;
            if (strcmp(, mn) == 0)
                flag_found = 1;
            
        if (num != 0)
            flag_found = 0;
            if (num == .->num)
                flag_found = 1;

        prev = curr;
            
        if (flag_found == 1)
            break;
    }*/

    if (curr != NULL && flag_found == 1)
    {
        free(curr->surename);
        free(curr->first_name);
        free(curr->midle_name);

        prev->next = curr->next;
        
        free(curr);
    }
}

int add_subscriber(struct subcriber **my_subcriber, char *sn, char *fn, char *mn, uint64_t num)
{
    struct subcriber *my_sub_new = NULL;

    my_sub_new = malloc(sizeof(SUBSCRIBER));

    my_sub_new->surename = sn;
    my_sub_new->first_name = fn;
    my_sub_new->midle_name = mn;
    my_sub_new->number = num;
    my_sub_new->next = NULL;

    if (*my_subcriber == NULL)
        *my_subcriber = my_sub_new;
    else
    {
        (*my_subcriber)->next = my_sub_new;
    } 

    return 0;
}

/*
void input_num(int *x)
{
    // VARIANT 1 START
    int *tmp_x_new = 0;

    x = malloc
    
    tmp_x_new = (int *)malloc(sizeof(int *));
    tmp_x_new = 0xFFFFFFFF;

    *x = tmp_x_new;
    // VARIANT 1 END 

    // VARIANT 2 START
    *x = (int *)malloc(sizeof(int *));
    *x = 0xFFFFFFFF;
    // VARIANT 2 END

    return;
}

int main(void)
{
    int *x = NULL;
    input_num(&x);

}
*/

int input_data(char **str_buff)
{
    int len;
    char *tmp_str = NULL;
    char tmp_buff[SIZE_BUFF] = {0};

    fgets(tmp_buff, SIZE_BUFF, stdin);
    len = strlen(tmp_buff);
    tmp_str = (char*)malloc(sizeof(char) * len);

    if (tmp_str == NULL)
        return -1;

    strcpy(tmp_str, tmp_buff);
    memset(tmp_buff, 0, SIZE_BUFF);
    tmp_str[len - 1] = '\0'; 

    *str_buff = tmp_str;

    return 0;
}

void print_struct(struct subcriber *my_subcriber)
{
    //printf("ptr struct %p\n", my_subcriber);
    for (struct subcriber *ptr = my_subcriber; ptr != NULL; ptr = ptr->next)
    {
        printf("\nsn = %s\n", ptr->surename);
        printf("fn = %s\n", ptr->first_name);
        printf("mn = %s\n", ptr->midle_name);
        printf("num = %ld\n", ptr->number);
    }
}

int input_struct_data(struct subcriber **my_subcriber)
{   
    char *surename;
    char *first_name;
    char *midle_name;
    uint64_t number;

    printf("ptr struct %p\n", &(*my_subcriber));

    printf("Input surename: ");
    input_data(&surename);
    
    printf("Input firstname: ");
    input_data(&first_name);
    
    printf("Input midlename: ");
    input_data(&midle_name);

    printf("Input number: ");
    scanf("%ld", &number);

    add_subscriber(my_subcriber, surename, first_name, midle_name, number);
}

int main()
{ 
    struct subcriber *my_subcriber = NULL;

    printf("ptr NULL = %p\n", &my_subcriber);
    add_subscriber(&my_subcriber, "Petrov", "Ivan", "Ivanovich", 79992838383);
    add_subscriber(&my_subcriber, "Ivanov", "Alexander", "Michailovich", 79963332211);
    //print_struct(my_subcriber);
    input_struct_data(&my_subcriber);
    print_struct(my_subcriber);

    printf("Input surename, firstname, midlename:");
    scanf("%s %s %s", );

    //add_subscriber(my_subcriber, "Sidorov", "Nikolay", "Ivanovich", 79992838383);
    //add_subscriber(my_subcriber, "Batomunkuev", "Vova", "Ivanovich", 79992838383);

    /*
    
    while (1)
    {
        printf("\n");
        printf("1 - Поиск\n");
        printf("2 - Добавление\n");
        printf("3 - Удаление\n");
        printf("4 - Вывод\n");
        printf("5 - Выход\n");
        printf("Введите номер операции: ");

        scanf("%d", &operation);


    }*/
    return 0;
}
