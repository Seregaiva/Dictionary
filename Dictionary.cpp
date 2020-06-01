#include "Dictionary.h"

void Dictionary::Loadfile()
{
	string temp,name="in.txt";
	ifstream fin;

	cout << "Enter the file name to download(.txt): ";
	//cin >> name;
	fin.open(name);
	while (!fin.is_open())
	{
		cout << "Incorect input file name!" << endl;
		cout << "Re-enter name? 1-Yes other Exit : ";
		int key;
		cin >> key;
		if (key == 1)
		{
			cout << "Enter the file name to download(.txt): ";
			cin >> name;
			fin.open(name);
		}
		else break;
	}
	if (fin.is_open())
	{
		cout << endl << "Ok!!" << endl;
		while (!fin.eof())
		{
			fin >> temp;
			this->words[temp]++;
		}
	}
}
void Dictionary::Edit()
{
	char key;
	string name;
	system("cls");
	cout << "Search word " << name<<endl;
	cout << "1 - Delete 2 - Edit 3 - Add 0 - Exit : ";
	cin >> key;
	while (true)
	{
		if (key-48==0)
			break;
		if (key - 48 == 1)
		{
			name = Find();
			cout << "Search word " << name << endl;
			if (words.erase(name))
				cout << "Word delete!" << endl;
			else cout << "No such word repeat editor!" << endl;
			system("pause");
			break;

		}
		if (key - 48 == 2)
		{
			name = Find();
			cout << "Search word " << name << endl;
			if (!words.erase(name))
				cout << "No such word repeat editor!" << endl;
			else {
				cout << "Enter Word : ";
				cin >> name;
				words.emplace(name, 1);
			}
			system("pause");
			break;
		}
		if(key-48==3){
			cout << "Enter Word : ";
			cin >> name;
			words.emplace(name, 1);
			cout << "Your word has been added" << endl;
			system("pause");
			break;
		}
		system("cls");
		cout << "1 - Delete 2 - Edit 3 - Add 0 - Exit ";
		cin >> key;
	}
}
void Dictionary::Showfile()
{
	system("cls");
	map<string, int>::iterator it;
	for (it=words.begin();it!=words.end();it++)
		cout << (*it).first << endl;
}
void Dictionary::Save()
{
	ofstream fout;
	fout.open("Dictionary.txt");
	if (!fout.is_open())
		cout << "Incorect input file name!"<<endl;
	map<string, int>::iterator it;
	for (it = words.begin(); it != words.end(); it++)
	fout << (*it).first  << endl;
	
}
string Dictionary::Find()
{
	string temp;
	cout << "Enter a search word : ";
	cin >> temp;
	auto it = this->words.find(temp);
	if (it != this->words.end())
		return it->first;
	else
	{
		while (true)
		{
			cout << "There is no such word" << endl;
			cout << "Re-enter word? 1-Yes other Exit : ";
			char key;
			cin >> key;
			if (key-48 == 1)
			{
				cout << "Enter a search word : ";
				cin >> temp;
				it = this->words.find(temp);
				if (it != this->words.end())
					return it->first;
				system("cls");
			}
			else break;
		}

		return temp="Not word\n";
	}
}