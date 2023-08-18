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
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264
#endif

long int RNG_Seed(unsigned int run_time, int times)
{
//from seed to seed    
    long int seed = 0;
    int8_t ts = times%3;
    do{
        if(run_time > 0)
		    srand(run_time - seed);
	    else if(run_time == 0)
		    srand(time(NULL) - seed);
        seed = rand();
        ts--;
    }while(ts < 0);

    return seed;
}

int RNG_Hardware(long int seed, int min, int max)
{
    system("cat /dev/random");
    return 0;
}

int RNG_Uniform(long int seed, int min, int max)
{
//return int-type numbers between min and max
    if(seed > 0)
		srand(seed);
	else if(seed == 0)
		srand(time(NULL));

    return rand()%(max+1-min)+min;
}

double RNG_Normal(long int seed, double mean, double dev)
{
//returns numbers based on normal distribution given mean and std dev
	if(seed > 0)
		srand(seed);
	else if(seed == 0)
		srand(time(NULL));
	//normal distribution centered on 0 with std dev of 1
	//Box-Muller transform	
	double randomNum_normal = sqrt(-2*log((rand()+1.0)/(RAND_MAX+1.0))) * cos(2*M_PI*(rand()+1.0)/(RAND_MAX+1.0));
	double random_out = mean + dev*randomNum_normal;

	return random_out;
}

double RNG_Exponential(long int seed, double mean)
{
//returns numbers based on exp distr given mean
	if(seed > 0)
		srand(seed);
	else if(seed == 0)
		srand(time(NULL));

	double inver = 1.0/mean; //inverse lambda
	double uni_rand; //this will be a uniform random variable 
 	double exp_value;

  	// Pull a uniform random number (0 < uni_rand < 1)
  	do
       	{
        	uni_rand = (double)RNG_Uniform(run_time, 0, RAND_MAX)/(RAND_MAX+1.0);
        }
    while ((uni_rand == 0) || (uni_rand == 1));
    exp_value = -inver * log(uni_rand);
  
    return(exp_value);
}

int8_t RNG_Walk(long int seed, int *rand_num)
{


    return 0;
}