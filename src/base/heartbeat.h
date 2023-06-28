/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    heartbeat.h
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.7
 * @brief   Heartbeat self-excitation source.
 */
// timer_create():创建一个新的timer；并且指定定时器到时间通知装置
// timer_delete():删除一个timer
// timer_gettime():获取剩余时间
// timer_settime():开始或停止某个定时器
// timer_getoverrun():获取丢失的定时器通知个数


#ifndef _HEART_BEAT_H_
#define _HEART_BEAT_H_ 3

#ifdef __cplusplus
extern "C" {
#endif
/* posix timer wrapper */
#define TICK_DEFAULT_VALUE 1 /* 1ms */

#include <time.h>
#include <linux/types.h>

#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*timer_cb_t)(void*);
typedef void* timer_argv_t;
typedef uint32_t timer_tick_ms_t;

struct timespec
{    
    long    tv_sec;
    long    tv_nsec;
};
struct itimerspec
{
     struct timespec it_value;//初次启动时间
     struct timespec it_interval;//定时时间
};

typedef enum {
    TIMER_TYPE_ONESHORT = 0u,
    TIMER_TYPE_PERIODIC,
    TIMER_TYPE_MAX
} timer_type_t;

typedef struct _timer_handle_t {
    timer_t timerid; ///< timer id
    timer_type_t type; ///< timer options
    timer_cb_t callback; ///< timer callback
    timer_argv_t argv; ///< timer argument vector
} timer_handle_t;


struct sigevent
{ 
    int sigev_notify;   //设置定时器到期后的行为
    int sigev_signo;    //设置产生信号的信号码
    union sigval sigev_value; //设置产生信号的值
    void (*sigev_notify_function)(union sigval);//定时器到期，从该地址启动一个线程
    pthread_attr_t *sigev_notify_attributes;    //创建线程的属性
};
union sigval
{
    int sival_int; //integer value
    void *sival_ptr; //pointer value 
};

typedef enum {
SIGEV_NONE = 0, /* 当计时器到期不进行异步通知 */
SIGEV_SIGNAL, /* 到计时器到期时，在进程中产生信号量 sigev_signo */
SIGEV_THREAD, /*  到计时器到期时，调用 sigev_notify_function 好像它是一个新线程的启动函数 */
SIGEV_THREAD_ID, /*   类似 SIGEV_SIGNAL，但信号量signal 针对由 sigev_notify_thread_id 指定的线程，这个线程必须和调用线程在同一个进程中 */
SIGEV_MAX
} sigev_t;


typedef enum {
CLOCK_REALTIME = 0, /* Systemwide realtime clock. 一个可设置的系统范围内的实时时钟，计算从1970年1月1日午夜0点起的毫秒数 */
CLOCK_MONOTONIC, /* Represents monotonic time. Cannot be set. 一个不可设置的单调增加时钟，它测度系统启动后某个非特定时间点起的时间 */
CLOCK_PROCESS_CPUTIME_ID, /* High resolution per-process timer. 这个时钟测量调用进程（包含其中所有线程）所消耗的 (用户和系统) CPU 时间 */
CLOCK_THREAD_CPUTIME_ID, /* Thread-specific timer. 这个时钟测量调用线程所消耗的 (用户和系统) CPU 时间*/
CLOCK_REALTIME_HR, /* High resolution version of CLOCK_REALTIME. */
CLOCK_MONOTONIC_HR, /* High resolution version of CLOCK_MONOTONIC. */
CLOCK_MAX
} clockid_t;

typedef struct{
    uint32_t tick_number;


timer_handle_t* (*heartbeat_init)(timer_type_t type, timer_cb_t cb,
                                timer_argv_t argv);
void (*heartbeat_exit)(timer_handle_t* timer_handle);
void (*heartbeat_start)(timer_handle_t* timer_handle, timer_tick_ms_t tick);
void (*heartbeat_stop)(timer_handle_t* timer_handle);

} heartbeat_t;



timer_handle_t* heartbeat_init(timer_type_t type, timer_cb_t cb,
                                timer_argv_t argv);
void heartbeat_exit(timer_handle_t* p_timer);
void heartbeat_start(timer_handle_t* p_timer, timer_tick_ms_t tick);
void heartbeat_stop(timer_handle_t* p_timer);


#ifdef __cplusplus
}
#endif

#endif /* _HEART_BEAT_H_ */