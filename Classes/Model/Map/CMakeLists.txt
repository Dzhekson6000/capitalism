CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Cells")

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/Cell.cpp
	Classes/Model/Map/MapObject.cpp
	Classes/Model/Map/World.cpp
	Classes/Model/Map/MapCity.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/Cell.h
	Classes/Model/Map/MapObject.h
	Classes/Model/Map/World.h
	Classes/Model/Map/MapCity.h
	PARENT_SCOPE)
