cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


message("Making ${LISTING_ID}")    

if(LISTING_ID STREQUAL "MS3-1")
	add_executable (MS3-1 src/MS3-1/MS3-1.cpp src/MS3-1/RelayRunner.cpp) 
else()
	add_executable (${LISTING_ID} src/${LISTING_ID}.cpp)	
endif()

