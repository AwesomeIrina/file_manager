#ifndef FILES_MONITORING_H
#define FILES_MONITORING_H
#include <iostream>
#include <QObject>
#include <QVector>
#include <QString>
#include <map>

using namespace std;

//Стуктура, хранящая в себе следующую информацию:
//был ли файл отключён от мониторинга пользователем по команде disconnect
//был ли файл удалён (при удалении файла из директории, либо при изменении названия файла)
//размер файла - это поле сделано для того, чтобы можно было отследить изменение размера файла
struct file_info
{
    bool wasDisconnected;
    bool wasRemoved;
    qint32 size;

    file_info(bool a = false, bool b = false, qint32 c = 0)
    {
        wasDisconnected = a;
        wasRemoved = b;
        size = c;
    }

};


class Files_Monitoring: public QObject
{
    Q_OBJECT

private:
   QVector<QString> fileNames; //вектор, хранящий пути к файлам
   map <QString, file_info> accordance; //контейнер, ставящий соответствие: путь к файлу - информация о нём, которая хранится в полях структуры
   map<QString, QString> fileWatcher; //контейнер для отслеживания изменений
   static Files_Monitoring* singleton_;

   //конструктор по умолчанию. Здесь происходит подключение сигналов и слотов
   //конструктор в приватной зоне, поскольку это предотвращает создание множества объектов (для паттерна singleton)
   Files_Monitoring()
   {
       connect(this, &Files_Monitoring::helperAsked, this, &Files_Monitoring::helperCommand);
       connect(this, &Files_Monitoring::fileInformed, this, &Files_Monitoring::fileInfo);
       connect(this, &Files_Monitoring::fileAdded, this, &Files_Monitoring::fileAdd);
       connect(this, &Files_Monitoring::fileRemoved, this, &Files_Monitoring::fileDisconnect);
       connect(this, &Files_Monitoring::fileDisconnected, this, &Files_Monitoring::fileDisconnect);
       connect(this, &Files_Monitoring::fileSizeChanged, this, &Files_Monitoring::fileSizeChange);
       connect(this, &Files_Monitoring::fileAgainConnected, this, &Files_Monitoring::fileAgainConnect);
       console(); //функция, в которой запускается цикл while(true) для постоянного запроса у пользователя ввода команды
   }

   ~Files_Monitoring()
   {
       delete singleton_;
   }

public:
   //предотвращение создания копий
   Files_Monitoring(Files_Monitoring &other) = delete;
   void operator=(const Files_Monitoring &other) = delete;
   //статический метод, заменяющий конструктор
   static Files_Monitoring *getInstance();
   void anythingChanged();
   void check(const QString& condition, const QString& path);
   void console();

   //описание работы каждой функции в .cpp файле
   //инструкция по использованию и описание возможностей программы - в main.cpp
signals:
   void helperAsked();
   void fileAdded(const QString& fileName);
   void fileRemoved(const qint32& index);
   void fileDisconnected(const qint32& index);
   void fileInformed(const QString& fileNeme);
   void fileSizeChanged(const QString& fileName);
   void fileAgainConnected(const QString& fileName);

public slots:
   void helperCommand();
   void fileAdd(const QString& fileName);
   void fileDisconnect(const qint32& index);
   void fileInfo(const QString& fileName);
   void fileSizeChange(const QString& fileName);
   void fileAgainConnect(const QString& fileName);

};

#endif // FILES_MONITORING_H
