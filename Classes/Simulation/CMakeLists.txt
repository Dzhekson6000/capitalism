CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Agents")
ADD_SUBDIRECTORY("Managers")

SET(GAME_SRC ${GAME_SRC}
	Classes/Simulation/Message.cpp
	Classes/Simulation/Agent.cpp
	Classes/Simulation/SimulationManager.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Simulation/Message.h
	Classes/Simulation/Agent.h
	Classes/Simulation/SimulationManager.h
	PARENT_SCOPE)
