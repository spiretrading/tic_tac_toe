file(GLOB game_board_window_header_files
  ../../Include/TicTacToe/Library/GameBoardWindow/*.hpp)
file(GLOB game_board_window_source_files
  ../../Source/Library/GameBoardWindow/*.cpp)
source_group("GameBoardWindow\\Header Files"
  FILES ${game_board_window_header_files})
source_group("GameBoardWindow\\Source Files"
  FILES ${game_board_window_source_files})
file(GLOB common_header_files ../../Include/TicTacToe/Library/*.hpp)
file(GLOB common_source_files ../../Source/Library/*.cpp)
source_group("TicTacToe\\Header Files" FILES ${common_header_files})
source_group("TicTacToe\\Source Files" FILES ${common_source_files})
file(GLOB header_files ${game_board_window_header_files}
  ${common_header_files})
file(GLOB source_files ${game_board_window_source_files}
  ${common_source_files})
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
