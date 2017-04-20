// This is the interface for basic operations with linked list
#include <stdbool.h>

// create() returns the address of an initialized linked list
// effects: allocates memory (caller must call llist_destroy)
struct llist *create(void);

// destroy(list) frees all the memory allocated for list
// effects: frees memory
//          or prints out message is num is not in list
// requires: list is valid
void destroy(struct llist *list);

// length(list) returns the length of list
// requires: list is valid
int length(const struct llist *list);

// print(list) prints out the information stored in list
// effects: prints out message
// requires: list is valid
void print(const struct llist *list);

// create_node(num, type, name, year, month, day, scrap, syear, smonth, sday)
//   returns the address of a new node with the given information
// effects: allocates memory (caller must free)
struct llnode *create_node(int num, const char *type, const char *name,
	double price, int year, int month, int day, bool scrap, int syear, int smonth,
	int sday);

// dupnode(node) returns a duplicate of node
// effects: allocates memory (caller must free)
// requires: node is valid
struct llnode *dupnode(const struct llnode *node);

// print_node(node) prints out the node
// effects: prints out information
// requires: node is not NULL
void print_node(const struct llnode *node);
