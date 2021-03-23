#include <files_monitoring.h>
#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //введите команду "help" для получения списка команд, доступных пользователю
    //программа отслеживает изменение размера файла
    //при удалении файла из директории программа выведет соответствующее сообщение
    //если файл был удалён из директории, затем снова восстановлен, но его размер изменился - программа выведет соответсвующее сообщение

    QCoreApplication a(argc, argv);

    Files_Monitoring* exmpl = Files_Monitoring::getInstance();
    return a.exec();
}
