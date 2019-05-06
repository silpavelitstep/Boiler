#include "test_boiler.h"
#include "boiler.h"
#include <iostream>
using namespace std;

void test_exist()
{
	BoilerList blr;
	const char 
		ps[] = "Pass",
		er[] = "Error";
	cout << "test_menu_exist:"
	     << ((blr.menu() == 1) ? ps:er)
		 << endl;
	cout << "test_add_exist:"
		<< ((blr.add() == 1) ? ps : er)
		<< endl;
	cout << "test_show_exist:"
		<< ((blr.show() == 1) ? ps : er)
		<< endl;

	cout << "test_del_exist:"
		<< ((blr.del() == 1) ? ps : er)
		<< endl;
	cout << "test_clear_exist:"
		<< ((blr.clear() == 1) ? ps : er)
		<< endl;
}




