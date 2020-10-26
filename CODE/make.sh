#!/bin/sh
set -x
g++ -std=c++11 MODEL/file_table.cpp VIEW/application_view.cpp VIEW/button_view.cpp VIEW/file_view.cpp chop.cpp $(pkg-config gtkmm-3.0 --cflags --libs | sed 's/ -I/ -isystem /g') -o chop
