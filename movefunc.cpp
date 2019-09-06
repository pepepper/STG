#define _USE_MATH_DEFINES
#include <math.h>
void MoveStraightVertical(double *x, double *y, int period) {
	*y += 0.2;
}

void MoveStraightHorizontal(double *x, double *y, int period) {
	*x += 0.1;
}

void MoveStraightFromLeftUp(double *x, double *y, int period) {
	*x += 0.1;
	*y -= 0.1;
}

void MoveStraightFromRightUp(double *x, double *y, int period) {
	*x -= 0.1;
	*y -= 0.1;
}

void MoveFromLeft1(double *x, double *y, int period) {
	if (period < 300) {
		*x += 0.5;
		*y = 320 - (period*period * 4 / 1125);
	} else if (period < 320) {} else {
		*y += 0.5;
	}
	return;
}

void MoveFromLeft2(double *x, double *y, int period) {
	if (period < 400) {
		*x += 0.5;
		*y = 320 - (period *period / 500);
	} else if (period < 420) {} else {
		*y += 0.5;
	}
	return;
}
void MoveFromLeft3(double *x, double *y, int period) {
	if (period < 600) {
		*x += 0.5;
		*y = 320 - (period *period / 1125);
	} else if (period < 620) {} else {
		*y += 0.5;
	}
	return;
}

void MoveFromRight1(double *x, double *y, int period) {
	if (period < 300) {
		*x -= 0.5;
		*y = 320 - (period*period * 4 / 1125);
	} else if (period < 320) {} else {
		*y += 0.5;
	}
	return;
}

void MoveFromRight2(double *x, double *y, int period) {
	if (period < 400) {
		*x -= 0.5;
		*y = 320 - (period *period / 500);
	} else if (period < 420) {} else {
		*y += 0.5;
	}
	return;
}

void MoveFromRight3(double *x, double *y, int period) {
	if (period < 600) {
		*x -= 0.5;
		*y = 320 - (period *period / 1125);
	} else if (period < 620) {} else {
		*y += 0.5;
	}
	return;
}

void BulletMoveStraight(double *x, double *y, int period, int type, double data) {
	*x += sin(M_PI*data / 180)*(double)(5- type);
	*y += cos(M_PI *data / 180)*(double)(5- type);
}

void BulletMoveSine(double *x, double *y, int period, int type, double data) {
	*x += sin(M_PI * period/180*data) * 2.0;
	*y += 1.0;
}