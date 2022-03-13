cmake_minimum_required(VERSION 3.17)
project(lab_07)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_07 app.cpp Domain/Expenditure.cpp Domain/Expenditure.h Tests/Test.cpp Tests/Test.h Repository/Repository.cpp Repository/Repository.h Service/Service.cpp Service/Service.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h)