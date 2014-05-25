cmake_minimum_required (VERSION 2.6)
project (教學)

# 版本號
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# 設定一個標頭檔案以傳入一些 CMake 設定值
# 到程式碼中
configure_file (
  "${PROJECT_SOURCE_DIR}/教學設定.h.in"
  "${PROJECT_BINARY_DIR}/教學設定.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# Ｖ字龍：因為 tutorial.cxx 無透過 include path 清單來找到 TutorialConfig.h 所以這一行應該不需要用
# include_directories("${PROJECT_BINARY_DIR}")

# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON) 
# add the MathFunctions library?
if (USE_MYMATH)
  # include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable(教學程式 tutorial.cxx)
target_link_libraries(教學程式 ${EXTRA_LIBS})
