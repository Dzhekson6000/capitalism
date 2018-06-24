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

void Camera::rotationLeft()
{
	int direction = static_cast<int>(_direction);
	if(direction==0)
	{
		direction = 3;
	}
	else
	{
		--direction;
	}
	_direction = static_cast<Direction>(direction);
}

void Camera::rotationRight()
{
	int direction = static_cast<int>(_direction);
	if(direction==3)
	{
		direction = 0;
	}
	else
	{
		++direction;
	}
	_direction = static_cast<Direction>(direction);
}
