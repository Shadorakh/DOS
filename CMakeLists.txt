cmake_minimum_required(VERSION 3.30)

project(DOS VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(Source/Collections)
add_subdirectory(Source/Intrinsics)
add_subdirectory(Source/Mathematics)
add_subdirectory(Source/System)
add_subdirectory(Source)

set(SOURCES 
   ${SOURCE_COLLECTIONS}
   ${SOURCE_INTRINSICS}
   ${SOURCE_MATHEMATICS}
   ${SOURCE_SYSTEM}
   )

set(INCLUDES 
   ${INCLUDE_COLLECTIONS}
   ${INCLUDE_INTRINSICS}
   ${INCLUDE_MATHEMATICS}
   ${INCLUDE_SYSTEM}
   ${MODULE_HEADERS}
  )

source_group("Source Files/Collections" FILES ${SOURCE_COLLECTIONS})
source_group("Header Files/Collections" FILES ${INCLUDE_COLLECTIONS})
source_group("Source Files/Intrinsics" FILES ${SOURCE_INTRINSICS})
source_group("Header Files/Intrinsics" FILES ${INCLUDE_INTRINSICS})
source_group("Source Files/Mathematics" FILES ${SOURCE_MATHEMATICS})
source_group("Header Files/Mathematics" FILES ${INCLUDE_MATHEMATICS})
source_group("Source Files/System" FILES ${SOURCE_SYSTEM})
source_group("Header Files/System" FILES ${INCLUDE_SYSTEM})

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)