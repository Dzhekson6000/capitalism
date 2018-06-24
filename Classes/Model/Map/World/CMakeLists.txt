CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/World/GroupObject.cpp
	Classes/Model/Map/World/MapCity.cpp
	Classes/Model/Map/World/World.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/World/GroupObject.h
	Classes/Model/Map/World/MapCity.h
	Classes/Model/Map/World/World.h
	PARENT_SCOPE)
