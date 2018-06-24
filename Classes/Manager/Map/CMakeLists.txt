CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Manager/Map/BuildingManager.cpp
	Classes/Manager/Map/LayerManager.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Manager/Map/BuildingManager.h
	Classes/Manager/Map/LayerManager.h
	PARENT_SCOPE
	)
