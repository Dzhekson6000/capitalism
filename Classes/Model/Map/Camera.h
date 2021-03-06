#ifndef CAPITALISM_CAMERA_H
#define CAPITALISM_CAMERA_H

class Camera
{
public:
	/**
	 * Список возможных углов отображения
	 */
	enum class Direction: int
	{
		NorthWest = 0,
		EastNorth = 1,
		SouthEast = 2,
		WestSouth = 3
	};
	
	static Camera* getInstance();
	
	Direction getDirection();
	void setDirection(Direction direction);
	
	void rotationLeft();///< Поворот влево.
	void rotationRight();///< Поворот вправо.
private:
	static Camera* _camera;
	
	Camera();
	~Camera();
	
	Direction _direction;
	
};


#endif //CAPITALISM_CAMERA_H
