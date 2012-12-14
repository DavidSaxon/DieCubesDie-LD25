CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
CMAKE_POLICY(VERSION 2.6)
PROJECT(GameFrame)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

SET(FLAGS "${FLAGS} -g")

SET(SRCS
    src/main/Main.cpp
    src/engine/Engine.cpp
    src/engine/Engine_Event.cpp
    src/engine/Event.cpp
  )

SET(PROGRAMS GameFrame)

ADD_EXECUTABLE(GameFrame ${SRCS})

TARGET_LINK_LIBRARIES(GameFrame
  -lSDL
  -lSDL_mixer
  -lGL
  -lGLU
  -lglut
  -lpng
  -lm
  )

INSTALL(TARGETS GameFrame RUNTIME DESTINATION .)

SET_TARGET_PROPERTIES(GameFrame PROPERTIES COMPILE_FLAGS "${FLAGS}")
