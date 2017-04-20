// This is the implementation for reading in information from the user
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "read.h"


bool reverse_menu() {
	while (1) {
		char cmd_r;
		printf("In reversed order? (Y/N) ");
		// invalid input
		while (scanf(" %c", &cmd_r) != 1) {
			printf("Invalid input! Please check your input.\n");
			printf("In reversed order? (Y/N) ");
		}
		if (cmd_r == 'y' || cmd_r == 'Y') {
			return true;
		} else if (cmd_r == 'n' || cmd_r == 'N') {
			return false;
		} else {
			printf("Invalid command! Please check your input.\n");
		}
	}
}


void read_int(int *min, int *max) {
	while (1) {
		char c;

		// read in minimun value
		printf("Minimum value: ");
		while (scanf("%d", min) != 1) {
			scanf(" %c", &c);
			printf("Invalid input! Please check your input!\n");
			printf("Minimum value: ");
		}

		// read in maximum value
		printf("Maximum value: ");
		while (scanf("%d", max) != 1) {
			scanf(" %c", &c);
			printf("Invalid input! Please check your input!\n");
			printf("Maximum value: ");
		}

		// validate two values
		if (*min > *max) {
			printf("Invalid value! Minimum value is greater than the maximum value.\n");
		} else {
			return;
		}
	}
}


void read_str(char *from, char *to) {
	while (1) {
		printf("Starting name: ");
		scanf("%s", from);
		printf("Ending name: ");
		scanf("%s", to);

		// validate two values
		if (strcmp(from, to) > 0) {
			printf("Invalid value! Starting value is greater than the ending value.\n");
		} else {
			return;
		}
	}
}


void read_bool(bool *b) {
	char c;
	while (1) {
		printf("Scrapped (Y/N): ");
		scanf(" %c", &c);
		if (c == 'y' || c == 'Y') {
			*b = true;
			break;
		} else if (c == 'n' || c == 'N') {
			*b = false;
			break;
		} else {
			printf("Invalid command! Please check your input.\n");
		}
	}
}


void read_double(double *min, double *max) {
	while (1) {
		char c;

		// read in minimun value
		printf("Minimum value: ");
		while (scanf("%lf", min) != 1) {
			scanf(" %c", &c);
			printf("Invalid input! Please check your input!\n");
			printf("Minimum value: ");
		}

		// read in maximum value
		printf("Maximum value: ");
		while (scanf("%lf", max) != 1) {
			scanf(" %c", &c);
			printf("Invalid input! Please check your input!\n");
			printf("Maximum value: ");
		}

		// validate two values
		if (*min > *max) {
			printf("Invalid value! Minimum value is greater than the maximum value.\n");
		} else {
			return;
		}
	}
}
