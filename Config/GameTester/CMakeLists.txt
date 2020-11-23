file(GLOB source_files ../../Source/GameTester/*.cpp)
add_executable(GameTester ${source_files})
target_link_libraries(GameTester Library)
add_custom_command(TARGET GameTester POST_BUILD COMMAND GameTester)
install(TARGETS GameTester CONFIGURATIONS Debug
  DESTINATION ${TIC_TAC_TOE_TESTS_INSTALL_DIRECTORY}/Debug)
install(TARGETS GameTester CONFIGURATIONS Release
  DESTINATION ${TIC_TAC_TOE_TESTS_INSTALL_DIRECTORY}/Release)
