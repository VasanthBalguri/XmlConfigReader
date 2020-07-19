cmake_minimum_required(VERSION 3.1.0)

project(XmlConfigReader)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_library(libxml2 libxml2)

link_directories(/usr/lib/x86_64-linux-gnu/)
include_directories(/usr/include/libxml2)

#add_library(xmlconfigreaderlib
#    xmlhandler.cpp
#)
add_executable(xmlconfigreader
    xmlhandler.cpp
    main.cpp
)

target_link_libraries(xmlconfigreader xml2) 
