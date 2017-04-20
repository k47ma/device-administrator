// This is the interface of linked list module
#include <stdbool.h>

struct llist {
	int len;
	struct llnode *front;
};

struct llnode {
	int num;
	char *type;
	char *name;
	double price;
	int year;
	int month;
	int day;
	bool scrap;
	int syear;
	int smonth;
	int sday;
	struct llnode *next;
};
