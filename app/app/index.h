// This is the interface for the menu module

// load_menu() loads the file from input
// effects: allocates memory (caller must call destroy)
void load_menu();

// new_menu() creates a new menu for the work
// effects: allocates memory(caller must call destroy), and creates new file
void new_menu();

// main_menu(list, dir) takes operation on list and returns a pointer to
//   the modified list
// effects: allocates memory, modifies list, or stores list to file
struct llist *main_menu(struct llist *list, const char *dir);
