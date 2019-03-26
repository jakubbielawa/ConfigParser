#include <iostream>
#include <map>
#include <string>

#include "cfgparser.h"

using namespace std;

int main()
{
	map<string, string> config;
	parseconfig("sample.ini", &config);

	map<string, string>::iterator it = config.begin();
	while (it != config.end())
	{
		cout << "[" << it->first << "] = " << it->second << endl;
		it++;
	}

	cin.get();
}