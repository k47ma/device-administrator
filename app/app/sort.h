// This is the interface for sorting the information
#include <stdbool.h>

// sort(list, cmp, reverse) returns a pointer to a duplicate of list with all the
//   nodes sorted by cmp function using insertion sort
// effects: allocates memory (caller must call destroy)
// requires: list is valid
struct llist *sort(const struct llist *list, 
	int (*cmp)(const struct llnode *node1, const struct llnode *node2), 
	bool reverse);
