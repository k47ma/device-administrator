// This is the implementation for the module of sorting menu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "menu_sort.h"
#include "llist.h"
#include "basic.h"
#include "io.h"
#include "sort.h"
#include "cmpfn.h"
#include "read.h"



struct llist *sort_menu(struct llist *list, const char *dir) {
	struct llist *new_list = NULL;
	while (1) {
		if (dir != NULL) {
			// called from main menu
			printf("\nStart Menu > Main > Sort\n");
		} else {
			// called from search menu
			printf("\nStart Menu > Main > Search > Sort Result\n");
		}
		printf("Please select an operation:\n");
		printf("  i - Sort the chart by number\n");
		printf("  t - Sort the chart by type name\n");
		printf("  n - Sort the chart by device name\n");
		printf("  p - Sort the chart by price\n");
		printf("  d - Sort the chart by date\n");
		printf("  s - Sort the chart by (scrap) status\n");
		printf("  a - Sort the chart by scrap date\n");
		if (dir != NULL) {
			printf("  b - Back to the main menu\n");
		} else {
			printf("  b - Back to the search menu\n");
		}
		printf("\ncommand: ");

		char cmd;
		bool reverse;

		// invalid input
		while (scanf(" %c", &cmd) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("\ncommand: ");
		}

		// sort the list and store the result in new_list
		while (1) {
			if (cmd == 'i' || cmd == 'I') {
				reverse = reverse_menu();
				printf("Sorting the list by number... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_num, reverse);
				print(new_list);
				break;
			} else if (cmd == 't' || cmd == 'T') {
				reverse = reverse_menu();
				printf("Sorting the list by type name... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_type, reverse);
				print(new_list);
				break;
			} else if (cmd == 'n' || cmd == 'N') {
				reverse = reverse_menu();
				printf("Sorting the list by name... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_name, reverse);
				print(new_list);
				break;
			} else if (cmd == 'p' || cmd == 'P') {
				reverse = reverse_menu();
				printf("Sorting the list by price... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_price, reverse);
				print(new_list);
				break;
			} else if (cmd == 'd' || cmd == 'D') {
				reverse = reverse_menu();
				printf("Sorting the list by date... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_date, reverse);
				print(new_list);
				break;
			} else if (cmd == 's' || cmd == 'S') {
				reverse = reverse_menu();
				printf("Sorting the list by status... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_scrap, reverse);
				print(new_list);
				break;
			} else if (cmd == 'a' || cmd == 'A') {
				reverse = reverse_menu();
				printf("Sorting the list by scrap date... Complete!\n");
				if (new_list) {
					destroy(new_list);
				}
				new_list = sort(list, cmp_sdate, reverse);
				print(new_list);
				break;
			} else if (cmd == 'b' || cmd == 'B') {
				while (new_list != NULL && dir != NULL) {
					char c;
					printf("Do you want to save the result to your file (will overwrite the original file)? (Y/N) ");
					while (scanf(" %c", &c) != 1) {
						printf("Invalid input! Please check your input.\n");
						printf("(Y/N) ");
					}
					if (c == 'y' || c == 'Y') {
						store(new_list, dir);
						destroy(list);
						list = new_list;
						break;
					} else if (c == 'n' || c == 'N') {
						destroy(new_list);
						break;
					} else {
						printf("Invalid command! Please check your input.\n");
					}
				}
				return list;
			} else {
				printf("Invalid command! Please check your input.\n");
				printf("\ncommand: ");
				scanf(" %c", &cmd);
			}
		}
	}
}
