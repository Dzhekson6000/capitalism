CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Map")

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Config.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Config.h
	PARENT_SCOPE)
