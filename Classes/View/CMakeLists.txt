CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY("Ui")

SET(GAME_SRC ${GAME_SRC}
	Classes/View/Scroller.cpp
	Classes/View/IsoScroller.cpp
	Classes/View/ViewManager.cpp
	PARENT_SCOPE
	)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/View/Scroller.h
	Classes/View/IsoScroller.h
	Classes/View/ViewManager.h
	PARENT_SCOPE)
