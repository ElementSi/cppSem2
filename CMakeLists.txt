cmake_minimum_required(VERSION 3.21)
project(Sem2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Minimum Templates/Minimum.cpp)
add_executable(TemplateStudent Templates/TemplateStudent.cpp)
add_executable(TemplateVector2D Templates/TemplateVector2D.cpp)
add_executable(Dimensions Templates/Dimensions.cpp)

add_executable(Analyzer BaseSTL1/Analyzer.cpp)
add_executable(RatingTable BaseSTL1/RatingTable.cpp)
add_executable(Name BaseSTL1/Name.cpp)

add_executable(ZooAdvanced BaseSTL2/ZooAdvanced.cpp)
add_executable(UserSessions BaseSTL2/UserSessions.cpp)
add_executable(UserActivity BaseSTL2/UserActivity.cpp)
add_executable(Telemetry BaseSTL2/Telemetry.cpp)
add_executable(AttackDetector BaseSTL2/AttackDetector.cpp)
