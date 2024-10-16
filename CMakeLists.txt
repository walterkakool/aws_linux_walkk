cmake_minimum_required(VERSION 3.5)
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

message(
	STATUS 
	"All vars: "

)

get_cmake_property(
			var_bundle 
			VARIABLES 

)

foreach( each_item ${var_bundle} )
#	message( "${each_item}\n" )
endforeach()

#message( "${aws-lambda-runtime_DIR}" )

#cmake_print_variables(aws-lambda-runtime_FOUND)

target_include_directories( 
			     project_includes_libraries 
			     PUBLIC include 
                             "${HOME_PATH_ROOT}" 	
 			     #"${aws-lambda-runtime_DIR}"			 
                             "${HOME_PATH_ROOT}/aws-lambda-cpp/include"
)

install(
          TARGETS 
          project_includes_libraries 
	  DESTINATION 
	  "${HOME_PATH_ROOT}"
)

target_link_libraries(
	               project_includes_libraries 
		       AWS::aws-lambda-runtime  
                       #${aws-lambda-runtime_LIBRARIES}
)


target_link_libraries(
	  runner 
          
	  project_includes_libraries	  
)
