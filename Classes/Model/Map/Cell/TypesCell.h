#ifndef CAPITALISM_TYPESCELL_H
#define CAPITALISM_TYPESCELL_H

#include <string>
#include <unordered_map>

/**
 * Класс работующий с типами клеток
 */
class TypesCell
{
public:
	/**
	 * @brief возвращает имя по номеру типа
	 * @param type
	 * @return
	 */
	static std::string getNameCellOfType(const int type);
	
	/**
	 * @brief возвращает имя по пикселю
	 * @param pixel
	 * @return
	 */
	static std::string getNameCellOfPixel(const unsigned char* pixel);

private:
	/**
	 * @brief имена клетки
	 */
	static const std::unordered_map<int, std::string> _cellsName;
};


#endif //CAPITALISM_TYPESCELL_H
