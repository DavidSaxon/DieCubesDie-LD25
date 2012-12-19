CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
CMAKE_POLICY(VERSION 2.6)
PROJECT(DieCubesDie)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

SET(FLAGS "${FLAGS} -g")

SET(SRCS
    src/main/Main.cpp
    src/engine/Engine.cpp
    src/engine/Engine_Level.cpp
    src/engine/Engine_Resources.cpp
    src/engine/Engine_Event.cpp
    src/engine/Event.cpp
    src/entities/LeftWallFollower.cpp
    src/entities/RightWallFollower.cpp
    src/entities/Floor.cpp
    src/entities/Wall.cpp
    src/entities/Spawn.cpp
    src/entities/Exit.cpp
    src/entities/Spike.cpp
    src/entities/Death.cpp
    src/engine/Selector.cpp
  )

SET(PROGRAMS DieCubesDie)

ADD_EXECUTABLE(DieCubesDie ${SRCS})

TARGET_LINK_LIBRARIES(DieCubesDie
  -lSDL
  -lGL
  -lGLU
  -lglut
  -lpng
  -lm
  )

INSTALL(TARGETS DieCubesDie RUNTIME DESTINATION .)

SET_TARGET_PROPERTIES(DieCubesDie PROPERTIES COMPILE_FLAGS "${FLAGS}")
