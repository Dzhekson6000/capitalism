#ifndef CAPITALISM_ISOTOOLS_H
#define CAPITALISM_ISOTOOLS_H


class IsoTools
{
public:
	/**
	 * @brief конвертация изометрических координат в экранные
	 * @param isoX изометрический X
	 * @param isoY изометрический Y
	 * @param x экранный X
	 * @param y экранный Y
	 */
	static void isoToScreen(const float isoX, const float isoY, float &x, float &y);
	
	/**
	 * @brief конвертация экранных координат в изометрические
	 * @param x экранный X
	 * @param y экранный Y
	 * @param isoX изометрический X
	 * @param isoY изометрический Y
	 */
	static void screenToIso(const float x, const float y, float &isoX, float &isoY);
	
	/**
	 * Возвращает количество клеток общей длиной в size
	 * @param size расстояние
	 * @return количество клеток
	 */
	static int getCellOfNumber(const float size);
	
	/**
	 * Возвращает расстояние занимаемое клетками
	 * @param cell количество клеток
	 * @return расстояние
	 */
	static float getNumberOfCell(const int cell);
};


#endif //CAPITALISM_ISOTOOLS_H
