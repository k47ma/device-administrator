// This is the implementation for date module
#include "date.h"

bool valid_date(int date) {
	int year = date / 10000;
	int month = date % 10000 / 100;
	int day = date % 100;
	return year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31;
}
