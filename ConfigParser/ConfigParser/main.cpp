#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#include "cfgparser.h"

using namespace std;

int main()
{
	map<string, string> config;
	parseconfig("sample.ini", &config);

	// STL iterator
	map<string, string>::iterator it = config.begin();
	while (it != config.end())
	{
		cout << "[" << it->first << "] = " << it->second << endl;
		it++;
	}

	cout << endl;

	// range based FOR loop
	for (pair<string, string> entry : config)
	{
		cout << "[" << entry.first << "] = " << entry.second << endl;
	}

	cout << endl;

	// for_each and a simple lambda function
	for_each(config.begin(), config.end(), 
		[](pair<string, string> entry) {
			cout << "[" << entry.first << "] = " << entry.second << endl;
	});

	cin.get();
}