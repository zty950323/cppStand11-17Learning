set(stdRegexUseProgram stdRegexUseLearning)
set(stdRegexStandingProgram stdRegexStandingExample)

add_executable(${stdRegexUseProgram}
stdRegexUseLearning.cpp)

add_executable(${stdRegexStandingProgram}
stdRegexStandingExample.cpp)