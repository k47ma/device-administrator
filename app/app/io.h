// This is the interface for the module of storing the information in list to file

// store(list, file) stores the information in list to file
// effects: modifies file
// requires: list is valid
// notes: store will overwrite whatever in the original file
void store(const struct llist *list, const char *file);

// parse(file) returns a pointer to a new list with all the information from file
// effects: allocates information
// requires: file is a valid file
struct llist *parse(const char *file);
