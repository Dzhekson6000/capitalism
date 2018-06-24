CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Map")

SET(GAME_SRC ${GAME_SRC}
	Classes/Loader/LoaderConfig.cpp
	Classes/Loader/LoaderSpriteSheets.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Loader/LoaderConfig.h
	Classes/Loader/LoaderSpriteSheets.h
	PARENT_SCOPE)

