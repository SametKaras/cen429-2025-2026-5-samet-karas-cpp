# src/LocalEventPlannerApp CMakeLists.txt
set(APPNAME LocalEventPlannerapp)

message(STATUS "[${APPNAME}] Module Processing...")

# Collect files without having to explicitly list each header and source file
file(GLOB APP_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.hpp")

file(GLOB APP_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

# Create named folders for the sources within the project
source_group("Header Files" FILES ${APP_HEADERS})
source_group("Source Files" FILES ${APP_SOURCES})

# Set Properties->General->Configuration Type to Executable
add_executable(${APPNAME} ${APP_HEADERS} ${APP_SOURCES}) # Create executable

# Include directories
target_include_directories(${APPNAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/../LocalEventPlanner/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/header)

set(SQLITE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utility/src)   # sqlite3.c'nin bulunduğu dizin
set(SQLITE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header)  # sqlite3.h'nin bulunduğu dizin

target_sources(${APPNAME} PRIVATE ${SQLITE_SRC_DIR}/sqlite3.c)

# SQLite başlık dosyasını include edilecek dizinlere ekle
target_include_directories(${APPNAME} PRIVATE ${SQLITE_INCLUDE_DIR})


# Link the LocalEventPlanner library
target_link_libraries(${APPNAME} PRIVATE LocalEventPlanner)

# CMake'i MDd (dinamik debug) olarak yapılandır
if(MSVC)
    # Visual Studio'da runtime library ayarını MDd (dinamik debug) yap
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MD" CACHE STRING "MSVC runtime library" FORCE)
endif()

# Debug ve Release yapılandırmaları için özel ayarlar
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Debug modu için /MDd kullan
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Release modu için /MD kullan (dinamik bağlantı)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

# Install the executable
install(TARGETS ${APPNAME}
        RUNTIME DESTINATION bin)

message(STATUS "[${APPNAME}] Added Executable target: ${APPNAME}")
