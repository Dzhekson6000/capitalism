CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)


SET(GAME_SRC ${GAME_SRC}
	Classes/Base/Loader.cpp
	Classes/Base/LoaderWorld.cpp
	Classes/Base/Manager.cpp
	Classes/Base/ManagerWorld.cpp
	Classes/Base/View.cpp
	Classes/Base/ViewWorld.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Base/Loader.h
	Classes/Base/LoaderWorld.h
	Classes/Base/Manager.h
	Classes/Base/ManagerWorld.h
	Classes/Base/View.h
	Classes/Base/ViewWorld.h
	PARENT_SCOPE)
