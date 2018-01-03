CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/Cells/RoadCell.cpp
	Classes/Model/Map/Cells/RailRoadCell.cpp
	Classes/Model/Map/Cells/ParkCell.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/Cells/RoadCell.h
	Classes/Model/Map/Cells/RailRoadCell.h
	Classes/Model/Map/Cells/ParkCell.h
	PARENT_SCOPE)
