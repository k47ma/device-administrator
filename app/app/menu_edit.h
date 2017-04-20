// This is the interface for the edit menu module

// modify_menu(list, dir) modifies the list and stores any change to dir, and returns
//   the new list
// effects: allocates memory (caller must free), frees memory, or modifies memory
void modify_menu(struct llist *list, const char *dir);

// add_menu(list, dir) adds a new item to the list and stores it to dir file
// effects: allocates memory (caller must free)
void add_menu(struct llist *list, const char *dir);

// remove_menu(list, dir) removes an item from the list 
//    and stores the new list to dir file
// effects: frees memory, and stores information
void remove_menu(struct llist *list, const char *dir);

// edit_menu(list, dir) edits the specific entry
// effects: mofifies memory
void edit_menu(struct llist *list, const char *dir);