cmake_minimum_required(VERSION 3.15)
project(Soccer_club_simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Soccer_club_simulator main.cpp Team.cpp Player.cpp Forward.cpp Midfielder.cpp Defender.cpp Goalkeeper.cpp)
