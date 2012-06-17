CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

PROJECT(witty-plus-2)

ADD_DEFINITIONS(-std=c++11 -Wall -Wextra)

# Settings for configuration and script files
IF( "${CMAKE_BUILD_TYPE}" STREQUAL Release )
  SET(DEBUG false)
  ADD_DEFINITIONS(-DBOOST_DISABLE_ASSERTS)
ELSE()
  SET(DEBUG true)
ENDIF()
SET(LOG_FILE_NAME "${PROJECT_NAME}.log")
option(WTDebug "Use the witty debug libraries ? (wtd.so etc.)" ${DEBUG})

set( DB_CONNECTION_STRING "host=localhost user=wp2 dbname=wp2 password=wp2" CACHE string "DB Connection string")
message("DB Connection string is: ${DB_CONNECTION_STRING}")

set(RunTests on CACHE BOOL "Run the testing code")
set(RunMemoryChecks on CACHE BOOL "Run the testing code with valgrind memory leak detection")

if (${RunTests}) 
    enable_testing()
endif()

# Sort out our libraries
if (WTDebug)
    find_library(wt wtd)
    find_library(wthttp wthttpd)
    find_library(wtdbo wtdbod)
    find_library(wtdbopostgres wtdbopostgresd)
    find_library(wttest wttestd)
else()
    find_library(wt wt)
    find_library(wthttp wthttp)
    find_library(wtdbo wtdbo)
    find_library(wtdbopostgres wtdbopostgres)
    find_library(wttest wttest)
endif()
 
find_package(OpenSSL REQUIRED)
include_directories(BEFORE ${OPENSSL_INCLUDE_DIR})

# Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.49.0 REQUIRED COMPONENTS system program_options signals date_time filesystem regex thread unit_test_framework)
include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIR})

# Sub directories
add_subdirectory(wp2)
add_subdirectory(bin)
add_subdirectory(static)
add_subdirectory(private)
