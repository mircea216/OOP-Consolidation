# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\OneDrive\Desktop\finalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\OneDrive\Desktop\finalProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\finalProject.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\finalProject.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\finalProject.dir\flags.make

CMakeFiles\finalProject.dir\app.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\app.cpp.obj: ..\app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/finalProject.dir/app.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\app.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\app.cpp
<<

CMakeFiles\finalProject.dir\app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/app.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\app.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\app.cpp
<<

CMakeFiles\finalProject.dir\app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/app.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\app.cpp.s /c D:\OneDrive\Desktop\finalProject\app.cpp
<<

CMakeFiles\finalProject.dir\Domain\Movie.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Domain\Movie.cpp.obj: ..\Domain\Movie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/finalProject.dir/Domain/Movie.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Domain\Movie.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Domain\Movie.cpp
<<

CMakeFiles\finalProject.dir\Domain\Movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Domain/Movie.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Domain\Movie.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Domain\Movie.cpp
<<

CMakeFiles\finalProject.dir\Domain\Movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Domain/Movie.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Domain\Movie.cpp.s /c D:\OneDrive\Desktop\finalProject\Domain\Movie.cpp
<<

CMakeFiles\finalProject.dir\Tests\Test.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Tests\Test.cpp.obj: ..\Tests\Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/finalProject.dir/Tests/Test.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Tests\Test.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Tests\Test.cpp
<<

CMakeFiles\finalProject.dir\Tests\Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Tests/Test.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Tests\Test.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Tests\Test.cpp
<<

CMakeFiles\finalProject.dir\Tests\Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Tests/Test.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Tests\Test.cpp.s /c D:\OneDrive\Desktop\finalProject\Tests\Test.cpp
<<

CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.obj: ..\Domain\TheatrePlay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/finalProject.dir/Domain/TheatrePlay.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Domain\TheatrePlay.cpp
<<

CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Domain/TheatrePlay.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Domain\TheatrePlay.cpp
<<

CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Domain/TheatrePlay.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.s /c D:\OneDrive\Desktop\finalProject\Domain\TheatrePlay.cpp
<<

CMakeFiles\finalProject.dir\Domain\Documentary.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Domain\Documentary.cpp.obj: ..\Domain\Documentary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/finalProject.dir/Domain/Documentary.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Domain\Documentary.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Domain\Documentary.cpp
<<

CMakeFiles\finalProject.dir\Domain\Documentary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Domain/Documentary.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Domain\Documentary.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Domain\Documentary.cpp
<<

CMakeFiles\finalProject.dir\Domain\Documentary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Domain/Documentary.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Domain\Documentary.cpp.s /c D:\OneDrive\Desktop\finalProject\Domain\Documentary.cpp
<<

CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.obj: ..\Repository\RepositoryInMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/finalProject.dir/Repository/RepositoryInMemory.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Repository\RepositoryInMemory.cpp
<<

CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Repository/RepositoryInMemory.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Repository\RepositoryInMemory.cpp
<<

CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Repository/RepositoryInMemory.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.s /c D:\OneDrive\Desktop\finalProject\Repository\RepositoryInMemory.cpp
<<

CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.obj: ..\Repository\FileRepository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/finalProject.dir/Repository/FileRepository.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Repository\FileRepository.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Repository\FileRepository.cpp
<<

CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Repository/FileRepository.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Repository\FileRepository.cpp
<<

CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Repository/FileRepository.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Repository\FileRepository.cpp.s /c D:\OneDrive\Desktop\finalProject\Repository\FileRepository.cpp
<<

CMakeFiles\finalProject.dir\Service\Service.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Service\Service.cpp.obj: ..\Service\Service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/finalProject.dir/Service/Service.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Service\Service.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Service\Service.cpp
<<

CMakeFiles\finalProject.dir\Service\Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Service/Service.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Service\Service.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Service\Service.cpp
<<

CMakeFiles\finalProject.dir\Service\Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Service/Service.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Service\Service.cpp.s /c D:\OneDrive\Desktop\finalProject\Service\Service.cpp
<<

CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.obj: ..\UserInterface\UserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/finalProject.dir/UserInterface/UserInterface.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\UserInterface\UserInterface.cpp
<<

CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/UserInterface/UserInterface.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\UserInterface\UserInterface.cpp
<<

CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/UserInterface/UserInterface.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.s /c D:\OneDrive\Desktop\finalProject\UserInterface\UserInterface.cpp
<<

CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.obj: ..\Validators\MovieValidator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/finalProject.dir/Validators/MovieValidator.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Validators\MovieValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Validators/MovieValidator.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Validators\MovieValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Validators/MovieValidator.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.s /c D:\OneDrive\Desktop\finalProject\Validators\MovieValidator.cpp
<<

CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.obj: ..\Exceptions\GenericException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/finalProject.dir/Exceptions/GenericException.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Exceptions\GenericException.cpp
<<

CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Exceptions/GenericException.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Exceptions\GenericException.cpp
<<

CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Exceptions/GenericException.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.s /c D:\OneDrive\Desktop\finalProject\Exceptions\GenericException.cpp
<<

CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.obj: ..\Validators\DocumentaryValidator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/finalProject.dir/Validators/DocumentaryValidator.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Validators\DocumentaryValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Validators/DocumentaryValidator.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Validators\DocumentaryValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Validators/DocumentaryValidator.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.s /c D:\OneDrive\Desktop\finalProject\Validators\DocumentaryValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.obj: ..\Validators\TheatrePlayValidator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/finalProject.dir/Validators/TheatrePlayValidator.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\Validators\TheatrePlayValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/Validators/TheatrePlayValidator.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\Validators\TheatrePlayValidator.cpp
<<

CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/Validators/TheatrePlayValidator.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.s /c D:\OneDrive\Desktop\finalProject\Validators\TheatrePlayValidator.cpp
<<

CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.obj: CMakeFiles\finalProject.dir\flags.make
CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.obj: ..\GraphicUserInterface\GraphicUserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/finalProject.dir/GraphicUserInterface/GraphicUserInterface.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.obj /FdCMakeFiles\finalProject.dir\ /FS -c D:\OneDrive\Desktop\finalProject\GraphicUserInterface\GraphicUserInterface.cpp
<<

CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finalProject.dir/GraphicUserInterface/GraphicUserInterface.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\OneDrive\Desktop\finalProject\GraphicUserInterface\GraphicUserInterface.cpp
<<

CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finalProject.dir/GraphicUserInterface/GraphicUserInterface.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.s /c D:\OneDrive\Desktop\finalProject\GraphicUserInterface\GraphicUserInterface.cpp
<<

# Object files for target finalProject
finalProject_OBJECTS = \
"CMakeFiles\finalProject.dir\app.cpp.obj" \
"CMakeFiles\finalProject.dir\Domain\Movie.cpp.obj" \
"CMakeFiles\finalProject.dir\Tests\Test.cpp.obj" \
"CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.obj" \
"CMakeFiles\finalProject.dir\Domain\Documentary.cpp.obj" \
"CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.obj" \
"CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.obj" \
"CMakeFiles\finalProject.dir\Service\Service.cpp.obj" \
"CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.obj" \
"CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.obj" \
"CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.obj" \
"CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.obj" \
"CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.obj" \
"CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.obj"

# External object files for target finalProject
finalProject_EXTERNAL_OBJECTS =

finalProject.exe: CMakeFiles\finalProject.dir\app.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Domain\Movie.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Tests\Test.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Domain\TheatrePlay.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Domain\Documentary.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Repository\RepositoryInMemory.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Repository\FileRepository.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Service\Service.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\UserInterface\UserInterface.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Validators\MovieValidator.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Exceptions\GenericException.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Validators\DocumentaryValidator.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\Validators\TheatrePlayValidator.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\GraphicUserInterface\GraphicUserInterface.cpp.obj
finalProject.exe: CMakeFiles\finalProject.dir\build.make
finalProject.exe: C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Widgetsd.lib
finalProject.exe: C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Guid.lib
finalProject.exe: C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Cored.lib
finalProject.exe: CMakeFiles\finalProject.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable finalProject.exe"
	"D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\finalProject.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\finalProject.dir\objects1.rsp @<<
 /out:finalProject.exe /implib:finalProject.lib /pdb:D:\OneDrive\Desktop\finalProject\cmake-build-debug\finalProject.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Widgetsd.lib C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Guid.lib C:\NEW_QT2\5.14.2\msvc2017_64\lib\Qt5Cored.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\finalProject.dir\build: finalProject.exe

.PHONY : CMakeFiles\finalProject.dir\build

CMakeFiles\finalProject.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\finalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles\finalProject.dir\clean

CMakeFiles\finalProject.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\OneDrive\Desktop\finalProject D:\OneDrive\Desktop\finalProject D:\OneDrive\Desktop\finalProject\cmake-build-debug D:\OneDrive\Desktop\finalProject\cmake-build-debug D:\OneDrive\Desktop\finalProject\cmake-build-debug\CMakeFiles\finalProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\finalProject.dir\depend

