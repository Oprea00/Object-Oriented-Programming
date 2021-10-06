#include "a89.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    Repository* repository;
    repository = new HtmlRepository{ "events.txt", "list.html" };
    Controller controller{ *repository };

    GUI gui{controller};
    gui.show();

    return a.exec();
}
