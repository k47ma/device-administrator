// This is the implementation for searching for required data
#include "search.h"
#include "llist.h"
#include "basic.h"
#include <stdlib.h>
#include <string.h>


struct llnode *lookup(const struct llist *list, int num) {
	// list is empty
	if (list->front == NULL) return NULL;
	
	// list is non-empty
	struct llnode *curnode = list->front;
	while (curnode) {
		if (curnode->num == num) return curnode;
		curnode = curnode->next;
	}
	return NULL;
}


// get_number(node) returns num of node
static int get_number(const struct llnode *node) {
	return node->num;
}

// get_date(node) returns the formatted date of node
static int get_date(const struct llnode *node) {
	int date = node->year * 10000 + node->month * 100 + node->day;
	return date;
}

// get_sdate(node) returns the formatted scraping date of node
static int get_sdate(const struct llnode *node) {
	int sdate = node->syear * 10000 + node->smonth * 100 + node->sday;
	return sdate;
}

// get_type(node) returns the type of node
static char *get_type(const struct llnode *node) {
	return node->type;
}

// get_name(node) returns the name of node
static char *get_name(const struct llnode *node) {
	return node->name;
}

struct llist *int_filter(const struct llist *list, char type, int min, int max) {
	// input is invalid
	if (list == NULL || min > max) return NULL;

	int (*get_item)(const struct llnode *);
	// set the get_item function to be the right type
	if (type == 'n') {
		get_item = get_number;
	} else if (type == 'd') {
		get_item = get_date;
	} else if (type == 's') {
		get_item = get_sdate;
	} else {
		// input is invalid
		return NULL;
	}

	struct llist *new_list = create();

	struct llnode *checknode = list->front;
	struct llnode *curnode = NULL;
	while (checknode) {
		int item = get_item(checknode);
		// checknode satisfies the requirement, 
		//   then add the duplicate of checknode to new_list
		if (item >= min && item <= max) {
			struct llnode *newnode = dupnode(checknode);
			newnode->next = NULL;
			if (curnode == NULL) {
				new_list->front = newnode;
			} else {
				curnode->next = newnode;
			}
			curnode = newnode;
			++new_list->len;
		}
		checknode = checknode->next;
	}
	return new_list;
}


struct llist *str_filter(const struct llist *list, char type, char *from, char *to) {
	// input is invalid
	if (list == NULL || strcmp(from, to) > 0) return NULL;

	char *(*get_item)(const struct llnode *);
	// set the get_item to be the right type
	if (type == 't') {
		get_item = get_type;
	} else if (type == 'n') {
		get_item = get_name;
	} else {
		return NULL;
	}

	struct llist *new_list = create();

	struct llnode *checknode = list->front;
	struct llnode *curnode = NULL;
	while (checknode) {
		char *item = get_item(checknode);
		// checknode satisfies the requirement, 
		//   then add the duplicate of checknode to new_list
		if (strcmp(item, from) >= 0 && strcmp(item, to) <= 0) {
			struct llnode *newnode = dupnode(checknode);
			newnode->next = NULL;
			if (curnode == NULL) {
				new_list->front = newnode;
			} else {
				curnode->next = newnode;
			}
			curnode = newnode;
			++new_list->len;
		}
		checknode = checknode->next;
	}
	return new_list;
}

struct llist *bool_filter(const struct llist *list, bool b) {
	// input is invalid
	if (list == NULL) return NULL;

	struct llist *new_list = create();

	struct llnode *checknode = list->front;
	struct llnode *curnode = NULL;
	while (checknode) {
		// checknode satisfies the requirement, 
		//   then add the duplicate of checknode to new_list
		if (checknode->scrap == b) {
			struct llnode *newnode = dupnode(checknode);
			newnode->next = NULL;
			if (curnode == NULL) {
				new_list->front = newnode;
			} else {
				curnode->next = newnode;
			}
			curnode = newnode;
			++new_list->len;
		}
		checknode = checknode->next;
	}
	return new_list;
}


struct llist *double_filter(const struct llist *list, double min, double max) {
	// input is invalid
	if (list == NULL || min > max) return NULL;

	struct llist *new_list = create();

	struct llnode *checknode = list->front;
	struct llnode *curnode = NULL;
	while (checknode) {
		double price = checknode->price;
		// checknode satisfies the requirement, 
		//   then add the duplicate of checknode to new_list
		if (price >= min && price <= max) {
			struct llnode *newnode = dupnode(checknode);
			newnode->next = NULL;
			if (curnode == NULL) {
				new_list->front = newnode;
			} else {
				curnode->next = newnode;
			}
			curnode = newnode;
			++new_list->len;
		}
		checknode = checknode->next;
	}
	return new_list;
}
