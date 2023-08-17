/**********************************Copyright (c)**********************************
**                       版权所有 (C), 2020-present, 拟熵科技
**
**                             https://www.ventropy.cn
**
*********************************************************************************/
/**
 * @file    randomizer.c
 * @author  TIANMAKE
 * @version v1.0.0
 * @date    2023.6.30.
 * @brief   RNG.
 */
#include "randomizer.h"
#include <stdlib.h>
#include <time.h>

int RNG_Hardware(unsigned int run_time, int min, int max)
{
    system("cat /dev/random");
    return 0;
}

int RNG_Uniform(unsigned int run_time, int min, int max)
{
    srand(run_time);
    return rand()%(max+1-min)+min;
}

int8_t RNG_Normal(uint64_t run_time, int *rand_num){


    return 0;
}

int8_t RNG_Walk(uint64_t run_time, int *rand_num){


    return 0;
}