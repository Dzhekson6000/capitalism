CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/Building/Building.cpp
	Classes/Model/Map/Building/TypeBuilding.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/Building/Building.h
	Classes/Model/Map/Building/TypeBuilding.h
	PARENT_SCOPE)
