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

long int RNG_Seed(unsigned int run_time, int times);
int RNG_Hardware(long int seed, int min, int max);
int RNG_Uniform(long int seed, int min, int max);
double RNG_Normal(long int seed, double mean, double dev);
double RNG_Exponential(long int seed, double mean);
int8_t RNG_Walk(long int seed, int *rand_num);

#ifdef __cplusplus
}
#endif

#endif /* _RANDOMIZER_H_ */