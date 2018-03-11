#include <iostream>
#include "Vector2DMaths.h"


int main()
{
	Vector2DMaths *calculate = new Vector2DMaths();
	//add to 2d //2d substract
	Vector2D *vecXY1 = new Vector2D(3.3,6.2);
	Vector2D *vecXY2 = new Vector2D(4.2, 12.7);
	//add to 3d//substract 3d 
	Vector3D *vecxy13D = new Vector3D(1.0, 4.5, 8.3);
    Vector3D *vecxy23D = new Vector3D(12.6, -4.5, 6.7);
	//dot product 2D
	Vector2D *dot2D1 = new Vector2D(7.5, 7.5);
	Vector2D *dot2D2 = new Vector2D(12.0, 0.0);
	//dot product 3D
	Vector3D *dot3D1 = new Vector3D(1.0, 4.5,8.3);
	Vector3D *dot3D2 = new Vector3D(12.6, 0.0, 6.7);
	//vector rotation 2D
	Vector2D *rotation2D = new  Vector2D(3.0, 4.0);
	double degree = 60;
	//scalar multiplication
	double scale = 3;
	//velovity vector
	double velocityVector = 20;
	double angle = 45;
	//projectile motion 2D
	Vector2D *carCoor = new Vector2D (0.0, 0.0);
	Vector2D *carCoor2 = new Vector2D(0.0, 0.0);
	Vector2D *carCoor3  = new Vector2D(0.0, 0.0);
	double timeStep = 0.02;
	double velocity = 30.0;
	double angle2 = 60.0;
	//projectile motion 3D
	Vector3D *ForceVec = new Vector3D(1.0, 1.0,0.0);
	Vector3D *initial3D = new Vector3D(0.0, 0.0,0.0);
	Vector3D *velPos = new Vector3D(0.0, 0.0,0.0);
	double  mass = 1;
	double giventime = 3.5;

	//Momentum
	Vector2D *balVell = new Vector2D(0.0, 0.0);
	Vector2D *velocityXY = new Vector2D(0.0,0.0);
	Vector2D *initialvelocity = new Vector2D(0.0, 4.0);
	Vector2D *eulorVelocity = new Vector2D(0.0, 0.0);
	Vector2D  *acceleration = new Vector2D(0.0, -0.1);
	Vector2D *vecotComponents = new Vector2D(0.0, 0.0);
	Vector2D *velXY2 = new Vector2D(0.0, 0.0);
	Vector2D *podXY2 = new Vector2D(0.0, 0.75);
	double angleMomentum = 30;
	double force = 1.0;
	double mass1 = 4.0;
	double mass2 = 4.0;
	double radius = 0.026;
	double timeStepMomentum = 0.02;

	// force mass1 mass2 radius  timeStepMomentum 

	//2 dimensional substraction
	Vector2D resultXY2D = calculate->addtoVectors(*vecXY1, *vecXY2);
	cout <<"2D X:" << resultXY2D.x << endl;

	cout <<"2D Y: "  << resultXY2D.y << endl;

	//3 dimensional addition 
	Vector3D resultXY3D = calculate->addtoVectors3D(*vecxy13D, *vecxy23D);

	cout << "3D X:" << resultXY3D.x << endl;

	cout << "3D Y: " << resultXY3D.y << endl;

	cout << "3D Z: " << resultXY3D.z << endl;

	
	//2 dimensional substraction
	Vector2D substration2D = calculate->substractVectors2D(*vecXY1, *vecXY2);

	cout << "2D x substraction:" << substration2D.x << endl;

	cout << "2D y substraction:" << substration2D.y << endl;

	//3 dimensional substraction
	Vector3D substration3D = calculate->substractVectors3D(*vecxy13D, *vecxy23D);
	
	cout << "3D x substraction:" << substration3D.x << endl;

	cout << "3D y substraction:" << substration3D.y << endl;

	cout << "3D z substraction:" << substration3D.z << endl;

	//dot product 2d
	Vector2D dotProduct2D = calculate->dotProductVectors2D(*dot2D1, *dot2D2);
	float dotProductResult = dotProduct2D.x + dotProduct2D.y;
	cout << "2D dot product:" << dotProductResult << endl;
	
	//dot product 3D
	Vector3D dotProduct3D = calculate->dotProductVectors3D(*dot3D1, *dot3D2);
	float dotProductResult3D = dotProduct3D.x + dotProduct3D.y + dotProduct3D.z;
	cout << "3D dot product:" << dotProductResult3D << endl;

	//unit vector 2d
	Vector2D unitVector2D = calculate->UnitVectors2D(*dot2D1);
	cout << unitVector2D.x << "i+" << unitVector2D.y << "j" << endl;

	Vector2D unitVector2D2 = calculate->UnitVectors2D(*dot2D2);
	cout << unitVector2D2.x << "i+" << unitVector2D2.y << "j" << endl;

	//unit vector 3D
	Vector3D unitVector3D = calculate->UnitVectors3D(*dot3D1);
	cout << unitVector3D.x << "i+" << unitVector3D.y << "j+" << unitVector3D.z << "k" << endl;

	Vector3D unitVector3D2 = calculate->UnitVectors3D(*dot3D2);
	cout << unitVector3D2.x << "i+" << unitVector3D2.y << "j+" << unitVector3D2.z << "k" << endl;

	//Vector rotation 2D
	Vector2D vector2D = calculate->vectorRotation2D(*rotation2D, degree);
	cout << "Vector rotation is:" << endl;
	cout << "X: " << vector2D.x << endl;
	cout << "Y: " << vector2D.y << endl;

	//magnitude 2D
	cout << "2D Magnitude: " << calculate->magnitude2d(*dot2D1) << endl;
	//magnitude 3D
	cout << "3D Magnitude:" << calculate->magnitude3D(*dot3D1) << endl;

	//scale2D
	Vector2D scale2D = calculate->scalar2D(*dot2D1, scale);
	cout << "2D Scalar multiplication" << endl;
	cout << "X: " << scale2D.x << endl;
	cout << "Y: " << scale2D.y << endl;
	//scale3D
	Vector3D scale3D = calculate->scalar3D(*dot3D1, scale);
	cout << "3D Scalar multiplication" << endl;
	cout << "X: " << scale3D.x << endl;
	cout << "Y: " << scale3D.y << endl;
	cout << "Z: " << scale3D.z << endl;

	//velocity vector
	Vector2D velVec2D = calculate->angle2D(velocityVector, angle);
	cout << "2D Vector Velocity" << endl;
	cout << "X: " << velVec2D.x << endl;
	cout << "Y: " << velVec2D.y << endl;

	//projectile motion
	// Vector2D prDis = calculate->projectileDis(carCoor, carCoor2, carCoor3, velocity, angle2, timeStep);

	cout << endl;
	cout << "2D PROJECTILE MOTION" << endl;
    calculate->projectileDis(*carCoor, *carCoor2, *carCoor3, &velocity, &angle2, &timeStep);
	cout << endl;

	cout << endl;
	cout << "3D PROJECTILE MOTION" << endl;
	calculate->projectileDi3D(*ForceVec,*initial3D, *velPos, &velocity,&angle2, &timeStep, &mass, &giventime);
	
	cout << endl;
	cout << "Momentum" << endl;
	calculate->Momentum(*velocityXY, *vecotComponents,*initialvelocity, *velXY2,*acceleration, *podXY2, *balVell,& angleMomentum, &force, &mass1, &mass2, &radius,&radius,  &timeStepMomentum);
	cout << endl;
	system("PAUSE");
	return 0;
}