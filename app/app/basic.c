// This is the implememtation for basic operations with linked list
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "basic.h"
#include "llist.h"


struct llist *create(void) {
	struct llist *new_list = malloc(sizeof(struct llist));
	new_list->len = 0;
	new_list->front = NULL;
	return new_list;
}


void destroy(struct llist *list) {
	if (list == NULL) return;
	struct llnode *curnode = list->front;
	while (curnode) {
		struct llnode *nextnode = curnode->next;
		free(curnode->type);
		free(curnode->name);
		free(curnode);
		curnode = nextnode;
	}
	free(list);
}


int length(const struct llist *list) {
	return list->len;
}


void print(const struct llist *list) {
	int width = 105;

	// print out the menu bar
	for (int i = 0; i < width; ++i) {
		printf("-");
	}
	printf("\n");
	printf("|  Number   |");
	for (int i = 0; i < 4; ++i) {
		printf(" ");
	}
	printf("Type");
	for (int i = 0; i < 4; ++i) {
		printf(" ");
	}
	printf("|");
	for (int i = 0; i < 14; ++i) {
		printf(" ");
	}
	printf("Name");
	for (int i = 0; i < 14; ++i) {
		printf(" ");
	}
	printf("|   Price   |    Date    | Scrap | Scrap Date |\n");
	for (int i = 0; i < width; ++i) {
		printf("-");
	}
	printf("\n");

	if (list == NULL) return;

	// print out the content
	struct llnode *curnode = list->front;
	while (curnode) {
		char scraped[6];
		if (curnode->scrap) {
			strcpy(scraped, "True");
		} else {
			strcpy(scraped, "False");
		}
		printf("| %09d | %-10s | %-30s | %-9.2lf | %04d.%02d.%02d | %-05s | %04d.%02d.%02d |\n",
			curnode->num, curnode->type, curnode->name, curnode->price,
			curnode->year, curnode->month, curnode->day, scraped,
			curnode->syear, curnode->smonth, curnode->sday);
		for (int i = 0; i < width; ++i) {
			printf("-");
		}
		printf("\n");
		curnode = curnode->next;
	}

	printf("%d item(s) in total.\n", list->len);
}


struct llnode *create_node(int num, const char *type, const char *name,
	double price, int year, int month, int day, bool scrap, int syear, int smonth, 
	int sday) {
	struct llnode *newnode = malloc(sizeof(struct llnode));
	newnode->num = num;
	newnode->type = _strdup(type);
	newnode->name = _strdup(name);
	newnode->price = price;
	newnode->year = year;
	newnode->month = month;
	newnode->day = day;
	newnode->scrap = scrap;
	newnode->syear = syear;
	newnode->smonth = smonth;
	newnode->sday = sday;
	newnode->next = NULL;
	return newnode;
}


struct llnode *dupnode(const struct llnode *node) {
	if (node == NULL) return NULL;
	struct llnode *dup = malloc(sizeof(struct llnode));
	dup->num = node->num;
	dup->type = _strdup(node->type);
	dup->name = _strdup(node->name);
	dup->price = node->price;
	dup->year = node->year;
	dup->month = node->month;
	dup->day = node->day;
	dup->scrap = node->scrap;
	dup->syear = node->syear;
	dup->smonth = node->smonth;
	dup->sday = node->sday;
	dup->next = node->next;
	return dup;
}

void print_node(const struct llnode *node) {
	if (node == NULL) {
		printf("Invalid node\n");
		return;
	}
	struct llist *print_list = create();
	struct llnode *print_node = dupnode(node);
	print_list->front = print_node;
	++print_list->len;
	print_node->next = NULL;
	print(print_list);
	destroy(print_list);
}