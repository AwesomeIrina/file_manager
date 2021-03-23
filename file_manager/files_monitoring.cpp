#include "files_monitoring.h"
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QString>
#include <QTextStream>
#include <fstream>
#include <windows.h>

using namespace std;

Files_Monitoring* Files_Monitoring:: singleton_ = nullptr;

//при первом запуске создаётся экземпляр и помещается в статическое поле
//при дальнейших запусках возвращается объект, хранящийся в статическом поле
Files_Monitoring *Files_Monitoring::getInstance()
{
    if(singleton_ == nullptr){
        singleton_ = new Files_Monitoring();
    }
    return singleton_;
}

//вызывается при получении команды "help". Здесь описаны все действия, доступные пользователю
void Files_Monitoring::helperCommand()
{
    std::cout << "add - to add the file in the vector of the names" << std::endl;
    std::cout << "disconnect - to disconnect the file from the monitoring" << std::endl;
    std::cout << "info - to get info about the file" << std::endl;
    std::cout << "list - to show the list of files names" << std::endl;
    std::cout << "watch - to show all changes" << std::endl;
}

//метод, работающий с контейнером map
//меняет поля структуры file_info при изменении соответствующей информации
//на вход функции идёт строка - информация о действии с файлом и путь к файлу
//например, если пользователь удалил файл из директории или изменил название,
//вызывается сигнал fileRemoved, а вместе с ним в метод check поступает строка "remove",
//в поле контейнера map, соответствующего пути к удалённому файлу, поле структруы wasRemoved изменяется с false на true
//Если же пользователь меняет размер файла, вызывается сигнал fileSizeChanged и в check поступает строка "size"
//тогда меняется информация в поле size структуры file_info
void Files_Monitoring::check(const QString& condition, const QString& path)
{

    if(condition == "add")
    {
        qint32 size = QFileInfo(path).size();
        accordance.insert(pair<QString, file_info>(path, file_info(false, false, size)));
        fileWatcher.insert(pair<QString, QString>(path,"was added. Size is " + QString::number(size)));
    }

    if(condition == "remove")
    {
        qint32 size = accordance[path].size;
        accordance[path] = file_info(false, true, size);
        if(fileWatcher.count(path) != 0)
        {
            fileWatcher[path] = "was removed";
        }

        else
        {
            fileWatcher.insert(pair<QString, QString>(path, "was removed"));
        }
    }

    if(condition == "disconnect")
    {
        qint32 size = accordance[path].size;
        accordance[path] = file_info(true, false, size);
        if(fileWatcher.count(path) != 0)
        {
            fileWatcher[path] = "was disconnected from the monitoring";
        }

        else
        {
            fileWatcher.insert(pair<QString, QString>(path, "was disconnected from the monitoring"));
        }
    }

    if(condition == "size")
    {
        qint32 size = QFileInfo(path).size();
        accordance[path] = file_info(false, false, size);
        if(fileWatcher.count(path) != 0)
        {
            fileWatcher[path] = "'s size was changed. Now it is " + QString::number(size);
        }

        else
        {
            fileWatcher.insert(pair<QString, QString>(path, "'s size was changed. Now it is " + QString::number(size)));
        }
    }

    if(condition == "exists")
    {
        qint32 size = QFileInfo(path).size();
        accordance[path] = file_info(false, false, size);
        if(fileWatcher.count(path) != 0)
        {
            fileWatcher[path] = "was connected to the monitoring again. Size is " + QString::number(size);
        }

        else
        {
            fileWatcher.insert(pair<QString, QString>(path, "was connected to the monitoring again. Size is " + QString::number(size)));
        }
    }
}

//Метод проверяет изменения, произошедшие в программе
//Минус работы функции - я не смогла разобраться с многопоточностью в С++,
//поэтому метод запускается вначале цикла while, а затем в конце, чтобы не было задержки информации
void Files_Monitoring::anythingChanged()
{
    //смотрю, удалён ли файл
    for (qint32 i = 0; i < fileNames.size(); i++)
    {
        //если файл был удалён, в метод check посылается соответсвующая строка
        //происходит изменение поля "wasRemoved" структуры file_info
        //вызывается сигнал fileRemoved, подключённый к слоту fileDisconnect, происходит удаление пути к файлу из вектора fileNames
        if (!QFileInfo(fileNames[i]).exists())
        {
            check("remove", fileNames[i]);
            emit fileRemoved(i);
            return ;
        }
    }

    //цикл, проходящий по контейнеру map
    for(auto it = accordance.begin(); it != accordance.end(); ++it)
    {
        //если файл был удалён из директории(либо изменено название), то есть поле wasRemoved == true
        //но при этом файл снова появился в директории, вызываю сигнал fileAgainConnected, соединённый со слотом fileAgainConnect
        //пользователь получает сообщение о том, что файл снова существует, а путь к файлу заносится в вектор fileNames
        if(it->second.wasRemoved == true && QFileInfo(it->first).exists())
        {
            emit fileAgainConnected(it->first);
            check("exists", it->first);
        }

        //проверяю изменение размера файла, цикл проходит по контейнеру map
        if(it->second.wasRemoved != true && it->second.wasDisconnected != true )
        {
            //если информация в поле size стурктуры file_info не соответствует текущему размеру файла,
            //вызывается сигнал fileSizeChanged, соединённый со слотом fileSizeChange,
            //пользователь получает сообщение об изменении размера, а также о дате и времени изменения размера
            if(it->second.size != QFileInfo(it->first).size())
            {
                check("size", it->first);
                emit fileSizeChanged(it->first);
            }
        }
    }
}

//В этом методе происходит добавление файла
//на вход подаётся строка, содержащая путь к файлу
void Files_Monitoring::fileAdd(const QString& fileName)
{
    //проверка, существует ли такой файл в директории
    if (QFileInfo(fileName).exists())
    {
        //если файл существует, проверяю, есть ли путь к этому файлу в векторе fileNames
        //если такой путь уже существует, пользователь получает соответсвующее сообщение
        for(qint32 i = 0; i < fileNames.size(); i++)
        {
            if (fileNames[i] == fileName)
            {
                cout<<"This file is monitoring already"<<endl;
                return ;
            }
        }
        //если же в векторе fileNames нет такого пути, путь заносится в вектор fileNames,
        //а пользователь получает соответствующее сообщение
        //в метод check поступает сообщение "add"
        //создаётся новое поле в контейнере, где первая компонента - это путь к файлу
        //вторая - это поле типа file_info
        //поля wasDisconnected и wasRemoved принимают значения false, а в поле size записывается текущий размер файла
        fileNames.push_back(fileName);
        QTextStream(stdout) << fileName << " was added" << endl;
        check("add", fileName);
    }
    // если такого файла не существует, пользователь получает соответствующее сообщение
    else
    {
        QTextStream(stdout) << fileName << " does not exists!" << endl;
    }

    //если пользователь удалил файл по команде disconnect, то есть захотел прекратить наблюдение,
    //а затем снова добавил файл по команде add, в map не создаётся нового поля с путём к файлу,
    //map содержит только уникальные имена, поэтому информация о файле просто обновляется,
    //то есть поле wasDisconnected меняется с true на false, а также обновляется размер файла
}

//если пользователь ввёл команду "disconnect", либо же файл был удалён из директории, пользователь получает сообщение об этом,
//а путь к файлу удаляется из вектора имён
void Files_Monitoring::fileDisconnect(const qint32& index)
{
    QTextStream(stdout) << fileNames[index] << " was disconnected from the monitoring!" << endl;
    fileNames.remove(index);
}

//путь к файлу заносится в вектор fileNames
//также здесь проверяется изменение размера файла
//то есть если файл пропал из директории, но затем был возвращён,
//сравниватся текущий размер файла и размер файла из поля size структуры file_info
void Files_Monitoring::fileAgainConnect(const QString& fileName)
{
    QTextStream(stdout)<< "The file " << fileName << " is connected to the monitoring again" << endl;
    if(accordance[fileName].size != QFileInfo(fileName).size())
    {
        check("size", fileName);
        emit fileSizeChanged(fileName);
    }
    fileNames.push_back(fileName);
}

//пользователь получает сообщение об изменении размера файла, а также о дате и времени последнего изменения
void Files_Monitoring::fileSizeChange(const QString& fileName)
{
    QTextStream(stdout)<< "The size of the " << fileName << " was changed " << QFileInfo(fileName).lastModified().toString() << ". Now size is " << QFileInfo(fileName).size()<<endl;
}

//метод, выводящий следующую информацию о файле:
//-дату и время создания
//-дату и время последнего изменения
//-текущий размер файла
void Files_Monitoring::fileInfo(const QString& fileName)
{
    bool existing = false;
    //проверяю, отслуживается ли файл в данный момент
    for(qint32 i = 0; i < fileNames.size(); i++)
    {
        if(fileNames[i] == fileName)
        {
            existing = true;
        }
    }

    //если файл отслеживается, выводится информация о файле
    if(existing)
    {
        QTextStream(stdout)<< "Date of creation of the file " << fileName << " is " << QFileInfo(fileName).created().toString() << endl;
        QTextStream(stdout)<< "Date of the last modification of the file " << fileName << " is " << QFileInfo(fileName).lastModified().toString() << endl;
        QTextStream(stdout)<< "Size of the file " << fileName << " is " << accordance[fileName].size<< endl;
    }

    else
    {
        //если файл не отслеживается, но существует в директории, выводится соответствующее сообщение
        if(QFileInfo(fileName).exists())
        {
            QTextStream(stdout)<<fileName<<" is not monitoring"<<endl;
        }
        //если файла не существует в директории, выводится соответствующее сообщение
        else
        {
            QTextStream(stdout)<<fileName<<" does not exist"<<endl;
        }
    }
}

//метод, выводящий сообщение с просьбой ввести команду
void Files_Monitoring:: console()
{
    cout << "Input 'help' to get the list of the commands" << endl;
    while(true)
    {
        //Нужно для того, чтобы считывались русские символы
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        QString command;

        QTextStream cout(stdout), cin(stdin);

        cout << "Input the command: " << endl;

        //команда считывается, а затем вызвается соответсвующий сигнал (либо выводится список путей к файлу,
        //если пользователь запросил команду "list"
        command = cin.readLine().trimmed().toLower();

        anythingChanged();

        //если была введена команда, которой нет в списке команд, пользователь получает соответсвтующее сообщение
        if(command != "help" && command != "info" && command != "list" && command != "add" && command != "disconnect" && command !="watch")
        {
            cout<<"Incorrect command"<<endl;
        }

        if(command != "watch")
        {
            //очищаю контейнер, чтобы информаци обновилась на очередном проходе
            fileWatcher.clear();
        }

        if(command == "help")
        {
            emit helperAsked();
        }

        if (command == "info")
        {
            cout<<"Input path to the file you want to get info: "<< endl;
            QString fileName = cin.readLine().trimmed().toLower();
            emit fileInfo(fileName);
        }

        if (command == "list")
        {
            if(fileNames.size() == 0)
            {
                //если вектор пуст, пользователь получает соответсвующее сообщение
                cout<<"There is no monitoring files"<<endl;
            }

            else
            {
                for (qint32 i = 0; i < fileNames.size(); i++)
                {
                    QTextStream(stdout) << i << ") " << fileNames[i] << endl;
                    emit fileInfo(fileNames[i]);
                }
            }
        }

        if (command == "add")
        {
            cout << "Enter your path to the file: " << endl;
            QString pathToFile = cin.readLine().trimmed().toLower();
            emit fileAdded(pathToFile);
        }

        if(command == "disconnect")
        {
            cout << "Input index of the file you want to remove: " << endl;
            qint32 index = cin.readLine().trimmed().toInt();
            //при удалении пути к файлу из вектора filenames у пользователя запрашивается индекс соответсвующего поля вектора
            //если индекс некорректный, пользователь получается сообщение об этом
            if(index < 0 || index > fileNames.size())
            {
                cout<<"Incorrect index"<<endl;
            }
            else
            {
                check("disconnect", fileNames[index]);
                emit fileDisconnected(index);
            }
        }

        anythingChanged();

        //После очередного прохода функции anythingChanged все изменения занесены в контейнер fileWatcher,
        //и по требованию пользователя их можно вывести
        if(command == "watch")
        {
            if(fileWatcher.size() == 0)
            {
                cout<<"There are no changes to any file"<<endl;
            }
            else
            {
                cout<< "There is the list of the files that was changed" <<endl;
                for(auto it = fileWatcher.begin(); it != fileWatcher.end(); ++it)
                {
                    QTextStream(stdout)<<it->first<<" "<<it->second<<endl;
                }
            }
        }
    }
}
