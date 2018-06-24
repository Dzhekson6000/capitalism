CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Loader/Map/LoaderMap.cpp
	Classes/Loader/Map/LoaderCompany.cpp
	Classes/Loader/Map/LoaderMapObject.cpp
	Classes/Loader/Map/LoaderTypeBuildings.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Loader/Map/LoaderMap.h
	Classes/Loader/Map/LoaderCompany.h
	Classes/Loader/Map/LoaderMapObject.h
	Classes/Loader/Map/LoaderTypeBuildings.h
	PARENT_SCOPE
	)

