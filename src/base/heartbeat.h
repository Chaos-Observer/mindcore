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


#ifndef _HEART_BEAT_H_
#define _HEART_BEAT_H_ 3

#ifdef __cplusplus
extern "C" {
#endif


#include <bits/types.h>
#include <linux/types.h>

typedef struct{
    __timer_t timer;
    __int8_t number;
    __int8_t tick;


__int8_t (*heartbeat_init)(unsigned char mode);
void (*heartbeat_exit)();
__int8_t (*heartbeat_start)(heartbeat_t *ptr);
__int8_t (*heartbeat_stop)();

}heartbeat_t;

__int8_t heartbeat_init(unsigned char mode);
void heartbeat_exit();
__int8_t heartbeat_start(__int8_t *ptr);
__int8_t heartbeat_stop();


#ifdef __cplusplus
}
#endif

#endif