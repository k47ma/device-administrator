// This is the implementation for comparing function module

// cmp_num(node1, node2) returns 1 if the number of node1 is greater than the number
//   of node2, returns -1 if the number of node1 is smaller than the number of node2,
//   and returns 0 if the numbers are equal
// requires: node1 and node2 are valid nodes
int cmp_num(const struct llnode *node1, const struct llnode *node2);

// cmp_type(node1, node2) returns 1 if the type of node1 is greater than the type
//   of node2, returns -1 if the type of node1 is smaller than the type of node2,
//   and returns 0 if the types are equal
// requires: node1 and node2 are valid nodes
int cmp_type(const struct llnode *node1, const struct llnode *node2);

// cmp_name(node1, node2) returns 1 if the name of node1 is greater than the type
//   of node2, returns -1 if the name of node1 is smaller than the name of node2,
//   and returns 0 if the names are equal
// requires: node1 and node2 are valid nodes
int cmp_name(const struct llnode *node1, const struct llnode *node2);

// cmp_price(node1, node2) returns 1 if the price of node1 is greater than the price
//   of node2, returns -1 if the price of node1 is smaller than the price of node2,
//   and returns 0 if the prices are equal
// requires: node1 and node2 are valid nodes
int cmp_price(const struct llnode *node1, const struct llnode *node2);

// cmp_date(node1, node2) returns 1 if the date of node1 is greater than the date
//   of node2, returns -1 if the date of node1 is smaller than the date of node2,
//   and returns 0 if the dates are equal
// requires: node1 and node2 are valid nodes
int cmp_date(const struct llnode *node1, const struct llnode *node2);

// cmp_sdate(node1, node2) returns 1 if the scrapping date of node1 is greater than
//   the scrapping date of node2, returns -1 if the scrapping date of node1 is smaller
//   than the date of node2, and returns 0 if the scrapping dates are equal
// requires: node1 and node2 are valid nodes
int cmp_sdate(const struct llnode *node1, const struct llnode *node2);

// cmp_scrap(node1, node2) returns 1 if the scrapping status of node1 is greater than
//   the scrapping date of node2, returns -1 if the scrapping status of node1 if smaller
//   than the scrapping status of node2, and returns 0 if the scrapping status are equal
// requires: node1 and node2 are valid nodes
int cmp_scrap(const struct llnode *node1, const struct llnode *node2);
