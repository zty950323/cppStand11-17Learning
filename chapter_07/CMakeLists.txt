set(stdThreadUseProgram stdThreadUseLearning)
set(synThreadUseProgram synThreadUseLeaning)
set(stdProducerAndCostomerProgram stdProducerAndCostomerLearning)
set(stdThreadExampleProgram stdThreadExampleLearning)

find_package(Threads REQUIRED)

add_executable(${stdThreadUseProgram}
stdThreadUseLearning.cpp)

add_executable(${synThreadUseProgram}
synThreadUseLeaning.cpp)

add_executable(${stdProducerAndCostomerProgram}
stdProducerAndCostomerLearning.cpp)

add_executable(${stdThreadExampleProgram}
stdThreadExampleLearning.cpp)

if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET ${stdThreadUseProgram} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdThreadUseProgram} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${synThreadUseProgram} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${synThreadUseProgram} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdProducerAndCostomerProgram} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdProducerAndCostomerProgram} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdThreadExampleProgram} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${stdThreadExampleProgram} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(${stdThreadUseProgram} "${CMAKE_THREAD_LIBS_INIT}")
  target_link_libraries(${synThreadUseProgram} "${CMAKE_THREAD_LIBS_INIT}")
  target_link_libraries(${stdProducerAndCostomerProgram} "${CMAKE_THREAD_LIBS_INIT}")
  target_link_libraries(${stdThreadExampleProgram} "${CMAKE_THREAD_LIBS_INIT}")
endif()

