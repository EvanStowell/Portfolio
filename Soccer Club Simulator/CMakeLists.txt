cmake_minimum_required(VERSION 3.15)
project(M3OEP-elstowel)

set(CMAKE_CXX_STANDARD 17)

add_executable(M3OEP-elstowel main.cpp Team.cpp Player.cpp Forward.cpp Midfielder.cpp Defender.cpp Goalkeeper.cpp)
add_executable(testing testing.cpp Team.cpp Player.cpp Forward.cpp Midfielder.cpp Defender.cpp Goalkeeper.cpp)