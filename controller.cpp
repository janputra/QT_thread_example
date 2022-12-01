#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

Controller::~Controller(){
    countThread->quit();
    countThread->wait();
}

void Controller::start(){
    countThread = new Counter;
   // counter->moveToThread(&countThread);
    connect(countThread, &QThread::finished,countThread,&QObject::deleteLater);
    connect(countThread,&Counter::sendCount,this,&Controller::displaycount);
    countThread->start();
}

void Controller::stop(){
    countThread->stop_counting();

}

void Controller::displaycount(int data){
    qml_count = data;
    emit new_count();
}
