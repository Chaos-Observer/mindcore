/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    heartbeat.c
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.7.
 * @brief   Heartbeat self-excitation source.
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <timer.h>

#include "heartbeat.h"


static void __timer_handle(union sigval sigev)
{
    timer_handle_t* p_timer = (timer_handle_t*)(sigev.sival_ptr);

    p_timer->callback(p_timer->argv);
}


timer_handle_t* heartbeat_init(timer_type_t type, timer_cb_t cb,
                                timer_argv_t argv){
    timer_handle_t* p_timer
        = (timer_handle_t*)calloc(sizeof(timer_handle_t), sizeof(uint8_t));

    if (NULL == p_timer) {
        printf("Timer creation failed, insufficient memory\r\n");
        return NULL;
    }

    p_timer->type = type;
    p_timer->argv = argv;
    p_timer->callback = cb;
    // memset(&evp, 0, sizeof(struct sigevent));
    struct sigevent evp = { .sigev_notify = SIGEV_THREAD,
                            .sigev_value.sival_ptr = (void*)p_timer,
                            .sigev_notify_function = __timer_handle };

    if (-1 == timer_create(CLOCK_REALTIME, &evp, &(p_timer->timerid))) {
        printf("Timer create failed!!!\r\n");
        free(p_timer);
        p_timer = NULL;
        return NULL;
    }

    return p_timer;
}

void heartbeat_exit(timer_handle_t* p_timer){
    if (-1 == timer_delete(p_timer->timerid))
        printf("Timer delete failed\r\n");

    free(p_timer);
    p_timer = NULL;
}

void heartbeat_start(timer_handle_t* p_timer, timer_tick_ms_t tick){
    struct itimerspec its;

    if (TIMER_TYPE_PERIODIC == p_timer->type) {
        its.it_interval.tv_sec = tick / 1000;
        its.it_interval.tv_nsec = tick % 1000 * 1000000;
    } else {
        its.it_interval.tv_sec = 0x00;
        its.it_interval.tv_nsec = 0x00;
    }

    its.it_value.tv_sec = tick / 1000;
    its.it_value.tv_nsec = tick % 1000 * 1000000;

    if (-1 == timer_settime(p_timer->timerid, 0, &its, NULL)) {
        printf("Timer start failed\r\n");
        free(p_timer);
        p_timer = NULL;
    }
}


void heartbeat_stop(timer_handle_t* p_timer){
    struct itimerspec its;

    its.it_interval.tv_sec = 0x00;
    its.it_interval.tv_nsec = 0x00;

    its.it_value.tv_sec = 0x00;
    its.it_value.tv_nsec = 0x00;

    if (-1 == timer_settime(p_timer->timerid, 0, &its, NULL)) {
        printf("Timer stop failed\r\n");
        free(p_timer);
        p_timer = NULL;
    }

}