#include "boiler.h"
#include <iostream>
using namespace std;
int BoilerList::menu()
{
	char select = ' ';
	while (true)
	{
		system("CLS");
		cout << "Menu:\n"
			<< "Select and put symbol:\n"
			<< "'a': add a boiler,\n"
			<< "'s': show all boilers\n"
			<< "'d': delete any boiler\n"
			<< "'c': delete all boilers\n"
			<< "'q' for exit.\n> ";
		cin >> select;
		switch (select)
		{
		case 'a':  add(); break;
		case 's': show(); break;
		case 'd':  del(); break;
		case 'c':clear(); break;
		case 'q':return 1;//to close menu
		
		}
	}
	return 1;
}
int BoilerList::add()
{
	if (countBoilers == 19)
		cout << "Can't add. List is full!\n";
	else
	{
		pBoiler[countBoilers++] = new Boiler();
	}
	return 1;
}
int BoilerList::show()
{
	cout << "Boiler list:\n";
	if (!countBoilers)
		cout << "List is empty!\n";
	for (int i = 0; i < countBoilers; i++)
	{
		cout << i << ": ";
		pBoiler[i]->show();
	}
	system("pause");
	return 1;
}
int BoilerList::del()
{
	int index;
	cout << "Set index: ";
	cin >> index;
	//index from 0 to countBoilers-1
	if (index<0 || countBoilers == 0 || index>countBoilers - 1)
		return 1;
	delete pBoiler[index];
	//if index==countBoiler то сдвиг массива не нужен
	for (int i=index;i<countBoilers-1;i++)
	{
		pBoiler[i] = pBoiler[i + 1];
	}
	countBoilers--;
	return 1;
}
int BoilerList::clear()
{
	for (int i = 0; i < countBoilers; i++)
	{
		delete pBoiler[i];
	}
	countBoilers = 0;
	return 1;
}
BoilerList::~BoilerList()
{
	clear();
}
Boiler::Boiler()
{
	cin.getline(vender, 20);//free buffer
	cout << "New boiler:\n";
	cout << "set a vender: ";
	cin.getline(vender,20);
	cout << "set litres in second: ";
	cin >> litresInSec;
	cout << "set power in watt: ";
	cin >> power;
}
Boiler::~Boiler()
{
	//for check free memory
	//cout << "Boiler dest\n";
}
inline void Boiler::show()
{
	cout << vender << '\t' << litresInSec << '\t' << power << endl;
}

