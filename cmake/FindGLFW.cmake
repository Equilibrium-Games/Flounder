set(GLFW_INCLUDES "${PROJECT_SOURCE_DIR}/Libraries/glfw/include")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(${PROJECT_SOURCE_DIR}/Libraries/glfw)
set(GLFW_LIBRARY "glfw")

list(APPEND LIBRARIES_INCLUDES ${GLFW_INCLUDES})
list(APPEND LIBRARIES_LINKS "${GLFW_LIBRARY}")

if(NOT GLFW_LIBRARY)
	message(FATAL_ERROR "GLFW library not found!")
endif()
