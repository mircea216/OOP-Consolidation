cmake_minimum_required(VERSION 3.17)
project(laboratory09_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboratory09_10 app.cpp Domain/Order.cpp Domain/Order.h Test/Test.cpp Test/Test.h Repository/Repository.cpp Repository/Repository.h Repository/FileRepository.cpp Repository/FileRepository.h Service/Service.cpp Service/Service.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Exceptions/OrderException.cpp Exceptions/OrderException.h Validators/OrderValidator.cpp Validators/OrderValidator.h Exceptions/RepositoryException.cpp Exceptions/RepositoryException.h Exceptions/ServiceException.cpp Exceptions/ServiceException.h)