cmake_minimum_required(VERSION 2.6)
project(RayTracer)

set(RayTracer_VERSION_MAJOR 0)
set(RAYTracer_VERSION_MINOR 1)

add_executable(raytracer
    main.cpp
    ray.cpp
    vector.cpp
    camera.cpp
    color.cpp
    light.cpp
    sphere.cpp
    object.cpp
    plane.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

install(TARGETS raytracer DESTINATION ${CMAKE_SOURCE_DIR})
