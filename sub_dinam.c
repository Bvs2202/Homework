#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

#define SIZE_BUFF 128

int global_id = 0;

typedef struct subscriber
{
    int id;
    char *surename;
    char *first_name;
    char *midle_name;
    uint64_t number;
    struct subscriber *next;
} SUBSCRIBER;

void search_subscriber(struct subscriber *head)
{
    char surename[SIZE_BUFF] = {0};
    struct subscriber *curr = NULL;

    printf("Введите фамилию абонента: ");
    fgets(surename, SIZE_BUFF, stdin);

    surename[strlen(surename) - 1] = '\0'; 

    for (curr = head; curr != NULL; curr = curr->next)
    {
        if (strcmp(surename, curr->surename) == 0)
        {
            printf("Абонент найден:\n");
            printf("[%d] - ", curr->id);
            printf("%s ", curr->surename);
            printf("%s ", curr->first_name);
            printf("%s ", curr->midle_name);
            printf("%ld\n", curr->number);
            return;
        }
    }

    printf("Абонент не найден.\n");
}

void del_subscriber(struct subscriber **head)
{
    int id_subscriber = 0;
    struct subscriber *prev = NULL;
    struct subscriber *curr = NULL;

    printf("Введите ID абонента для удаления: ");
    scanf("%d", &id_subscriber);

    for (curr = *head; curr != NULL; curr = curr->next)
    {   
        if (id_subscriber == curr->id)
        {
            printf("id = %d\n", curr->id);
            break;
        }
        prev = curr;
    }

    if (curr != NULL)
    {
        if (*head == curr)
            *head = curr->next;

        free(curr->surename);
        free(curr->first_name);
        free(curr->midle_name);

        if (prev != NULL)
            prev->next = curr->next;

        free(curr);

        printf("Абонент удалён.\n");
    }
    else
    {
        printf("Абонент не найден.\n");
    }
}

int add_subscriber(struct subscriber **head, char *sn, char *fn, char *mn, uint64_t num)
{
    struct subscriber *my_sub_new = NULL;
    struct subscriber *last = NULL;

    my_sub_new = malloc(sizeof(SUBSCRIBER));

    my_sub_new->id = ++global_id;
    my_sub_new->surename = sn;
    my_sub_new->first_name = fn;
    my_sub_new->midle_name = mn;
    my_sub_new->number = num;
    my_sub_new->next = NULL;

    if (*head == NULL)
        *head = my_sub_new;
    else
    {
        for (last = *head; last->next != NULL; last = last->next);
        last->next = my_sub_new;
    } 

    return 0;
}

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

void print_struct(struct subscriber *my_subscriber)
{
    printf("\n");
    for (struct subscriber *ptr = my_subscriber; ptr != NULL; ptr = ptr->next)
    {
        printf("[%d] - ", ptr->id);
        printf("%s ", ptr->surename);
        printf("%s ", ptr->first_name);
        printf("%s ", ptr->midle_name);
        printf("%ld\n", ptr->number);
    }
}

int input_struct_data(struct subscriber **head)
{
    char *surename;
    char *first_name;
    char *midle_name;
    uint64_t number;

    printf("Input surename: ");
    input_data(&surename);
    
    printf("Input firstname: ");
    input_data(&first_name);
    
    printf("Input midlename: ");
    input_data(&midle_name);

    printf("Input number: ");
    scanf("%ld", &number);

    add_subscriber(head, surename, first_name, midle_name, number);
}

int main()
{
    int operation;
    struct subscriber *my_subscriber = NULL;

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
        getchar();

        switch (operation)
        {
            case 1:
                search_subscriber(my_subscriber);
                break;
            case 2:
                printf("\n");
                input_struct_data(&my_subscriber);
                break;
            case 3:
                del_subscriber(&my_subscriber);
                break;
            case 4:
                print_struct(my_subscriber);
                break;
            case 5:
                return 0;
            default:
                printf("Введена неверная операция.\n");
                break;
        }

        operation = 0;
    }

    return 0;
}
