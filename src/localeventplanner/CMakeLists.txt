set(LIBNAME LocalEventPlanner)

message(STATUS "[${LIBNAME}] Module Processing...")

# Collect files without having to explicitly list each header and source file
file(GLOB LIB_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.hpp")

file(GLOB LIB_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Create named folders for the sources within the project
source_group("Header Files" FILES ${LIB_HEADERS})
source_group("Source Files" FILES ${LIB_SOURCES})

# Set Properties->General->Configuration Type to Dynamic Library (.dll/.so/.dylib)
add_library(${LIBNAME} SHARED ${LIB_HEADERS} ${LIB_SOURCES}) # Create dynamic library (DLL)

# Include directories
target_include_directories(${LIBNAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/header)

# Anahtar yollarını C++ programına tanımlama
set(KEYS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../keys")
set(PRIVATE_KEY_PATH "${KEYS_DIR}/private_key.pem")
set(PUBLIC_KEY_PATH "${KEYS_DIR}/public_key.pem")

set(CERTIFICATE_FILE_PATH "${KEYS_DIR}/certificate.crt")
set(PRIVATE_KEY_FILE_PATH "${KEYS_DIR}/private.key")
set(CA_CERTIFICATE_FILE_PATH "${KEYS_DIR}/ca_cert.pem")

# SQLite kaynak dosyasının ve başlık dosyasının yollarını ayarla
set(SQLITE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utility/src)   # sqlite3.c'nin bulunduğu dizin
set(SQLITE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header)  # sqlite3.h'nin bulunduğu dizin

# SQLite kaynak dosyasını derleme için ekle
        target_sources(${LIBNAME} PRIVATE ${SQLITE_SRC_DIR}/sqlite3.c)

	# SQLite başlık dosyasını include edilecek dizinlere ekle
	target_include_directories(${LIBNAME} PRIVATE ${SQLITE_INCLUDE_DIR})

target_compile_definitions(${LIBNAME} PRIVATE 
    CERTIFICATE_FILE_PATH="${CERTIFICATE_FILE_PATH}" 
    PRIVATE_KEY_FILE_PATH="${PRIVATE_KEY_FILE_PATH}"
    CA_CERTIFICATE_FILE_PATH="${CA_CERTIFICATE_FILE_PATH}"
    PRIVATE_KEY_PATH="${PRIVATE_KEY_PATH}" 
    PUBLIC_KEY_PATH="${PUBLIC_KEY_PATH}")


# Anahtar dosyalarını oluşturmak için OpenSSL komutları
execute_process(
    COMMAND openssl genpkey -algorithm RSA -out ${PRIVATE_KEY_PATH} -pkeyopt rsa_keygen_bits:2048
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
if(NOT result EQUAL 0)
    message(FATAL_ERROR "Özel anahtar oluşturulamadı!")
endif()

# Açık anahtar oluşturulması
execute_process(
    COMMAND openssl rsa -pubout -in ${PRIVATE_KEY_PATH} -out ${PUBLIC_KEY_PATH}
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
if(NOT result EQUAL 0)
    message(FATAL_ERROR "Açık anahtar oluşturulamadı!")
endif()

# Creates preprocessor definition used for library exports
target_compile_definitions(${LIBNAME} PUBLIC LOCAL_EVENT_PLANNER_LIB_EXPORTS)


# OpenSSL'i bul ve dahil et
find_package(OpenSSL REQUIRED)

# OpenSSL bulunamazsa hata ver
if(NOT OpenSSL_FOUND)
    message(FATAL_ERROR "OpenSSL bulunamadı! Lütfen OpenSSL'i kurun veya doğru dizini belirtin.")
endif()

# OpenSSL'i hedef kütüphaneye linkle
target_link_libraries(${LIBNAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto)

target_link_libraries(${LIBNAME} PUBLIC
    Ws2_32
    Crypt32
)

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

# Install targets
install(TARGETS ${LIBNAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

# Copy required header to the installation include folder
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/LocalEventPlanner.h
        DESTINATION include)
