// This is the implementation for comparing function module
#include "cmpfn.h"
#include "llist.h"
#include <string.h>


int cmp_num(const struct llnode *node1, const struct llnode *node2) {
	if (node1->num > node2->num) {
		return 1;
	} else if (node1->num < node2->num) {
		return -1;
	} else {
		return 0;
	}
}


int cmp_type(const struct llnode *node1, const struct llnode *node2) {
	return strcmp(node1->type, node2->type);
}


int cmp_name(const struct llnode *node1, const struct llnode *node2) {
	return strcmp(node1->name, node2->name);
}


int cmp_price(const struct llnode *node1, const struct llnode *node2) {
	if (node1->price > node2->price) {
		return 1;
	} else if (node1->price < node2->price) {
		return -1;
	} else {
		return 0;
	}
}


int cmp_date(const struct llnode *node1, const struct llnode *node2) {
	int date1 = node1->year * 10000 + node1->month * 100 + node1->day;
	int date2 = node2->year * 10000 + node2->month * 100 + node2->day;
	if (date1 > date2) {
		return 1;
	} else if (date1 < date2) {
		return -1;
	} else {
		return 0;
	}
}


int cmp_sdate(const struct llnode *node1, const struct llnode *node2) {
	int sdate1 = node1->syear * 10000 + node2->smonth * 100 + node1->sday;
	int sdate2 = node2->syear * 10000 + node2->smonth * 100 + node2->sday;
	if (sdate1 > sdate2) {
		return 1;
	} else if (sdate1 < sdate2) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_scrap(const struct llnode *node1, const struct llnode *node2) {
	if (node1->scrap > node2->scrap) {
		return 1;
	} else if (node1->scrap < node2->scrap) {
		return -1;
	} else {
		return 0;
	}
}