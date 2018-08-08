set(nullptrProgram nullptrLearning)
set(constexprProgram constexprLearning)
set(ifValueStatementProgram ifValueStatementLearing)
set(InitializerListProgram InitializerListLearing)
set(autoUseProgram autoUseLearning)
set(decltypeProgram decltypeLearning)
set(forIterationProgram forIterationLearning)
set(tepmateUseProgram tepmateUseLearning)
set(DelegatingContructorsProgram DelegatingContructorsLearning)
set(inheritedConstructorsProgram inheritedConstructorsLearning)
set(OONewProgram OONewLearning)
set(enumClassProgram enumClassLearning)

add_executable(${nullptrProgram} 
nullptrLearning.cpp )

add_executable(${constexprProgram}
constexprLearning.cpp)

add_executable(${ifValueStatementProgram}
ifValueStatement.cpp)

add_executable(${InitializerListProgram}
InitializerListLearning.cpp)

add_executable(${autoUseProgram}
autoUseLearning.cpp)

add_executable(${decltypeProgram}
decltypeLearning.cpp)

add_executable(${forIterationProgram}
forIterationLearning.cpp)

add_executable(${tepmateUseProgram}
tepmateUseLearning.cpp)

add_executable(${DelegatingContructorsProgram}
DelegatingContructorsLearning.cpp)

add_executable(${inheritedConstructorsProgram}
inheritedConstructorsLearning.cpp)

add_executable(${OONewProgram}
OONewLearning.cpp)

add_executable(${enumClassProgram}
enumClassLearning.cpp)