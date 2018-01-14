CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Map")

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/IsoPoint.cpp
	Classes/Model/Config.cpp
	Classes/Model/Camera.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/IsoPoint.h
	Classes/Model/Config.h
	Classes/Model/Camera.h
	PARENT_SCOPE)
