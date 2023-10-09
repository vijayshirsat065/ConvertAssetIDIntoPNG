function(SetupAndAddSingleTestFile TestExecutableName TestSourceFile)
  add_executable(${TestExecutableName} ${TestSourceFile})
  add_test(NAME ${TestExecutableName}
         COMMAND ${TestExecutableName})
  target_link_libraries(${TestExecutableName} ${CMAKE_PROJECT_NAME}_lib gtest gmock GTest::gtest_main)
endfunction()

SetupAndAddSingleTestFile(NumberConversionTest NumberConversionTest.cpp)
SetupAndAddSingleTestFile(TwoDigitChecksumGeneratorTest TwoDigitChecksumGeneratorTest.cpp)
