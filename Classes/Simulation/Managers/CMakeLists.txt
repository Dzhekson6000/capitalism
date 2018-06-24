CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Simulation/Managers/AgentsManager.cpp
	Classes/Simulation/Managers/BuildingManager.cpp
	Classes/Simulation/Managers/CompaniesManager.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Simulation/Managers/AgentsManager.h
	Classes/Simulation/Managers/BuildingManager.h
	Classes/Simulation/Managers/CompaniesManager.h
	PARENT_SCOPE)
