// -- PRAGMAS

#pragma once

// -- IMPORTS

#include <gtkmm.h>

// -- CONSTANTS

#define GTK_ALIGN_Start Gtk::ALIGN_START
#define GTK_DESTINATION_DefaultAll Gtk::DEST_DEFAULT_ALL
#define GTK_ORIENTATION_Horizontal Gtk::ORIENTATION_HORIZONTAL
#define GTK_ORIENTATION_Vertical Gtk::ORIENTATION_VERTICAL
#define GTK_TARGET_OtherApplication Gtk::TARGET_OTHER_APP

// -- TYPES

#undef GTK_APPLICATION
#define GTK_APPLICATION Gtk::Application
#undef GTK_BOX
#define GTK_BOX Gtk::Box
#undef GTK_BUTTON
#define GTK_BUTTON Gtk::Button
#undef GTK_ENTRY
#define GTK_ENTRY Gtk::Entry
#undef GTK_FRAME
#define GTK_FRAME Gtk::Frame
#undef GTK_LABEL
#define GTK_LABEL Gtk::Label
#undef GTK_SCROLLED_WINDOW
#define GTK_SCROLLED_WINDOW Gtk::ScrolledWindow
#undef GTK_SELECTION_DATA
#define GTK_SELECTION_DATA Gtk::SelectionData
#undef GTK_SEPARATOR
#define GTK_SEPARATOR Gtk::Separator
#undef GTK_TARGET_ENTRY
#define GTK_TARGET_ENTRY Gtk::TargetEntry
#undef GTK_TOOLBAR
#define GTK_TOOLBAR Gtk::Toolbar
#undef GTK_WIDGET
#define GTK_WIDGET Gtk::Widget
#undef GTK_WINDOW
#define GTK_WINDOW Gtk::Window
