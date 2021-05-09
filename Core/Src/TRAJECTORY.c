// File name: TRAJECTORY.c
// Author: KRITTAPAK
// Project Name: Module8-9
// Group name: ISUS

#include "TRAJECTORY.h"
#include <math.h>

static trajectory_state trajectorys[NUM_TRAJECTORY];

void setuptrajectory(float xt, float yt, float vxt, float vyt, float c2, float c3){
	trajectory_state * trajectory = &trajectorys[NUM_TRAJECTORY];
	trajectory -> Xt = xt;
	trajectory -> Yt = yt;
	trajectory -> Vxt = vxt;
	trajectory -> Vyt = vyt;
	trajectory -> C2 = c2;
	trajectory -> C3 = c3;
}


float calculationsetup(float x_pos, float y_pos,float r, float ome, float x_en, float y_en){
	trajectory_state * trajectory = &trajectorys[NUM_TRAJECTORY];
	float tau = sqrt(pow((x_pos - x_en),2.0) + pow((y_pos - y_en),2.0));
	float theta = ome * tau;
	float x_posnew = x_pos + r*cos(theta);
	float y_posnew = y_pos + r*sin(theta);

	trajectory -> C2 = (3.0*(sqrt(pow((x_posnew - x_en),2.0) + pow((y_posnew - y_en),2.0))))/(pow(tau,2.0));
	trajectory -> C3 = ((-2.0)*(sqrt(pow((x_posnew - x_en),2.0) + pow((y_posnew - y_en),2.0))))/(pow(tau,3.0));

	return trajectory -> C2,trajectory -> C3, tau, x_posnew, y_posnew, theta;
}


float calculationtrajectory(float tau,float theta,float x_posnew, float y_posnew){
	trajectory_state * trajectory = &trajectorys[NUM_TRAJECTORY];
	float t;
	while(t <= tau){
		t += 1;
		float rt = (trajectory -> C2 * t *t) + (trajectory -> C3 *t*t*t);
		trajectory -> Xt = x_posnew + rt*cos(theta);
		trajectory -> Yt = y_posnew + rt*sin(theta);
	}
}
