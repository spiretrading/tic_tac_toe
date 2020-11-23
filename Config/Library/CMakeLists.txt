file(GLOB header_files ../../Include/TicTacToe/Library/*.hpp)
file(GLOB source_files ../../Source/Library/*.cpp)
source_group("Header Files" FILES ${header_files})
source_group("Source Files" FILES ${source_files})
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()
add_library(Library ${header_files} ${source_files})
set_source_files_properties(${header_files} PROPERTIES HEADER_FILE_ONLY TRUE)
set_target_properties(Library PROPERTIES OUTPUT_NAME tic_tac_toe)
install(TARGETS Library CONFIGURATIONS Debug
  DESTINATION ${TIC_TAC_TOE_LIBRARY_INSTALL_DIRECTORY}/Debug)
install(TARGETS Library CONFIGURATIONS Release
  DESTINATION ${TIC_TAC_TOE_LIBRARY_INSTALL_DIRECTORY}/Release)
