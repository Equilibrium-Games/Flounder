set(BUILD_BULLET3 ON CACHE INTERNAL "Set when you want to build Bullet 3")
set(BUILD_CPU_DEMOS OFF CACHE INTERNAL "Build original Bullet CPU examples")
set(BUILD_BULLET2_DEMOS OFF CACHE INTERNAL "Set when you want to build the Bullet 2 demos")
set(USE_GRAPHICAL_BENCHMARK OFF CACHE INTERNAL "Use Graphical Benchmark")
set(BUILD_OPENGL3_DEMOS OFF CACHE INTERNAL "Set when you want to build the OpenGL3+ demos")
set(BUILD_EXTRAS OFF CACHE INTERNAL "Set when you want to build the extras")
set(USE_GLUT OFF CACHE INTERNAL "Use Glut")
add_subdirectory(${PROJECT_SOURCE_DIR}/Libraries/bullet3)
set(CMAKE_DEBUG_POSTFIX "" CACHE STRING "Adds a postfix for debug-built libraries.")
set(BULLET_LIBRARY "BULLET_PHYSICS")

message(WARNING "${BULLET_LIBRARY}")

# Bullet3Collision Bullet3Common Bullet3Dynamics Bullet3Geometry BulletCollision BulletDynamics BulletInverseDynamics BulletSoftBody
#list(APPEND LIBRARIES_INCLUDES ${BULLET_INCLUDES})
#list(APPEND LIBRARIES_LINKS "${BULLET_LIBRARY}")

if(NOT BULLET_LIBRARY)
	message(FATAL_ERROR "bullet library not found!")
endif()
