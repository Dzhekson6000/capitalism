CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Controller/Loader/LoaderMap.cpp
	Classes/Controller/Loader/LoaderConfig.cpp
	Classes/Controller/Loader/LoaderMapObject.cpp
	Classes/Controller/Loader/LoaderSpriteSheets.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Controller/Loader/LoaderMap.h
	Classes/Controller/Loader/LoaderConfig.h
	Classes/Controller/Loader/LoaderMapObject.h
	Classes/Controller/Loader/LoaderSpriteSheets.h
	PARENT_SCOPE)

