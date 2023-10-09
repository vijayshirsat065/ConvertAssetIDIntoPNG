
SET(INTERFACE_FILES	"IAssetIDLoader.h"
					"IChecksumGenerator.h"
					)

SET(SOURCE_FILES	"core/FileReader.h"
					"core/FileReader.cpp"
					"core/NumberConversion.h"
					"core/NumberConversion.cpp"
					"PlainTextFileLoader.h"
					"PlainTextFileLoader.cpp"
					"TwoDigitChecksumGenerator.h" 
					"TwoDigitChecksumGenerator.cpp"
					)

# Add source to this project's executable.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${INTERFACE_FILES} ${SOURCE_FILES})
add_executable (${CMAKE_PROJECT_NAME} ${INTERFACE_FILES} ${SOURCE_FILES} "main.cpp")

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

