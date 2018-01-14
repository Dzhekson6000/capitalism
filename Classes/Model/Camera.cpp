#include "Camera.h"

Camera* Camera::_camera = nullptr;

Camera* Camera::getInstance()
{
	if(_camera== nullptr)
	{
		_camera = new Camera();
	}
	return _camera;
}

Camera::Camera():
_direction(Direction::WestSouth)
{
}

Camera::~Camera()
{
}

Camera::Direction Camera::getDirection()
{
	return _direction;
}

void Camera::setDirection(Camera::Direction direction)
{
	_direction = direction;
}
