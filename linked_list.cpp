#include <iostream>
#include "headers/List_t.h"

int main()
{
	List_t list = List_t(5);

	list.push_back(10);
	list.push_back(11);
	list.push_back(12);
	list.push_back(13);
    list.print();

    list.insert(1,20);
    list.print();
    list.reverse();
    list.print();
    list.sort();
    list.print();


	return 0;
}
