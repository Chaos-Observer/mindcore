/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    randomizer.h
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.30.
 * @brief   RNG.
 */
#ifndef _RANDOMIZER_H_
#define _RANDOMIZER_H_ 1

//0、uniform
//1、normal
//2、walk

#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <stdint.h>

int RNG_Hardware(unsigned int run_time, int min, int max);
int RNG_Uniform(unsigned int run_time, int min, int max);
int8_t RNG_Normal(uint64_t run_time, int *rand_num);
int8_t RNG_Walk(uint64_t run_time, int *rand_num);

#ifdef __cplusplus
}
#endif

#endif /* _RANDOMIZER_H_ */