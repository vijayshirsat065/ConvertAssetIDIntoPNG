
SET(SOURCE_FILES	"core/NumberConversion.h"
					"core/NumberConversion.cpp"
					"IChecksumGenerator.h" 
					"TwoDigitChecksumGenerator.h" 
					"TwoDigitChecksumGenerator.cpp"
					)

# Add source to this project's executable.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCE_FILES})
add_executable (${CMAKE_PROJECT_NAME} ${SOURCE_FILES} "main.cpp")

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

