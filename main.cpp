#include <gtkmm.h>
#include "MyWindow.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("dev.hyun.kanapractice");

    return app->make_window_and_run<MyWindow>(argc, argv);
}