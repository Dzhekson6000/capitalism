#ifndef CAPITALISM_LOADER_H
#define CAPITALISM_LOADER_H

#include <string>

//TODO: нужно реализовать прогресс загрузки

/**
 * Базовый класс загрузчика
 */
class Loader
{
public:
	Loader();
	virtual ~Loader();
	
	/**
	 * Метод загрузки
	 * @param path путь
	 * @return true - если успешно
	 */
	virtual bool load(const std::string &path);
};


#endif //CAPITALISM_LOADER_H
