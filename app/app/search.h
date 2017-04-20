// This is the interface for searching for required data
#include <stdbool.h>

// lookup(list, num) returns the address of the node which number is num, 
//   and NULL if there is no node with number num
// requires: list is valid
struct llnode *lookup(const struct llist *list, int num);

// int_filter(list, type, min, max) returns a pointer to a new list with all the nodes
//   within the range of min and max
// requires: list is valid
//           min <= max
//           type is one of 'n'(number), 'p'(price), 'd'(date), and 's'(scraping date)
// effects: allocates memory (caller must free)
struct llist *int_filter(const struct llist *list, char type, int min, int max);

// str_filter(list, type, min, max) returns a pointer to a new list with all the nodes
//   within the range of min and max
// requires: list is valid
//           min <= max
//           type is one of 't'(type name) and 'n'(name)
struct llist *str_filter(const struct llist *list, char type, char *from, char *to);

// bool_filter(list, b) returns a pointer to a new list with all the nodes with b
// requires: list is valid
struct llist *bool_filter(const struct llist *list, bool b);

// double_filter(list, min, max) returns a pointer to a new list with all the nodes
//   within the range of min and max
// requires: list is valid
//           min <= max
// effects: allocates memory (caller must free)
struct llist *double_filter(const struct llist *list, double min, double max);
