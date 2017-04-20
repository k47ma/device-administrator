// This is the inplementation for the module of editing linked list
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "edit.h"
#include "llist.h"
#include "search.h"
#include "basic.h"


bool insert_item(struct llist *list, struct llnode *node) {
	// node is invalid
	if (node == NULL) {
		printf("The given node is invalid.\n");
		return false;
	}

	// num has existed in list
	if (lookup(list, node->num) != NULL) {
		printf("The item number has existed in the list. Please use another number.\n");
		return false;
	}

	// list is empty
	if (list->front == NULL) {
		list->front = node;
	} else {
		struct llnode *curnode = list->front;
		struct llnode *prevnode = NULL;
		// find the correct position
		while (curnode && node->num > curnode->num) {
			prevnode = curnode;
			curnode = curnode->next;
		}
		if (prevnode == NULL) {
			list->front = node;
			node->next = curnode;
		} else {
			node->next = curnode;
			prevnode->next = node;
		}
	}
	++list->len;
	return true;
}


bool remove_item(struct llist *list, int num) {
	struct llnode *curnode = list->front;
	struct llnode *prevnode = NULL;
	while (curnode) {
		if (curnode->num == num) {
			if (prevnode == NULL) {
				list->front = curnode->next;
			} else {
				prevnode->next = curnode->next;
			}
			free(curnode->type);
			free(curnode->name);
			free(curnode);
			--list->len;
			return true;
		}
		prevnode = curnode;
		curnode = curnode->next;
	}
	printf("The number does not exist! Please check your input.\n");
	return false;
}

bool edit(struct llnode *node, int num, const char *type,
	const char *name, double price, int year, int month, int day, bool scrap,
	int syear, int smonth, int sday) {
	node->num = num;
	free(node->type);
	free(node->name);
	node->type = _strdup(type);
	node->name = _strdup(name);
	node->price = price;
	node->year = year;
	node->month = month;
	node->day = day;
	node->scrap = scrap;
	node->syear = syear;
	node->smonth = smonth;
	node->sday = sday;
	return true;
}
