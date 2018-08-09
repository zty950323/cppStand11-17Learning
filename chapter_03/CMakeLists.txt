set(LambdaProgram LambdaLearning)
set(make_uniqueProgram make_uniqueLearning)
set(moveSemanticsProgram moveSemanticsLearning)
set(perfactTransFromValueProgram perfactTransFromValueLearning)
set(forwardUsingProgram forwardUsingLearning)

add_executable(${LambdaProgram}
LambdaLearning.cpp)

add_executable(${make_uniqueProgram}
make_uniqueLearning.cpp)

add_executable(${moveSemanticsProgram}
moveSemanticsLearning.cpp)

add_executable(${perfactTransFromValueProgram}
perfactTransFromValueLearning.cpp)

add_executable(${forwardUsingProgram}
forwardUsingLearning.cpp)