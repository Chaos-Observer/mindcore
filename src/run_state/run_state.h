/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    run_state.h
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.7
 * @brief   running state machine.
 */


#ifndef _RUN_STATE_H_
#define _RUN_STATE_H_ 1

#ifdef __cplusplus
extern "C" {
#endif


#include <bits/types.h>

typedef struct run_state{
    __int8_t next_state;
    __int8_t state;

__int8_t (*state_oprate)(unsigned char mode);

}run_state_t;

#ifdef __cplusplus
}
#endif

#endif