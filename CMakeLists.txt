cmake_minimum_required(VERSION 3.24)
project(GradeCal)

set(CMAKE_CXX_STANDARD 17)

add_executable(GradeCal GradeBook.cpp GradeClasses.cpp GradeClasses.h)
