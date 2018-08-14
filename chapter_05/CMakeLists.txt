set(sharedPtrProgram sharedPtrLearning)
set(uniquePrtProgram uniquePrtLearning)

add_executable(${sharedPtrProgram}
sharedPtrLearning.cpp)

add_executable(${uniquePrtProgram}
uniquePrtLearning.cpp)

