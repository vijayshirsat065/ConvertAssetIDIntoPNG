# CMakeList.txt : CMake project for ConvertAssetIDIntoPNG, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ConvertAssetIDIntoPNG")

# Download and load gtest package (https://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE # To avoid timestamp related warnings while downloading the gtest package
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Needed by the CTest
enable_testing()

# To resolve paths while including headers
include_directories(src)

# Including src and tests directories
add_subdirectory(src)
add_subdirectory(tests)

# Include test packages
include(CTest)			# CTest is a tool for managing and executing a complete suite of tests
include(GoogleTest)		# Google Test is a tool for writing individual C++ tests
