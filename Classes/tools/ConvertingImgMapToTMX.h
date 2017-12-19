#ifndef CAPITALISM_CONVERIMGMAPTOTMX_H
#define CAPITALISM_CONVERIMGMAPTOTMX_H

#include <string>

/**
 * Класс для конвертирования карты из изображения в более подходящий для этого TMX
 *
 * http://doc.mapeditor.org/en/latest/reference/tmx-map-format/ - описание формата TMX
 */

class ConvertingImgMapToTMX
{
public:
	/**
	 * @brief Конвертирует
	 * @param pathIn путь к изображение
	 * @param pathOut путь и имя файла куда нужно сохранить
	 * @return true = успешно, false = ошибка
	 */
	static bool converting(const std::string &pathIn, const std::string &pathOut);
private:
	static bool saveTMXFile(const std::string &pathOut, const std::string &layer, int width, int height);
};


#endif //CAPITALISM_CONVERIMGMAPTOTMX_H
