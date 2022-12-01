#include "counter.h"
#include <QThread>

void Counter::run(){
    doCount();
}

void Counter::doCount(){
    running=true;
    count=0;
    while(isRunning()){

        count = count + 1 >100 ? 0:count+1;
        emit sendCount(count);
        QThread::sleep(1);
    }
}

void Counter::stop_counting(){
    const QMutexLocker locker(&m_mutex);
    emit sendCount(0);
    running= false;
}

bool Counter::isRunning(){
    const QMutexLocker locker(&m_mutex);
    return running;
}
