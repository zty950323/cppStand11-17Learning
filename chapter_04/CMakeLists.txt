set(std_arrayProgram std_arrayLearning)
set(compareMapAndUnorderedMapProgram compareMapAndUnorderedMapLeaning)
set(tupleUseAndProgram tupleUseAndLearning)

add_executable(${std_arrayProgram}
std_arrayLearning.cpp)

add_executable(${compareMapAndUnorderedMapProgram}
compareMapAndUnorderedMap.cpp)

add_executable(${tupleUseAndProgram}
tupleUseAndLearning.cpp)