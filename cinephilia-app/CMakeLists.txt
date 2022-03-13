cmake_minimum_required(VERSION 3.17)
project(finalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(finalProject app.cpp Domain/Object.h Domain/Movie.cpp Domain/Movie.h Tests/Test.cpp Tests/Test.h Domain/TheatrePlay.cpp Domain/TheatrePlay.h Domain/Documentary.cpp Domain/Documentary.h Repository/Repository.h Repository/RepositoryInMemory.cpp Repository/RepositoryInMemory.h Repository/FileRepository.cpp Repository/FileRepository.h Service/Service.cpp Service/Service.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Validators/MovieValidator.cpp Validators/MovieValidator.h Exceptions/GenericException.cpp Exceptions/GenericException.h Validators/DocumentaryValidator.cpp Validators/DocumentaryValidator.h Validators/TheatrePlayValidator.cpp Validators/TheatrePlayValidator.h GraphicUserInterface/GraphicUserInterface.cpp GraphicUserInterface/GraphicUserInterface.h)
set(CMAKE_PREFIX_PATH C:\\NEW_QT2\\5.14.2\\msvc2017_64)
find_package(Qt5Widgets REQUIRED)
target_link_libraries(finalProject Qt5::Widgets)