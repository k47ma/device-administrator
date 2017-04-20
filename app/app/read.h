// This is the interface for reading in information from the user
#include <stdbool.h>

// reverse_menu() asks the user to decide whether the list 
//   should be sorted in reversed order
bool reverse_menu();

// read_int(min, max) asks the user for min and max values for searching, 
//   and stores them in min and max
// effects: modifies min and max
// notes: input min <= input max
void read_int(int *min, int *max);

// read_str(from, to) asks the user for the string range for searching,
//   and stores them in from and to
// effects: modifies from and to
// notes: input from <= input to
void read_str(char *from, char *to);

// read_bool(b) asks the user for yes or no, and stores the result in b
// effects: modifies b
void read_bool(bool *b);

// read_double(min, max) asks the user for min and max values for searching, 
//   and stores them in min and max
// effects: modifies min and max
// notes: input min <= input max
void read_double(double *min, double *max);