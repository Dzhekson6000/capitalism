CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Building")
ADD_SUBDIRECTORY("Cell")
ADD_SUBDIRECTORY("World")

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/MapObject.cpp
	Classes/Model/Map/IsoPoint.cpp
	Classes/Model/Map/Camera.cpp
	Classes/Model/Map/Types.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/MapObject.h
	Classes/Model/Map/IsoPoint.h
	Classes/Model/Map/Camera.h
	Classes/Model/Map/Types.h
	PARENT_SCOPE)
