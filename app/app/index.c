// This is the implementation for the menu module
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "index.h"
#include "menu_edit.h"
#include "menu_sort.h"
#include "menu_search.h"
#include "llist.h"
#include "basic.h"
#include "io.h"


void load_menu() {
	printf("\nStart Menu > Load File\n");
	printf("Please select an operation:\n");
	printf("  i - Load a file from computer\n");
	printf("  b - Back to start menu\n");
	printf("\ncommand: ");

	char cmd;
	char *dir = malloc(1024 * sizeof(char));
	struct llist *list = NULL;

	// invalid input
	while (scanf(" %c", &cmd) != 1) {
		printf("Invalid input! Please check your input.\n");
		printf("\ncommand: ");
	}

	while (1) {
		if (cmd == 'i' || cmd == 'I') {
			printf("Start Menu > Load File > Path\n");
			printf("Path (*.csv): ");
			scanf("%s", dir);
			
			// back to the input menu
			if (strlen(dir) == 1 && (dir[0] == 'b' || dir[0] == 'B')) {
				free(dir);
				load_menu();
				return;
			}

			printf("Loading...\n");
			list = parse(dir);
			if (list == NULL) {
				// parse unsuccessfully
				printf("Invalid path or file name! Please check your file name or type b to exit.\n");
			} else {
				// parse successfully
				printf("File %s has been loaded!\n", dir);
				list = main_menu(list, dir);
				break;
			}
		} else if (cmd == 'b' || cmd == 'B') {
			break;
		} else {
			printf("Invalid command! Please check your input.\n");
			printf("\ncommand: ");
			scanf(" %c", &cmd);
		}
	}
	destroy(list);
	free(dir);
	return;
}


void new_menu() {
	printf("\nStart Menu > New File\n");
	printf("Please select an operation:\n");
	printf("  c - Create a new file with customized name\n");
	printf("  r - Create a new file with random name (temporary file)\n");
	printf("  b - Back to start menu\n");
	printf("\ncommand: ");

	char cmd;
	char *dir = malloc(1024 * sizeof(char));
	struct llist *list = NULL;

	// invalid input
	while (scanf(" %c", &cmd) != 1) {
		printf("Invalid input! Please check your input.\n");
		printf("\ncommand: ");
	}

	while (1) {
		if (cmd == 'c' || cmd == 'C') {
			printf("Start Menu > New File > Create File\n");
			printf("File name (*.csv): ");
			scanf("%s", dir);

			// back to the input menu
			if (strlen(dir) == 1 && (dir[0] == 'b' || dir[0] == 'B')) {
				free(dir);
				load_menu();
				return;
			}

			// generate a new file with the name dir
			//   (the file must not exist originally)
			printf("Generating...\n");
			FILE *fp;
			fp = fopen(dir, "r");
			if (fp != NULL) {
				// the file has existed
				fclose(fp);
				printf("The file has existed. Please change a file name or type b to exit.\n");
				continue;
			} else {
				// create the file
				fp = fopen(dir, "w");
				fclose(fp);
				printf("Complete!");
			}

			// create the list and pass it to the main_menu
			list = create();
			list = main_menu(list, dir);
			break;
		} else if (cmd == 'r' || cmd == 'R') {
			char random[10];
			itoa(time(NULL) % 100000, random, 16);
			strcpy(dir, "tempFile_");
			strcat(dir, random);
			strcat(dir, ".csv");

			// generate a new file with the name fp 
			//   (the file must not exist originally)
			printf("Generating...\n");
			FILE *fp;
			if (fopen(dir, "r") == NULL) {
				// create the file
				fp = fopen(dir, "w");
				fclose(fp);
			} else {
				continue;
			}

			// create the list and pass it to the main_menu
			list = create();
			list = main_menu(list, dir);
			break;
		} else if (cmd == 'b' || cmd == 'B') {
			break;
		} else {
			printf("Invalid command! Please check your input.\n");
			printf("\ncommand: ");
			scanf(" %c", &cmd);
		}
	}
	destroy(list);
	free(dir);
	return;
}


struct llist *main_menu(struct llist *list, const char *dir) {
	while (1) {
		printf("\nStart Menu > Main\n");
		printf("Please select an operation:\n");
		printf("  p - Print the chart to the screen\n");
		printf("  e - Edit the chart\n");
		printf("  s - Sort the chart\n");
		printf("  l - Look up content in the chart\n");
		printf("  b - Back to Start Menu\n");
		printf("\ncommand: ");

		char cmd;

		// invalid input
		while (scanf(" %c", &cmd) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("\ncommand: ");
		}

		while (1) {
			if (cmd == 'p' || cmd == 'P') {
				print(list);
				break;
			} else if (cmd == 'e' || cmd == 'E') {
				modify_menu(list, dir);
				break;
			} else if (cmd == 's' || cmd == 'S') {
				list = sort_menu(list, dir);
				break;
			} else if (cmd == 'l' || cmd == 'L') {
				search_menu(list);
				break;
			} else if (cmd == 'b' || cmd == 'B') {
				return list;
			} else {
				printf("Invalid command! Please check your input.\n");
				printf("\ncommand: ");
				scanf(" %c", &cmd);
			}
		}
	}
}
