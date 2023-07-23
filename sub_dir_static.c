#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NUM_SUBCRIBERS 1000

struct subcriber
{
	char surename[32];
	char first_name[32];
	char midle_name[32];
	uint64_t number;
	int valid;
};

int add_subscriber(struct subcriber *my_struct, char *sn, char *fn, char *mn, uint64_t num)
{
	for (int i = 0; i < NUM_SUBCRIBERS; i++)
	{
		if (my_struct[i].valid == 0)
		{
			memcpy(my_struct[i].surename, sn, strlen(sn));
			memcpy(my_struct[i].first_name, fn, strlen(fn));
			memcpy(my_struct[i].midle_name, mn, strlen(mn));
			my_struct[i].number = num;
			my_struct[i].valid = 1;

			return 0;
		}
	}

	return -1;
}

int main()
{ 
	struct subcriber my_subcriber[NUM_SUBCRIBERS];
	int index = 0;
	int operation;
	int delete_index;
	int search_index;
	int not_found = 0;
	char search_surename[32];
	char search_first_name[32];
	uint64_t search_number; 
	char surename[32];
	char first_name[32];
	char midle_name[32];
	uint64_t number;

	memset(my_subcriber, 0, sizeof(struct subcriber) * NUM_SUBCRIBERS);

	//my_subcriber[index++] = (struct subcriber){"Alexseev", "Alexander", "Vladimirovich", 94190544502825};
	add_subscriber(my_subcriber, "Alexseev", "Petr", "Perovich", 111);
	add_subscriber(my_subcriber, "Petrov", "Alexander", "Pirogoevich", 222);
	add_subscriber(my_subcriber, "Hrenova", "Gadya", "Petrovich", 333);
	add_subscriber(my_subcriber, "Nimaev", "Amgalan", "Vladimirovich", 444);
	add_subscriber(my_subcriber, "Bazarsadaev", "Bato", "Soktoevich", 555);
	add_subscriber(my_subcriber, "Batomunkuev", "Vladimir", "Soelovich", 666);
	add_subscriber(my_subcriber, "Alexseev", "Solbon", "Michaelovich", 777);
	add_subscriber(my_subcriber, "Bulatov", "Bulat", "Damdinovich", 888);
	add_subscriber(my_subcriber, "Alexandrov", "Alexander", "Vladimirovich", 999);
	add_subscriber(my_subcriber,  "Stolpoev", "Alexey", "Alexandrovich", 123);

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
						for (int i = 0; i < NUM_SUBCRIBERS; i++)
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
						for (int i = 0; i < NUM_SUBCRIBERS; i++)
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
						for (int i = 0; i < NUM_SUBCRIBERS; i++)
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
				add_subscriber(my_subcriber, surename, first_name, midle_name, number);
				break;
			case 3:
				printf("Введите индекс абонента: ");
				scanf("%d", &delete_index);
				if (delete_index > 0 && delete_index <= NUM_SUBCRIBERS &&
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
				for (int i = 0; i < NUM_SUBCRIBERS; i++)
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