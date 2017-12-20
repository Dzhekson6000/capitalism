#ifndef CAPITALISM_LOADERCONFIG_H
#define CAPITALISM_LOADERCONFIG_H

#include <string>

class LoaderConfig
{
public:
	/**
	 * @brief загрузка файлов конфигурации
	 * @param path путь до конфига
	 * @return статус выполнения
	 */
	bool loadConfigFile(const std::string& path);
};


#endif //CAPITALISM_LOADERCONFIG_H
