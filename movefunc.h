#pragma once
void MoveStraightVertical(double *x, double *y, int period);
void MoveStraightHorizontal(double *x, double *y, int period);
void MoveStraightFromRightUp(double *x, double *y, int period);
void MoveStraightFromLeftUp(double *x, double *y, int period);

void MoveFromLeft1(double *x, double *y, int period);
void MoveFromLeft2(double *x, double *y, int period);
void MoveFromLeft3(double *x, double *y, int period);

void MoveFromRight1(double *x, double *y, int period);
void MoveFromRight2(double *x, double *y, int period);
void MoveFromRight3(double *x, double *y, int period);

void BulletMoveStraight(double *x, double *y, int period, int type, double data);

void BulletMoveSine(double *x, double *y, int period, int type, double data);