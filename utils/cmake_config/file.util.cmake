#
# @file		file.util.cmake
# @author	Vincent Zeng
# @brief	file utils for cmake
#

include(CMakeParseArguments)

# add source files to a list
function(append_source_list source_list)
	cmake_parse_arguments(ARG "" "" "SRC_PATH" ${ARGN})

	# parameter check
	if(NOT "${${source_list}}" STREQUAL "source_list" AND NOT "${${source_list}}" STREQUAL "")
		list(APPEND temp_list ${${source_list}})
	endif()

	message("")
	message(STATUS "append_source_list from: ")

	foreach(arg IN LISTS ARG_SRC_PATH)
		message(${arg})
		file(GLOB_RECURSE sources "${arg}")
		list(APPEND temp_list ${sources})
	endforeach()
	
	list(SORT temp_list)
	set(${source_list} ${temp_list} PARENT_SCOPE)

	message(STATUS "append_source_list end")
endfunction()

# exclude files from a list
function(exclude_source_list source_list)
	cmake_parse_arguments(ARG "" "" "REMOVE_PATH" ${ARGN})

	message("")
	message(STATUS "exclude_source_list from: ")

	list(APPEND temp_list ${${source_list}})

	foreach(arg IN LISTS ARG_REMOVE_PATH)
		message(${arg})
		file(GLOB_RECURSE sources "${arg}")
		list(REMOVE_ITEM temp_list ${sources})
	endforeach()
	
	set(${source_list} ${temp_list} PARENT_SCOPE)
	
	message(STATUS "exclude_source_list end")
endfunction()

# create source group from a list
function(create_source_group source_list)
	cmake_parse_arguments(ARG "" "RELATIVE_PATH" "" ${ARGN})

	message("")
	message(STATUS "create_source_group: ")

	foreach(src in ${${source_list}})
		get_filename_component(filePath "${src}" DIRECTORY)

		if("${filePath}" STREQUAL "")
			continue()
		endif()

		file(RELATIVE_PATH relPath ${ARG_RELATIVE_PATH} ${filePath})

		string(REPLACE "/" "\\" groupPath "${relPath}")
		# message(STATUS "source group ${src} -> ${groupPath}")
		source_group("${groupPath}" FILES ${src})
	endforeach()

	message(STATUS "create_source_group end")
endfunction()
