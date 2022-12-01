#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "counter.h"

#include <QObject>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int qml_count READ get_count NOTIFY new_count)

   // QThread countThread;
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    int get_count(){return qml_count;};
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
public slots:
    void displaycount(int data);


signals:
    //void start_count();
    //void stop_count();
    void new_count();

private:
        int qml_count;
        Counter *countThread ;
};

#endif // CONTROLLER_H
