/*
* ctimer.h
*
* Created on: 2009-7-13
*      Author: DEAN
*/

//////////////////////////////////////////////////////////////////////////
// This class provide a timer to finish some works.
// Call SetTimer() to set the timer_interval. Call StartTimer()
// to enable it and call StopTimer() to stop it.
// The work you want to do should be written on OnTimer
// function.
//////////////////////////////////////////////////////////////////////////

#ifndef CTIMER_H_
#define CTIMER_H_

#include <pthread.h>
#include <sys/time.h>

typedef void (*CallBackFun)(void);

class CTimer
{
private:
    pthread_t thread_timer;                                            //用于声明线程ID   sizeof（pthread_t）=4；
    long m_second, m_microsecond;
    static void *OnTimer_stub(void *p)
    {
        (static_cast<CTimer*>(p))->thread_proc();       //static_cast < type-id > ( expression )  该运算符把expression转换为type-id类型;
    }
    void thread_proc();                                                  
    void OnTimer();
    CallBackFun cbf;
public:
    CTimer();
    CTimer(long second, long microsecond);
    virtual ~CTimer();
    void SetTimer(long second,long microsecond);
    void StartTimer();
    void StopTimer();
    void SetCallBack(CallBackFun pCallBack);
    int count;
};
#endif /* CTIMER_H_ */
