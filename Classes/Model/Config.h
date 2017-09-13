#ifndef CAPITALISM_CONFIG_H
#define CAPITALISM_CONFIG_H

#include <string>

class Config
{
public:
	Config();
	~Config();
	
	bool loadConfigFile(const std::string& path);
};


#endif //CAPITALISM_CONFIG_H
