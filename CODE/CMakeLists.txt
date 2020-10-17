PROJECT(chop)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM REQUIRED gtkmm-3.0)
INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTKMM_CFLAGS_OTHER})
ADD_EXECUTABLE(
    chop
    chop.cpp
    SYSTEM/gdk.hpp
    SYSTEM/glib.hpp
    SYSTEM/gtk.hpp
    SYSTEM/sigc.hpp
    SYSTEM/std.hpp
    FRAMEWORK/handle.hpp
    MODEL/file_table.cpp
    MODEL/file_table.hpp
    VIEW/application_view.cpp
    VIEW/application_view.hpp
    VIEW/button_view.cpp
    VIEW/button_view.hpp
    VIEW/file_view.cpp
    VIEW/file_view.hpp
    )
TARGET_LINK_LIBRARIES(chop ${GTKMM_LIBRARIES})
