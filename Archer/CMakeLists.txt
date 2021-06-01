# CMakeList.txt : CMake project for Archer, include source and define
# project specific logic here

# require minumim cmake version
cmake_minimum_required (VERSION 3.8)

# verify architracture is supported
if (NOT ${ARCHITECTURE} MATCHES "x86_64")
  MESSAGE( FATAL_ERROR "Architecture is not supported. The only suppored arch is x64" )
endif()

# list src files
SET(SRC_FILES 
	"Archer.cpp"
    "coverage/DebuggerBase.hpp"
    "fuzzer/Logging.hpp"
    )

# verify platform is supported and locate os specific files
if (WIN32)
  SET(OS_SPECIFIC_SRC_FILES
       "coverage/win/Debugger.hpp"
       "coverage/win/Debugger.cpp"
       "coverage/win/HandleWrapper.hpp"
       "coverage/win/utils.hpp"
       "coverage/win/utils.cpp"
  )
elseif (UNIX AND ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  SET(OS_SPECIFIC_SRC_FILES
       "coverage/linux/Debugger.hpp"
       "coverage/linux/Debugger.cpp"
  )
else()
  MESSAGE( FATAL_ERROR "Platform is not supported. supported platforms are: windows, linux" )
endif()

# add source files to this project's executable
add_executable (Archer ${SRC_FILES} ${OS_SPECIFIC_SRC_FILES})

# set c++17 as the language standard for this executable
target_compile_features(Archer PRIVATE cxx_std_17)