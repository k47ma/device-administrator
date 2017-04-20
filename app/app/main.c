#include "index.h"
#include <stdio.h>
#include <stdbool.h>


int main(void) {
	printf("Hello! Welcome to the Device Administrator v1.3.1!\n\n");
	while (1) {
		printf("Start Menu\n");
		printf("Please select an operation:\n");
		printf("  e - Start your work with existing file\n");
		printf("  n - Start your work with new file\n");
		printf("  q - Quit the application\n");
		printf("\ncommand: ");

		char cmd;

		// input is invalid
		while (scanf(" %c", &cmd) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("\ncommand: ");
		}

		while (1) {
			if (cmd == 'e' || cmd == 'E') {
				load_menu();
				break;
			} else if (cmd == 'n' || cmd == 'N') {
				new_menu();
				break;
			} else if (cmd == 'q' || cmd == 'Q') {
				printf("Thanks for using!\n");
				return;
			} else {
				printf("Invalid command! Please check your input.\n");
				printf("\ncommand: ");
				scanf(" %c", &cmd);
			}
		}
	}
}
