// This is the implementation for sorting the information
#include "sort.h"
#include "llist.h"
#include "basic.h"
#include <stdlib.h>


// cmp_insert(list, node, cmp, reverse) inserts node into list using cmp function
// effects: modifies list
// requires: both list and node are valid
static void cmp_insert(struct llist *list, struct llnode *node, 
	int(*cmp)(const struct llnode *node1, const struct llnode *node2),
	bool reverse) {
	struct llnode *curnode = list->front;
	struct llnode *prevnode = NULL;
	// find the correct place for node
	if (reverse) {
		while (curnode && cmp(node, curnode) < 0) {
			prevnode = curnode;
			curnode = curnode->next;
		}
	} else {
		while (curnode && cmp(node, curnode) > 0) {
			prevnode = curnode;
			curnode = curnode->next;
		}
	}

	if (prevnode == NULL) {
		// insert the node at the first entry
		node->next = list->front;
		list->front = node;
	} else {
		// insert the node between prevnode and curnode
		node->next = curnode;
		prevnode->next = node;
	}
	++list->len;
}


struct llist *sort(const struct llist *list, 
	int(*cmp)(const struct llnode *node1, const struct llnode *node2), 
	bool reverse) {
	// list is invald
	if (list == NULL) return NULL;

	struct llist *new_list = create();
	struct llnode *curnode = list->front;
	while (curnode) {
		struct llnode *curdup = dupnode(curnode);
		cmp_insert(new_list, curdup, cmp, reverse);
		curnode = curnode->next;
	}
	return new_list;
}
