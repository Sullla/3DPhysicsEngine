#pragma once
#include <iostream>
#include "2DVector.h" 
#include "3DVector.h"

using namespace std;

class Vector2DMaths
{
private:
	double g;
	double pi;
	double timeStep;
	double velocityB = 0;
	double velocityA = 0;
public:
	
	double getG();
	double getpi();
	void setTimeS(double timestep);
	double getTimeS();

	void setvelocityB(double velocityB);
	double getVelocityB();
	void setvelocityA(double velocityB);
	double getVelocityA();
	//addiotion
	static Vector2D  addtoVectors(Vector2D vec1, Vector2D vec2);
	static Vector3D  addtoVectors3D(Vector3D vec1, Vector3D vec2 );
	//substraciton
	static Vector2D  substractVectors2D(Vector2D vec1, Vector2D vec2);
	static Vector3D  substractVectors3D(Vector3D vec1, Vector3D vec2);
	//dot product
	static Vector2D dotProductVectors2D(Vector2D vec1, Vector2D vec2);
	static Vector3D  dotProductVectors3D(Vector3D vec1, Vector3D vec2);
	//unit vector
	static Vector2D UnitVectors2D(Vector2D vec1);
	static Vector3D UnitVectors3D(Vector3D vec1);
	//vector rotation
	static Vector2D vectorRotation2D(Vector2D vec1, double degree);
	//Magnitude 2D
	static float magnitude2d(Vector2D vec1);
	//Magnitude 3D
	static float magnitude3D(Vector3D vec1);
	//scalar multiplication 2D
	static Vector2D scalar2D(Vector2D vec1, double scale);
	//scalar multiplication 3D
	static Vector3D scalar3D(Vector3D vec1, double scale);
	//velocity vector and launch angle
	static Vector2D angle2D(double velocity, double degreeAngle);
	//Projectile Motion 2D
	static void projectileDis(Vector2D vec1, Vector2D velocityXY, Vector2D velPos, double *velocity, double *launchAngle, double *h);
	//Projectile Motion 3D
	static Vector3D projectileDi3D(Vector3D vec1, Vector3D velocityXY, Vector3D velPos, double *velocity, double *launchAngle, double *h, double *mass, double *giventime);
	//Momentum
	static Vector2D Momentum( Vector2D velXY, Vector2D posXY, Vector2D initialVel, Vector2D vectorVelocity, Vector2D acceleration,  Vector2D posXY2, Vector2D ballVel2, double *angle, double *force, double *mass1, double *mass2, double *radius,double *radius2, double *h);
	static bool Collision(Vector2D vecoll1, Vector2D vecColl2,double radius1, double radius2);
};

	