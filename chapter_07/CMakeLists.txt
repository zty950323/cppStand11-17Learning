set(stdThreadUseProgram stdThreadUseLearning)

find_package(Threads REQUIRED)

add_executable(${stdThreadUseProgram}
stdThreadUseLearning.cpp)

if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET ${stdThreadUseProgram} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdThreadUseProgram} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(${stdThreadUseProgram} "${CMAKE_THREAD_LIBS_INIT}")
endif()

