// -- IMPORTS

#include "SYSTEM/glib.hpp"
#include "SYSTEM/gtk.hpp"
#include "SYSTEM/std.hpp"
#include "FRAMEWORK/handle.hpp"
#include "VIEW/application_view.hpp"

// -- FUNCTIONS

int main(
    int argument_count,
    char * argument_array[]
    )
{
    GLIB_REFERENCE<GTK_APPLICATION>
        application;
    HANDLE<APPLICATION_VIEW>
        application_view;

    application = GTK_APPLICATION::create( argument_count, argument_array, "be.senselogic.chop" );
    application_view = new APPLICATION_VIEW();

    return application->run( *application_view );
}
