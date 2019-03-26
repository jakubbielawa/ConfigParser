#include "cfgparser.h"

#include <iostream>
#include <fstream>
#include <algorithm>

void parseconfig(std::string filename, std::map<std::string, std::string>* output)
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
			if (line[0] == '#' || line.empty())
			{
				continue;
			}

			auto delimiterPos = line.find('=');
			auto name = line.substr(0, delimiterPos);
			auto value = line.substr(delimiterPos + 1);
			(*output)[name] = value;
		}
	}
	else
	{
		std::cerr << "Could not open the config file!" << std::endl;
	}
}