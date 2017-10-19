#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/
CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(APP_NAME capitalism)
PROJECT(${APP_NAME})

SET(COCOS2D_ROOT ${CMAKE_SOURCE_DIR}/cocos2d)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${COCOS2D_ROOT}/cmake/Modules/")
INCLUDE(CocosBuildHelpers)

# Some macro definitions
IF(WINDOWS)
	IF(BUILD_SHARED_LIBS)
		ADD_DEFINITIONS(-D_USRDLL -D_EXPORT_DLL_ -D_USEGUIDLL -D_USREXDLL -D_USRSTUDIODLL)
	ELSE()
		ADD_DEFINITIONS(-DCC_STATIC)
	ENDIF()

	ADD_DEFINITIONS(-DCOCOS2DXWIN32_EXPORTS -D_WINDOWS -DWIN32 -D_WIN32)
	SET(PLATFORM_FOLDER win32)
ELSEIF(MACOSX OR APPLE)
	ADD_DEFINITIONS(-DCC_TARGET_OS_MAC)
	ADD_DEFINITIONS(-DUSE_FILE32API)
	SET(PLATFORM_FOLDER mac)
ELSEIF(LINUX)
	ADD_DEFINITIONS(-DLINUX)
	SET(PLATFORM_FOLDER linux)
ELSEIF(ANDROID)
	ADD_DEFINITIONS(-DUSE_FILE32API)
	SET(PLATFORM_FOLDER android)
ELSE()
	MESSAGE(FATAL_ERROR "Unsupported platform, CMake will exit")
ENDIF()

# Compiler options
IF(MSVC)
	IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
		SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrt /NODEFAULTLIB:libcmt")
	ELSE()
		SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libcmt")
	ENDIF()
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS
			-wd4251 -wd4244 -wd4334 -wd4005 -wd4820 -wd4710
			-wd4514 -wd4056 -wd4996 -wd4099)
ELSE()
	IF(CMAKE_BUILD_TYPE MATCHES Debug)
		ADD_DEFINITIONS(-DCOCOS2D_DEBUG=1)
	ENDIF()

	IF(NOT (CMAKE_CXX_COMPILER MATCHES clang AND CMAKE_C_COMPILER MATCHES clang))
		MESSAGE(FATAL_ERROR "Please, generate cmake file witch -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++")
	ENDIF()
	#set(CMAKE_C_COMPILER "/usr/bin/clang" CACHE string "clang compiler" FORCE)
	#set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE string "clang compiler" FORCE)

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
	set(LIBRARIES ${LIBRARIES} c++experimental)

	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g3 -O0")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g0 -O3")

	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -g3 -O0")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g0 -O3")
ENDIF(MSVC)

SET(PLATFORM_SPECIFIC_SRC)
SET(PLATFORM_SPECIFIC_HEADERS)

IF(MACOSX OR APPLE)
	SET(PLATFORM_SPECIFIC_SRC
		proj.ios_mac/mac/main.cpp
		)
ELSEIF(LINUX)
	SET(PLATFORM_SPECIFIC_SRC
		proj.linux/main.cpp
		)
ELSEIF(WIN32)
	SET(PLATFORM_SPECIFIC_SRC
		proj.win32/main.cpp
		)
	SET(PLATFORM_SPECIFIC_HEADERS
		proj.win32/main.h
		proj.win32/resource.h
		)
ELSEIF(ANDROID)
	SET(PLATFORM_SPECIFIC_SRC
		proj.android-studio/app/jni/hellocpp/main.cpp
		)
ENDIF()

INCLUDE_DIRECTORIES(
		/usr/local/include/GLFW
		/usr/include/GLFW
		${COCOS2D_ROOT}
		${COCOS2D_ROOT}/cocos
		${COCOS2D_ROOT}/external
		${COCOS2D_ROOT}/cocos/platform
		${COCOS2D_ROOT}/cocos/audio/include/
		Classes
)
IF(WIN32)
	INCLUDE_DIRECTORIES(
			${COCOS2D_ROOT}/external/glfw3/include/win32
			${COCOS2D_ROOT}/external/win32-specific/gles/include/OGLES
	)
ENDIF(WIN32)

SET(GAME_SRC
	Classes/AppDelegate.cpp
	Classes/Scene/MenuScene.cpp
	Classes/Scene/GameScene.cpp
	${PLATFORM_SPECIFIC_SRC}
	Classes/View/Scroller.cpp
	Classes/Model/IsoPoint.cpp
	Classes/Controller/LoaderMap.cpp
	Classes/Model/Config.cpp
	Classes/Controller/TileImageManager.cpp
	Classes/Model/Map/Cell.cpp
	Classes/Controller/FactoryCells.cpp
	Classes/Model/Map/Cells/RoadCell.cpp
	Classes/Model/Map/Cells/RailRoadCell.cpp
	Classes/Model/Map/Cells/ParkCell.cpp
	Classes/Model/Map/MapObject.cpp
	Classes/View/Ui/Button.cpp
	Classes/View/Ui/ItemBuilding.cpp
	Classes/View/Ui/Buildings.cpp
	Classes/Model/Map/World.cpp
	Classes/Model/Map/MapCity.cpp
	Classes/Controller/LoaderConfig.cpp
	Classes/Controller/BuildingController.cpp
	Classes/Controller/LoaderMapObject.cpp Classes/View/Ui/SpritesHeetLoader.cpp Classes/View/Ui/SpritesHeetLoader.h)

SET(GAME_HEADERS
	Classes/AppDelegate.h
	Classes/Scene/MenuScene.h
	Classes/Scene/GameScene.h
	${PLATFORM_SPECIFIC_HEADERS}
	Classes/View/Scroller.h
	Classes/Model/IsoPoint.h
	Classes/Controller/LoaderMap.h
	Classes/Model/Config.h
	Classes/Controller/TileImageManager.h
	Classes/Model/Map/Cell.h
	Classes/Controller/FactoryCells.h
	Classes/Model/Map/Cells/RoadCell.h
	Classes/Model/Map/Cells/RailRoadCell.h
	Classes/Model/Map/Cells/ParkCell.h
	Classes/Model/Map/MapObject.h
	Classes/View/Ui/Button.h
	Classes/View/Ui/ItemBuilding.h
	Classes/View/Ui/Buildings.h
	Classes/Model/Map/World.h
	Classes/Model/Map/MapCity.h
	Classes/Controller/LoaderConfig.h
	Classes/Controller/BuildingController.h
	Classes/Controller/LoaderMapObject.h
	)

set(GAME_HEADERS ${PLATFORM_SPECIFIC_HEADERS})

# Configure libcocos2d
SET(BUILD_CPP_EMPTY_TEST OFF CACHE BOOL "turn off build cpp-empty-test")
SET(BUILD_CPP_TESTS OFF CACHE BOOL "turn off build cpp-tests")
SET(BUILD_LUA_LIBS OFF CACHE BOOL "turn off build lua related targets")
SET(BUILD_JS_LIBS OFF CACHE BOOL "turn off build js related targets")
SET(BUILD_JS_LIBS OFF CACHE BOOL "turn off build js related targets")

SET(USE_CHIPMUNK OFF CACHE BOOL "turn off build USE_CHIPMUNK")
SET(USE_BULLET OFF CACHE BOOL "Turn off Bullet (3d physics)")
SET(USE_RECAST OFF CACHE BOOL "Turn off Recast (3d pathfinding)")

ADD_SUBDIRECTORY(${COCOS2D_ROOT})

# MyGame
IF(ANDROID)
	ADD_LIBRARY(${APP_NAME} SHARED ${GAME_SRC} ${GAME_HEADERS})
	IF(CMAKE_BUILD_TYPE MATCHES RELEASE)
		ADD_CUSTOM_COMMAND(TARGET ${APP_NAME} POST_BUILD COMMAND ${CMAKE_STRIP} lib${APP_NAME}.so)
	ENDIF()
ELSE()
	ADD_EXECUTABLE(${APP_NAME} ${GAME_SRC} ${GAME_HEADERS})
ENDIF()

TARGET_LINK_LIBRARIES(${APP_NAME} cocos2d ${LIBRARIES})

SET(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin")

SET_TARGET_PROPERTIES(${APP_NAME} PROPERTIES
					  RUNTIME_OUTPUT_DIRECTORY "${APP_BIN_DIR}")

IF(WIN32)
	#also copying dlls to binary directory for the executable to run
	PRE_BUILD(${APP_NAME}
			  COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/Resources
			  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/Resources
			  COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/win32-specific/gles/prebuilt/glew32.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
			  COMMAND ${CMAKE_COMMAND} -E copy ${COCOS2D_ROOT}/external/win32-specific/zlib/prebuilt/zlib1.dll ${APP_BIN_DIR}/${CMAKE_BUILD_TYPE}
			  )
ELSEIF(ANDROID)

ELSE()
	PRE_BUILD(${APP_NAME}
			  COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/Resources
			  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/Resources
			  )

ENDIF()
