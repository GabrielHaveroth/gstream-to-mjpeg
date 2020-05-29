cmake_minimum_required(VERSION 3.0.0)
project(gstreamer_t_mjpeg)

include_directories(include)
find_package(OpenCV REQUIRED)
find_package (Threads)

set(SOURCES src/main.cpp src/MJPEGWriter.cpp)

add_executable(gstreamer_mjpeg ${SOURCES})

target_link_libraries(gstreamer_mjpeg ${OpenCV_LIBS})
target_link_libraries (gstreamer_mjpeg ${CMAKE_THREAD_LIBS_INIT})


