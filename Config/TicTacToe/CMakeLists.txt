find_package(Qt5Widgets REQUIRED)
file(GLOB header_files ${TIC_TAC_TOE_INCLUDE_PATH}/TicTacToe/*.hpp)
file(GLOB source_files ${TIC_TAC_TOE_SOURCE_PATH}/TicTacToe/*.cpp)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
if(WIN32)
  file(GLOB resource_files ${TIC_TAC_TOE_SOURCE_PATH}/TicTacToe/*.rc)
  file(GLOB manifest_files ${TIC_TAC_TOE_SOURCE_PATH}/TicTacToe/*.manifest)
  set(app_type WIN32)
elseif(APPLE)
  set(app_type MACOSX_BUNDLE)
  set(resource_files "")
  set(manifest_files "")
else()
  set(resource_files "")
  set(manifest_files "")
endif(WIN32)
include_directories(${PROJECT_BINARY_DIR})
add_executable(tic_tac_toe ${app_type} ${header_files} ${source_files}
  ${resource_files} ${manifest_files})
set_source_files_properties(${header_files} PROPERTIES HEADER_FILE_ONLY TRUE)
target_link_libraries(TicTacToe Resources
  debug ${QT_CORE_LIBRARY_DEBUG_PATH}
  optimized ${QT_CORE_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_FREETYPE_LIBRARY_DEBUG_PATH}
  optimized ${QT_FREETYPE_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_HBNG_LIBRARY_DEBUG_PATH}
  optimized ${QT_HBNG_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_GUI_LIBRARY_DEBUG_PATH}
  optimized ${QT_GUI_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_MAIN_LIBRARY_DEBUG_PATH}
  optimized ${QT_MAIN_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_PCRE_LIBRARY_DEBUG_PATH}
  optimized ${QT_PCRE_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_WIDGETS_LIBRARY_DEBUG_PATH}
  optimized ${QT_WIDGETS_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_PNG_LIBRARY_DEBUG_PATH}
  optimized ${QT_PNG_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_EVENT_LIBRARY_DEBUG_PATH}
  optimized ${QT_EVENT_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_FONT_LIBRARY_DEBUG_PATH}
  optimized ${QT_FONT_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_THEME_LIBRARY_DEBUG_PATH}
  optimized ${QT_THEME_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_ACCESS_LIBRARY_DEBUG_PATH}
  optimized ${QT_ACCESS_LIBRARY_OPTIMIZED_PATH})
if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
  target_link_libraries(TicTacToe pthread rt)
endif()
if(WIN32)
  target_link_libraries(TicTacToe
    debug ${QT_WINDOWS_ACCESSIBILITY_LIBRARY_DEBUG_PATH}
    optimized ${QT_WINDOWS_ACCESSIBILITY_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_WINDOWS_LIBRARY_DEBUG_PATH}
    optimized ${QT_WINDOWS_LIBRARY_OPTIMIZED_PATH}
    Crypt32.lib dwmapi.lib imm32.lib netapi32.lib opengl32.lib userenv.lib
    version.lib winmm.lib ws2_32.lib wtsapi32.lib)
endif()
install(TARGETS TicTacToe DESTINATION ${PROJECT_BINARY_DIR}/Application)
