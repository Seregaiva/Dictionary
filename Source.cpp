#include "Dictionary.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int key;
	string temp = "Not word\n";
	Dictionary dic;
	dic.Loadfile();
	do
	{
		
		cout << "1 - Show Dictionary "<<endl;
		cout << "2 - Edit Dictionary" << endl;
		cout << "3 - Find Word" << endl;
		cout << "4 - Save Dictionary (default Dicitionary.txt)" << endl;
		cout << "Other Exit : ";
		cin >> key;
		if (key == 1)
		{
			dic.Showfile();
			system("pause");
		}
		if (key == 2)dic.Edit();
		if (key == 3)
		{
			string name = dic.Find();
			if (temp.find(name))
				cout <<"There is such a word in the dictionary : "<< name<<endl;
			else cout << temp;
			system("pause");
  		}
		if (key == 4)dic.Save();
		cin.ignore(key, '\n');
		system("cls");
		
	} while (key==1||key==2||key==3||key==4);
}
