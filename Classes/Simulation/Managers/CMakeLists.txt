CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Simulation/Managers/AgentsManager.cpp
	Classes/Simulation/Managers/BuildingAManager.cpp
	Classes/Simulation/Managers/CompaniesManager.cpp
	Classes/Simulation/Managers/HouseholdManager.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Simulation/Managers/AgentsManager.h
	Classes/Simulation/Managers/BuildingAManager.h
	Classes/Simulation/Managers/CompaniesManager.h
	Classes/Simulation/Managers/HouseholdManager.h
	PARENT_SCOPE)
