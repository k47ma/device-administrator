// This is the interface for searching menu module
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "menu_search.h"
#include "menu_sort.h"
#include "llist.h"
#include "basic.h"
#include "search.h"


// ask_sort() asks the user whether sorted is needed and returns the result
// effects: prints out information
static bool ask_sort() {
	char cmd;
	printf("\nDo you want to sort the result? (Y/N) ");
	scanf(" %c", &cmd);
	if (cmd == 'y' || cmd == 'Y') {
		return true;
	} else if (cmd == 'n' || cmd == 'N') {
		return false;
	} else {
		printf("Invalid command! Please check your input.\n");
		return ask_sort();
	}
}

void search_menu(const struct llist *list) {
	struct llist *temp_list = NULL;
	while (1) {
		printf("\nStart Menu > Main > Search\n");
		printf("Please select an operation:\n");
		printf("  i - Search the chart by number\n");
		printf("  t - Search the chart by type name\n");
		printf("  n - Search the chart by device name\n");
		printf("  p - Search the chart by price\n");
		printf("  d - Search the chart by date\n");
		printf("  s - Search the chart by (scrap) status\n");
		printf("  a - Search the chart by scrap date\n");
		printf("  b - Back to the main menu\n");
		printf("\ncommand: ");

		char cmd;
		int min, max;
		double dmin, dmax;
		bool b;
		char *from = malloc(1024 * sizeof(char));
		char *to = malloc(1024 * sizeof(char));

		// invalid input
		while (scanf(" %c", &cmd) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("\ncommand: ");
		}

		destroy(temp_list);

		// sort the list and store the result in new_list
		while (1) {
			if (cmd == 'i' || cmd == 'I') {
				read_int(&min, &max);
				printf("Searching the list by number... Complete!\n");
				temp_list = int_filter(list, 'n', min, max);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 't' || cmd == 'T') {
				read_str(from, to);
				printf("Searching the list by type name... Complete!\n");
				temp_list = str_filter(list, 't', from, to);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 'n' || cmd == 'N') {
				read_str(from, to);
				printf("Searching the list by name... Complete!\n");
				temp_list = str_filter(list, 'n', from, to);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 'p' || cmd == 'P') {
				read_double(&dmin, &dmax);
				printf("Searching the list by price... Complete!\n");
				temp_list = double_filter(list, dmin, dmax);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 'd' || cmd == 'D') {
				read_int(&min, &max);
				printf("Searching the list by date... Complete!\n");
				temp_list = int_filter(list, 'd', min, max);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 's' || cmd == 'S') {
				read_bool(&b);
				printf("Searching the list by scrap status... Complete!\n");
				temp_list = bool_filter(list, b);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 'a' || cmd == 'A') {
				read_int(&min, &max);
				printf("Searching the list by scrapping date... Complete!\n");
				temp_list = int_filter(list, 's', min, max);
				print(temp_list);
				if (ask_sort()) {
					sort_menu(temp_list, NULL);
				}
				break;
			} else if (cmd == 'b' || cmd == 'B') {
				free(from);
				free(to);
				return;
			} else {
				printf("Invalid command! Please check your input.\n");
				printf("\ncommand: ");
				scanf(" %c", &cmd);
			}
		}
	}
}
