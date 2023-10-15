
SET(INTERFACE_FILES		"IAssetIDCharToNumberMapper.h"
						"IAssetIDLoader.h"
						"ICharToBitArrayMapper.h"
						"IChecksumGenerator.h"
						"IImageFileCreator.h"
						)

SET(SOURCE_FILES		"core/ConfigFileReader.h"
						"core/ConfigFileReader.cpp"
						"core/FileReader.h"
						"core/FileReader.cpp"
						"core/FileWriter.h"
						"core/FileWriter.cpp"
						"AssetIDDecimalCharToNumberMapper.h"
						"AssetIDDecimalCharToNumberMapper.cpp"
						"CharToSevenSegmentBitArrayMapper.h"
						"CharToSevenSegmentBitArrayMapper.cpp"
						"ConvertAssetIDIntoPNG.h"
						"ConvertAssetIDIntoPNG.cpp"
						"FourDigitAssetIDLoader.h"
						"FourDigitAssetIDLoader.cpp"
						"OneBitPNGImageFileGenerator.h"
						"OneBitPNGImageFileGenerator.cpp"
						"TwoDigitChecksumGeneratorFromFourDigitAssetID.h" 
						"TwoDigitChecksumGeneratorFromFourDigitAssetID.cpp"
						"${EXTERNAL_DEPENDENCIES_FOLDER}/lodepng/lodepng.h"
						"${EXTERNAL_DEPENDENCIES_FOLDER}/lodepng/lodepng.cpp"
						)

# Add source to this project's executable.
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${INTERFACE_FILES} ${SOURCE_FILES})
add_executable (${CMAKE_PROJECT_NAME} ${INTERFACE_FILES} ${SOURCE_FILES} "main.cpp")

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

set(DESTINATION_FOLDER "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

INSTALL(FILES "SevenSegmentDisplayCharacterToBitArrayMapping.txt" DESTINATION ${DESTINATION_FOLDER})
INSTALL(FILES "test.txt" DESTINATION ${DESTINATION_FOLDER})
