#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QThread>
#include <QMutex>

class Counter : public QThread
{
    Q_OBJECT

    void run() override;

    void doCount();
public:
    void start_counting();
    void stop_counting();
signals:
        void sendCount(int result);
private:
        bool isRunning();
        int count;
        bool running = false;
        mutable QMutex m_mutex;
};

#endif // COUNTER_H
