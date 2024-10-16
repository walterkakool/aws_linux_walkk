cmake_minimum_required(VERSION 3.0)
project(DeleteAll)

add_definitions(-w)

set   ( HOME_PATH_ROOT              ${CMAKE_CURRENT_SOURCE_DIR} )
set   ( CMAKE_CXX_STANDARD          11 )
set   ( CMAKE_CXX_STANDARD_REQUIRED true )

option( CMAKE_INSTALL_PREFIX        "${HOME_PATH_ROOT}" )

find_package(	
	        aws-lambda-runtime 
	        REQUIRED
)



add_library   ( 
	         project_includes_libraries
                 ${HOME_PATH_ROOT}/runner.cpp
)

add_executable(
	         runner
                 ${HOME_PATH_ROOT}/runner.cpp
)

target_include_directories( 
			     project_includes_libraries 
			     PUBLIC include 
                             "${HOME_PATH_ROOT}" 
                             "${aws-lambda-runtime_INCLUDE_DIRS}"
)

target_link_libraries	  ( 
		             project_includes_libraries   
			     PUBLIC 
	                     "${aws-lambda-runtime_LIBRARIES}"
)
 

target_compile_definitions( project_includes_libraries  PUBLIC "-DBOOST_LOG_DYN_LINK")

target_link_libraries(
		        runner 
	                project_includes_libraries 
)

install(
          TARGETS 
          project_includes_libraries 
	  DESTINATION 
	  "${HOME_PATH_ROOT}"
)

target_link_libraries(
	  runner 
	  project_includes_libraries	  
)
