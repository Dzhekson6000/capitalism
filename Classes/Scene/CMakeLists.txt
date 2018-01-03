CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Scene/MenuScene.cpp
	Classes/Scene/GameScene.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Scene/MenuScene.h
	Classes/Scene/GameScene.h
	PARENT_SCOPE)
