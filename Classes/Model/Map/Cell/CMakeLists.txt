CMAKE_POLICY(SET CMP0017 NEW)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(GAME_SRC ${GAME_SRC}
	Classes/Model/Map/Cell/Cell.cpp
	Classes/Model/Map/Cell/RoadCell.cpp
	Classes/Model/Map/Cell/RailRoadCell.cpp
	Classes/Model/Map/Cell/ParkCell.cpp
	Classes/Model/Map/Cell/TypesCell.cpp
	Classes/Model/Map/Cell/RouteCell.cpp
	PARENT_SCOPE)

SET(GAME_HEADERS ${GAME_HEADERS}
	Classes/Model/Map/Cell/Cell.h
	Classes/Model/Map/Cell/RoadCell.h
	Classes/Model/Map/Cell/RailRoadCell.h
	Classes/Model/Map/Cell/ParkCell.h
	Classes/Model/Map/Cell/TypesCell.h
	Classes/Model/Map/Cell/RouteCell.h
	PARENT_SCOPE)
