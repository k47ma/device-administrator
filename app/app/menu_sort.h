// This is the interface for the module of sorting menu

// sort_menu(list, dir) provides a series of operations on sorting list,
//   and returns the list which is finally stored in the file
// effects: modifies memory
// notes: no information will be removed in this menu
struct llist *sort_menu(struct llist *list, const char *dir);
