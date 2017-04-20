// This is the implementation for the edit menu module
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "menu_edit.h"
#include "llist.h"
#include "basic.h"
#include "edit.h"
#include "io.h"
#include "date.h"
#include "search.h"


void modify_menu(struct llist *list, const char *dir) {
	while (1) {
		printf("\nStart Menu > Main > Edit\n");
		printf("Please select an operation:\n");
		printf("  a - Add item\n");
		printf("  d - Delete item\n");
		printf("  e - Edit item\n");
		printf("  b - Back to the Main Menu\n");
		printf("\ncommand: ");

		char cmd;

		// invalid input
		while (scanf(" %c", &cmd) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("\ncommand: ");
		}

		while (1) {
			if (cmd == 'a' || cmd == 'A') {
				add_menu(list, dir);
				break;
			} else if (cmd == 'd' || cmd == 'D') {
				remove_menu(list, dir);
				break;
			} else if (cmd == 'e' || cmd == 'E') {
				edit_menu(list, dir);
				break;
			} else if (cmd == 'b' || cmd == 'B') {
				return;
			} else {
				printf("Invalid command! Please check your input.\n");
				printf("\ncommand: ");
				scanf(" %c", &cmd);
			}
		}
	}
}

void add_menu(struct llist *list, const char *dir) {
	printf("\nStart Menu > Main > Edit > Add Entry\n");
	// list is invalid
	if (list == NULL) return;

	// variables for reading information
	int num, date, scrap, sdate;
	char type[1024];
	char name[1024];
	double price;
	char c;

	// read in information
	printf("Please input the corresponding information of the new item\n");
	printf("or type b to exit:\n");
	printf("Number: ");

	// invalid input or exit command
	while (scanf("%d", &num) != 1) {
		if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
			return;
		} else {
			printf("Invalid input! Please check your input.\n");
			printf("Number: ");
		}
	}

	printf("Type: ");
	while (scanf("%s", type) != 1) {
		if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
			return;
		} else {
			printf("Invalid input! Please check your input.\n");
			printf("Type: ");
		}
	}

	printf("Name: ");
	while (scanf("%s", name) != 1) {
		if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
			return;
		} else {
			printf("Invalid input! Please check your input.\n");
			printf("Name: ");
		}
	}

	printf("Price: ");
	while (scanf("%lf", &price) != 1) {
		if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
			return;
		} else {
			printf("Invalid input! Please check your input.\n");
			printf("Price: ");
		}
	}

	while (1) {
		printf("Date (e.g. 20160101): ");
		// invalid input or exit command
		while (scanf("%d", &date) != 1) {
			if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
				return;
			} else {
				printf("Invalid input! Please check your input.\n");
				printf("Date (e.g. 20160101): ");
				break;
			}
		}
		// validate the date
		if (valid_date(date)) {
			break;
		} else {
			printf("Invalid date! Please check your input.\n");
		}
	}

	while (1) {
		printf("Scrap (Y/N): ");
		scanf(" %c", &c);
		if (c == 'y' || c == 'Y') {
			scrap = 1;
			break;
		} else if (c == 'n' || c == 'N') {
			scrap = 0;
			break;
		} else {
			printf("Invalid value! Please check your input.\n");
		}
	}

	while (1) {
		printf("Scrap Date (e.g. 20160101): ");
		// invalid input or exit command
		while (scanf("%d", &sdate) != 1) {
			if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
				return;
			} else {
				printf("Invalid input! Please check your input.\n");
				printf("Scrap Date (e.g. 20160101): ");
				break;
			}
		}
		// validate the date
		if (valid_date(sdate)) {
			break;
		} else {
			printf("Invalid date! Please check your input.\n");
		}
	}

	// add the new item to the list
	printf("Adding item...\n");
	int year, month, day, syear, smonth, sday;
	year = date / 10000;
	month = date % 10000 / 100;
	day = date % 100;
	syear = sdate / 10000;
	smonth = sdate % 10000 / 100;
	sday = sdate % 100;

	struct llnode *newnode = create_node(num, type, name, price, year, month, day,
		scrap, syear, smonth, sday);

	if (insert_item(list, newnode)) {
		printf("Complete! Here is the new node:\n");
		print_node(newnode);
		store(list, dir);
	} else {
		printf("Adding item fails. Please check your input.\n");
	}
}

void remove_menu(struct llist *list, const char *dir) {
	printf("\nStart Menu > Main > Edit > Remove Entry\n");
	int num;
	char c;
	printf("Please input the number of the item your want to remove\n");
	printf("or type b to exit: ");

	// invalid input or exit command
	while (scanf("%d", &num) != 1) {
		if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
			return;
		} else {
			printf("Invalid input! Please check your input.\n");
		}
	}

	struct llnode *item = lookup(list, num);
	printf("Removing item...\n");
	if (item) {
		print_node(item);
		remove_item(list, num);
		store(list, dir);
		printf("Complete!\n");
	} else {
		printf("Removing item fails. Please check your input.\n");
	}
}


void edit_menu(struct llist *list, const char *dir) {
	while (1) {
		printf("\nStart Menu > Main > Edit > Edit Entry\n");
		printf("Please input the number of the item you want to edit\n");
		printf("or type b to exit: ");
		int num;
		char c;

		// invalid input or exit command
		while (scanf("%d", &num) != 1) {
			if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
				return;
			} else {
				printf("Invalid input! Please check your input.\n");
			}
		}

		// item does not exist
		struct llnode *item = lookup(list, num);
		if (item == NULL) {
			printf("Item does not exist! Please check your input.\n");
			continue;
		}

		printf("Item found!\n");
		print_node(item);

		// variables for reading information
		int date, scrap, sdate;
		char type[1024];
		char name[1024];
		double price;

		// read in information
		printf("Please input the corresponding new information\n");
		printf("or type b to exit: ");
		printf("Number: ");

		// invalid input or exit command
		while (scanf("%d", &num) != 1) {
			if (scanf(" %c", &c) == 1 && (c == 'b' || c == 'B')) {
				return;
			} else {
				printf("Invalid input! Please check your input.\n");
				printf("Number: ");
			}
		}

		printf("Type: ");
		while (scanf("%s", type) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("Type: ");
		}

		printf("Name: ");
		while (scanf("%s", name) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("Name: ");
		}

		printf("Price: ");
		while (scanf("%lf", &price) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("Price: ");
		}

		printf("Date (eg. 20160101): ");
		while (1) {
			if (scanf("%d", &date) != 1) {
				printf("Invalid input! Please check your input.\n");
			} else if (!valid_date(date)) {
				printf("Invalid date! Please check your input.\n");
			} else {
				break;
			}
			printf("Date(eg. 20160101): ");
		}

		printf("Scrap: ");
		while (scanf("%d", &scrap) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("Price: ");
		}

		printf("Scrap Date(eg. 20160101): ");
		while (1) {
			if (scanf("%d", &sdate) != 1) {
				printf("Invalid input! Please check your input.\n");
			} else if (!valid_date(sdate)) {
				printf("Invalid date! Please check your input.\n");
			} else {
				break;
			}
			printf("Scrap Date(eg. 20160101): ");
		}

		// update the item
		printf("Updating item...\n");
		int year, month, day, syear, smonth, sday;
		year = date / 10000;
		month = date % 10000 / 100;
		day = date % 100;
		syear = sdate / 10000;
		smonth = sdate % 10000 / 100;
		sday = sdate % 100;

		if (edit(item, num, type, name, price, year, month, day, scrap,
			syear, smonth, sday)) {
			printf("Complete! Here is the new item:\n");
			print_node(item);
			store(list, dir);
			return;
		} else {
			printf("Updating item fails! Please check your input.\n");
		}
	}
}
