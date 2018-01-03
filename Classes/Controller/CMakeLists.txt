CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Loader")

SET(GAME_SRC ${GAME_SRC}
	Classes/Controller/TileImageManager.cpp
	Classes/Controller/FactoryCells.cpp
	Classes/Controller/BuildingController.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Controller/TileImageManager.h
	Classes/Controller/FactoryCells.h
	Classes/Controller/BuildingController.h
	PARENT_SCOPE)
