#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>


struct subcriber
{
	char surename[32];
	char first_name[32];
	char midle_name[32];
	uint64_t number;
	int valid;
    struct subcriber *next;
};

struct subcriber* head = NULL;


int add_subscriber(struct subcriber *head, char *sn, char *fn, char *mn, uint64_t num, int *size_dir)
{
	struct subcriber* new_subcriber = (struct subcriber*)malloc(sizeof(struct subcriber));

	size_dir++;
	
	for (int i = 0; i < size_dir; i++)
	{
		if (new_subcriber[i].valid == 0)
		{
			memcpy(new_subcriber[i].surename, sn, strlen(sn));
			memcpy(new_subcriber[i].first_name, fn, strlen(fn));
			memcpy(new_subcriber[i].midle_name, mn, strlen(mn));
			new_subcriber[i].number = num;
			new_subcriber[i].valid = 1;

			return 0;
		}
	}


	return -1;
}

int main()
{ 
	int index = 0;
	int operation;
	int delete_index;
	int search_index;
	int not_found = 0;
	int size_dir = 0;
	int* p_size_dir;
	p_size_dir = &size_dir;
	char search_surename[32];
	char search_first_name[32];
	uint64_t search_number; 
	char surename[32];
	char first_name[32];
	char midle_name[32];
	uint64_t number;
	struct subcriber my_subcriber[size_dir];

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

		switch(operation)
		{
			case 1:
				printf("\nВведите индекс параметра поиска:\n");
				printf("1 - Фамилия\n");
				printf("2 - Имя\n");
				printf("3 - номер\n");
				scanf("%d", &search_index);
				
				switch(search_index)
				{
					case 1:
						printf("Введите Фамилию абонента: ");
						scanf("%s", search_surename);
						printf("\n");
						for (int i = 0; i < size_dir; i++)
						{
							if (strcmp(my_subcriber[i].surename, search_surename) == 0)
							{
								printf("%d) %s %s %s %lu\n", i + 1,
									my_subcriber[i].first_name, my_subcriber[i].surename,
									my_subcriber[i].midle_name, my_subcriber[i].number);
								not_found = 1;
							}
						}
						if (not_found == 0)
							printf("Фамилия не найдена.\n");
						not_found = 0;
						break;
					case 2:
						printf("Введите Имя абонента: ");
						scanf("%s", search_first_name);
						printf("\n");
						for (int i = 0; i < size_dir; i++)
						{
							if (strcmp(my_subcriber[i].first_name, search_first_name) == 0)
							{
								printf("%d) %s %s %s %lu\n", i + 1,
									my_subcriber[i].first_name, my_subcriber[i].surename,
									my_subcriber[i].midle_name, my_subcriber[i].number);
								not_found = 1;
							}
						}
						if (not_found == 0)
							printf("Имя не найдено.\n");
						not_found = 0;
						break;
					case 3:
						printf("Введите номер абонента: ");
						scanf("%lu", &search_number);
						printf("\n");
						for (int i = 0; i < size_dir; i++)
						{
							if (my_subcriber[i].number == search_number)
							{
								printf("%d) %s %s %s %lu\n", i + 1,
									my_subcriber[i].first_name, my_subcriber[i].surename,
									my_subcriber[i].midle_name, my_subcriber[i].number);
								not_found = 1;
							}
						}
						if (not_found == 0)
							printf("Номер не найден.\n");
						not_found = 0;
						break;
					default:
						printf("Введена неверная команда\n");
						break;
				}
				break;
			case 2:
				printf("Введите ФИО и номер(через пробелы): ");
				memset(surename, 0, sizeof(surename));
				memset(first_name, 0, sizeof(first_name));
				memset(midle_name, 0, sizeof(midle_name));
				scanf("%s %s %s %lu", surename, first_name, midle_name, &number);
				add_subscriber(my_subcriber, surename, first_name, midle_name, number, size_dir);
				break;
			case 3:
				printf("Введите индекс абонента: ");
				scanf("%d", &delete_index);
				if (delete_index > 0 && delete_index <= size_dir &&
					my_subcriber[delete_index].valid == 1)
					{
						printf("Запись удалена - %d) %s %s %s %lu\n", delete_index,
							my_subcriber[delete_index - 1].first_name, my_subcriber[delete_index - 1].surename,
							my_subcriber[delete_index - 1].midle_name, my_subcriber[delete_index - 1].number);
						memset(&my_subcriber[delete_index - 1], 0, sizeof(struct subcriber));
					}
					else
					{
						printf("Введён неверный индекс!\n");
					}
				break;
			case 4:
				printf("\n");
				for (int i = 0; i < size_dir; i++)
				{   
					if (my_subcriber[i].valid == 1)
						printf("%d) %s %s %s %lu\n", i + 1, my_subcriber[i].first_name,
							my_subcriber[i].surename, my_subcriber[i].midle_name, my_subcriber[i].number);
				}
				break;
			case 5:
			default:
				return 0;
		}
	}

	return 0;
}