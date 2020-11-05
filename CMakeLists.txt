cmake_minimum_required(VERSION 3.17)
project(xiTech)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL 4.1 REQUIRED)

include_directories(src/libs/glad/include ${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

add_executable(xiTech main.cpp src/libs/glad/src/glad.c src/engine/rendering/Renderer.cpp src/engine/rendering/Renderer.h src/engine/XiTech.cpp src/engine/XiTech.h src/engine/exceptions/GLFWException.cpp src/engine/exceptions/GLFWException.h src/engine/hid/InputHandler.cpp src/engine/hid/InputHandler.h src/engine/hid/InputHandlerManager.cpp src/engine/hid/InputHandlerManager.h src/engine/resources/graphics/Mesh.cpp src/engine/resources/graphics/Mesh.h src/engine/resources/graphics/Model.cpp src/engine/resources/graphics/Model.h src/engine/resources/manager/ResourceManager.cpp src/engine/resources/manager/ResourceManager.h src/engine/resources/Resource.cpp src/engine/resources/Resource.h src/engine/resources/exceptions/ResourceException.cpp src/engine/resources/exceptions/ResourceException.h src/engine/resources/loader/ResourceLoader.cpp src/engine/resources/loader/ResourceLoader.h src/engine/resources/loader/ResourceLoaderRegistration.h src/engine/resources/loader/obj/ObjLoader.cpp src/engine/resources/loader/obj/ObjLoader.h src/engine/resources/graphics/Shader.cpp src/engine/resources/graphics/Shader.h src/engine/math/vector/Vector2.h src/engine/math/Vector.h src/engine/math/vector/Vector3.h src/engine/math/vector/Vector4.h src/engine/resources/graphics/Vertex.cpp src/engine/resources/graphics/Vertex.h src/engine/resources/loader/glsl/GlslLoader.cpp src/engine/resources/loader/glsl/GlslLoader.h)

target_link_libraries(xiTech glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${CMAKE_DL_LIBS})

file(COPY resources DESTINATION .)