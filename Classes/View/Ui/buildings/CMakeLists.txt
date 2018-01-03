CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/View/Ui/buildings/Button.cpp
	Classes/View/Ui/buildings/ItemBuilding.cpp
	Classes/View/Ui/buildings/Buildings.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/View/Ui/buildings/Button.h
	Classes/View/Ui/buildings/ItemBuilding.h
	Classes/View/Ui/buildings/Buildings.h
	PARENT_SCOPE)
