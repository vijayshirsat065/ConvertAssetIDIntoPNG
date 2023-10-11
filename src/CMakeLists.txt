
SET(INTERFACE_FILES	"IAssetIDLoader.h"
					"IAssetIDCharToNumberMapper.h"
					"IChecksumGenerator.h"
					)

SET(SOURCE_FILES	"core/FileReader.h"
					"core/FileReader.cpp"
					"core/ConfigFileReader.h"
					"core/ConfigFileReader.cpp"
					"FourDigitAssetIDLoader.h"
					"FourDigitAssetIDLoader.cpp"
					"AssetIDDecimalCharToNumberMapper.h"
					"AssetIDDecimalCharToNumberMapper.cpp"
					"TwoDigitChecksumGeneratorFromFourDigitAssetID.h" 
					"TwoDigitChecksumGeneratorFromFourDigitAssetID.cpp"
					)

# Add source to this project's executable.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${INTERFACE_FILES} ${SOURCE_FILES})
add_executable (${CMAKE_PROJECT_NAME} ${INTERFACE_FILES} ${SOURCE_FILES} "main.cpp")

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

set(DESTINATION_FOLDER "${PROJECT_BINARY_DIR}/src")

INSTALL(FILES "SevenSegmentDisplayCharacterToBitArrayMapping.txt" DESTINATION ${DESTINATION_FOLDER})
INSTALL(FILES "test.txt" DESTINATION ${DESTINATION_FOLDER})
