find_path(DOT_INCLUDE_DIR Dot.h PATH_SUFFIXES /usr/local/include/Dot /usr/include/Dot $ENV{Dot_DIR}/include/Dot)
find_library(DOT_LIBS Dot HINTS /usr/local/lib /usr/lib $ENV{Dot_DIR}/lib)
get_filename_component(DOT_LIBRARY_DIR ${DOT_LIBS} PATH)
if(DOT_INCLUDE_DIR)
	if(DOT_LIBS)
		set(DOT_FOUND "YES")
	endif()
endif()
