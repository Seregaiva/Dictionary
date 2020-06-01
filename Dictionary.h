#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
class Dictionary
{
	map <string, int> words;
public:
	Dictionary() {}
	void Loadfile();
	string Find();
	void Edit();
	void Showfile();
	void Save();
	~Dictionary() {}
};
