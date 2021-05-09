// File name: TRAJECTORY.h
// Author: KRITTAPAK
// Project Name: Module8-9
// Group name: ISUS

#ifndef __TRAJECTORY_H
#define __TRAJECTORY_H

#include "stm32h7xx_hal.h"

#define NUM_TRAJECTORY 4

typedef struct{
	//number
	int number;

	//x, y trajectory
	volatile float Xt, Yt;

	//vx vy trajectory
	volatile float Vxt, Vyt;

	//constant c2 c3
	volatile float C2, C3;


}trajectory_state;

void setuptrajectory(float xt, float yt, float vxt, float vyt, float c2, float c3);

float calculationsetup(float x_pos, float y_pos,float r, float ome, float x_en, float y_en);

float calculationtrajectory(float tau,float theta,float x_posnew, float y_posnew);

#endif /* __TRAJECTORY_H */
