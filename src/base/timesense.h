/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    timesense.h
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.7.
 * @brief   time sensing source.
 */

#ifndef _TIME_SENSE_H_
#define _TIME_SENSE_H_ 0

#ifdef __cplusplus
extern "C" {
#endif


#include <bits/types.h>

#define         RTC         0 //real time clock
#define         NTC         1 //network time clock

typedef struct{
    __int8_t idle;

}timespace_t;


__int8_t timesense_init(unsigned char mode);


#ifdef __cplusplus
}
#endif

#endif /* _TIME_SENSE_H_ */