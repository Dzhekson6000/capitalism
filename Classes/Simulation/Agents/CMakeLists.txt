CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Building")
ADD_SUBDIRECTORY("Market")

SET(GAME_SRC ${GAME_SRC}
	Classes/Simulation/Agents/Company.cpp
	Classes/Simulation/Agents/Household.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Simulation/Agents/Company.h
	Classes/Simulation/Agents/Household.h
	PARENT_SCOPE)
