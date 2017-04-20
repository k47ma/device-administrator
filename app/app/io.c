// This is the implememtation for the module of storing the information in list to file
#define _CRT_SECURE_NO_WARNINGS
#include "io.h"
#include "llist.h"
#include "basic.h"
#include <stdlib.h>
#include <stdio.h>


void store(const struct llist *list, const char *file) {
	// list is invalid
	if (list == NULL) {
		printf("Invalid list!\n");
		return;
	}

	// open the file for storing information
	FILE *fp;
	fp = fopen(file, "w+");

	// file is invalid
	if (fp == NULL) {
		printf("Invalid file name!\n");
		return;
	}

	struct llnode *curnode = list->front;
	while (curnode) {
		int date = curnode->year * 10000 + curnode->month * 100 + curnode->day;
		int sdate = curnode->syear * 10000 + curnode->smonth * 100 + curnode->sday;
		fprintf(fp, "%d,%s,%s,%lf,%d,%d,%d\n", curnode->num, curnode->type, 
			curnode->name, curnode->price, date, curnode->scrap, sdate);
		curnode = curnode->next;
	}
	// close the file after writing
	fclose(fp);
}

struct llist *parse(const char *file) {
	FILE *fp;
	fp = fopen(file, "r");

	// file is invalid
	if (fp == NULL) {
		printf("Invalid file name!\n");
		return NULL;
	}

	struct llist *list = create();
	struct llnode *curnode = NULL;
	int num, date, sdate, scrap;
	char c;
	char type[1024];
	char name[1024];
	double price;
	while (fscanf(fp, "%d", &num) == 1) {
		// read in information from file
		fscanf(fp, "%c", &c);

		// read in type name
		int len = 0;
		while (fscanf(fp, "%c", &c) == 1 && c != ',') {
			type[len] = c;
			++len;
		}
		type[len] = '\0';

		// read in name
		len = 0;
		while (fscanf(fp, "%c", &c) == 1 && c != ',') {
			name[len] = c;
			++len;
		}
		name[len] = '\0';

		// read in other information
		fscanf(fp, "%lf", &price);
		fscanf(fp, "%c", &c);
		fscanf(fp, "%d", &date);
		fscanf(fp, "%c", &c);
		fscanf(fp, "%d", &scrap);
		fscanf(fp, "%c", &c);
		fscanf(fp, "%d", &sdate);
		fscanf(fp, "%c", &c);

		// create a new node
		struct llnode *newnode = create_node(num, type, name, price, date / 10000, 
			date % 10000 / 100, date % 100, scrap, sdate / 10000, sdate % 1000 / 100, 
			sdate % 100);
		// adds the new node to the list
		if (curnode == NULL) {
			list->front = newnode;
			curnode = newnode;
		} else {
			curnode->next = newnode;
			curnode = newnode;
		}
		++list->len;
	}
	fclose(fp);
	return list;
}
