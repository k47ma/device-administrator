// This is the interface for the module of edting linked list
#include <stdbool.h>

// insert_item(list, node) adds node to list, and returns true if insertion 
//   is successful
// effects: allocates memory (caller must free)
// requires: list is valid
bool insert_item(struct llist *list, struct llnode *node);

// remove_item(list, num) removes the item with num from list, and returns true if 
//   removing is successful
// effects: frees memory
// requires: list is valid
bool remove_item(struct llist *list, int num);

// edit(node, num, type, name, price, year, month, day, scrap, 
//   syear, smonth, sday) modifies node to be the given information,
//   and returns true if modifying is successful
// effects: modifies memory
// requires: node is valid
bool edit(struct llnode *node, int num, const char *type,
	const char *name, double price, int year, int month, int day, bool scrap,
	int syear, int smonth, int sday);
