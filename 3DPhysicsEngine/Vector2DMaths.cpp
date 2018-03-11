#include <iostream>
#include "Vector2DMaths.h"



int timeS = 0;
double Vector2DMaths::getG() 
{
	g = 9.18;
	return g;
}
double Vector2DMaths::getpi()
{
	pi = 3.14;
	return pi;
}

void Vector2DMaths::setTimeS(double timeStep) 
{
	this->timeStep = timeStep;
}
double Vector2DMaths::getTimeS() 
{
	return this->timeStep;
}

void Vector2DMaths::setvelocityB(double velocityB)
{
	this->velocityB = velocityB;
}
double Vector2DMaths::getVelocityB()
{
	return this->velocityB;
}
void Vector2DMaths::setvelocityA(double velocityA) 
{
	this->velocityA = velocityA;
}
double Vector2DMaths::getVelocityA() 
{
	return this->velocityA;
}

Vector2D Vector2DMaths::addtoVectors(Vector2D vec1, Vector2D vec2)
{
	Vector2D *vecResult2D = new Vector2D();

	vecResult2D->x = vec1.x + vec2.x;
	vecResult2D->y = vec1.y + vec2.y;


	return *vecResult2D;
}

Vector3D Vector2DMaths::addtoVectors3D(Vector3D vec1, Vector3D vec2)
{
	Vector3D *vecResult3D = new Vector3D();
	
	vecResult3D->x = vec1.x + vec2.x;
	vecResult3D->y = vec1.y + vec2.y;
	vecResult3D->z = vec1.z + vec2.z;


	return *vecResult3D;
}
Vector2D Vector2DMaths::substractVectors2D(Vector2D vec1, Vector2D vec2) 
{

	Vector2D *vecSub2d = new Vector2D();

	vecSub2d->x = vec1.x - vec2.x;
	vecSub2d->y = vec1.y - vec2.y;
	return *vecSub2d;
}
Vector3D Vector2DMaths::substractVectors3D(Vector3D vec1, Vector3D vec2)
{

	Vector3D *vecSub3d = new Vector3D();

	vecSub3d->x = vec1.x - vec2.x;
	vecSub3d->y = vec1.y - vec2.y;
	vecSub3d->z = vec1.z - vec2.z;

	return *vecSub3d;
}
Vector2D Vector2DMaths::dotProductVectors2D(Vector2D vec1, Vector2D vec2) 
{
	Vector2D *vecdot2D = new Vector2D();
	vecdot2D->x = vec1.x * vec2.x;
	vecdot2D->y = vec1.y * vec2.y;
	

	return *vecdot2D;

}

Vector3D Vector2DMaths::dotProductVectors3D(Vector3D vec1, Vector3D vec2) 
{
	Vector3D *vecdot3D = new Vector3D();
	vecdot3D->x = vec1.x * vec2.x;
	vecdot3D->y = vec1.y * vec2.y;
	vecdot3D->z = vec1.z * vec2.z;
	
	return *vecdot3D;
	
}
Vector2D Vector2DMaths::UnitVectors2D(Vector2D vec1)
{
	Vector2D *vecunit2D = new Vector2D();
	vecunit2D->x = vec1.x / sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
	vecunit2D->y = vec1.y / sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
	
	return *vecunit2D;

}
Vector3D Vector2DMaths::UnitVectors3D(Vector3D vec1)
{
	Vector3D *vecunit3D = new Vector3D();
	vecunit3D->x = vec1.x / sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));
	vecunit3D->y = vec1.y / sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));
	vecunit3D->z = vec1.z / sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));

	return *vecunit3D;
}
Vector2D Vector2DMaths::vectorRotation2D(Vector2D vec1, double degree)
{
	// x = x cosf - y sinf
	// y = y cosf + x sinf
	Vector2D *vecRot2D = new Vector2D();
	vecRot2D->x = vec1.x * cos((3.14/180) * degree) - vec1.y* sin(degree);
	vecRot2D->y = vec1.y * cos((3.14/180) * degree) + vec1.x* sin(degree);

	return *vecRot2D;
}
float Vector2DMaths::magnitude2d(Vector2D vec1) 
{
	//magnitude = sqrt(x2 + y2 + z2)
	Vector2D *magni2D = new Vector2D();
	magni2D->x = vec1.x * vec1.x;
	magni2D->y = vec1.y * vec1.y;
	
	return  sqrt(magni2D->x + magni2D->y);

}
float Vector2DMaths::magnitude3D(Vector3D vec1)
{
	//magnitude = sqrt(x2 + y2 + z2)
	Vector3D *magni3D = new Vector3D();
	magni3D->x = vec1.x * vec1.x;
	magni3D->y = vec1.y * vec1.y;
	magni3D->z = vec1.z * vec1.z;

	return  sqrt(magni3D->x + magni3D->y + magni3D->z);
}
Vector2D Vector2DMaths::scalar2D(Vector2D vec1, double scale)
{
	Vector2D *scale2D = new Vector2D();
	scale2D->x = vec1.x * scale;
	scale2D->y = vec1.y * scale;

	return *scale2D;
}
Vector3D Vector2DMaths::scalar3D(Vector3D vec1, double scale)
{
	Vector3D *scale3D = new Vector3D();
	scale3D->x = vec1.x * scale;
	scale3D->y = vec1.y * scale;
	scale3D->z = vec1.z * scale;
	return *scale3D;
}
Vector2D Vector2DMaths::angle2D(double  velocity, double degreeAngle)
{
	Vector2D *velVec = new Vector2D();
	velVec->x = velocity * cos((3.14 / 180) *degreeAngle);
	velVec->y = velocity * sin((3.14 / 180) *degreeAngle);
	return *velVec;
}
//projectileMotion
void Vector2DMaths::projectileDis(Vector2D vec1, Vector2D velocityXY, Vector2D velPos, double *velocity, double *launchAngle, double *h)
{
	Vector2DMaths *gravity = new Vector2DMaths();

	Vector2D posXy;
	
	double timeOfFlight = 2 * *velocity*sin(*launchAngle) / gravity->getG();
	
	double xDis = 0.0;
	double yDis = 0.0;

	xDis = *velocity * timeOfFlight * cos(*launchAngle);
	yDis = *velocity * timeOfFlight * sin(*launchAngle) - 0.5*9.8*timeOfFlight * timeOfFlight;
	velocityXY.x = *velocity * cos((gravity->getpi() / 180) *  *launchAngle);
	velocityXY.y = *velocity * sin((gravity->getpi() / 180) *  *launchAngle);
	
		while(posXy.y>=0){
		
			gravity->setTimeS(gravity->getTimeS() + *h);
			vec1.x = velocityXY.x;
			vec1.y = velocityXY.y - gravity->getG()* gravity->getTimeS();
			velocityXY.x = vec1.x;
			velocityXY.y = vec1.y;
			
			posXy.x += vec1.x*gravity->getTimeS();
			cout <<"X:"<< posXy.x <<  " vel x " << vec1.x << endl;
			posXy.y += vec1.y*gravity->getTimeS();
			cout <<"Y:"<< posXy.y << "  vel y "<<vec1.y << endl;


			
			cout << gravity->getTimeS() << endl;
	}
	//return *posXy[];
	
}

Vector3D Vector2DMaths:: projectileDi3D(Vector3D ForceVector, Vector3D initialVel, Vector3D velPos, double *velocity, double *launchAngle, double *h, double *mass, double *givenTime)
{
	Vector2DMaths *gravity = new Vector2DMaths();
	Vector3D *posXy = new Vector3D();;
	double time = 5.0;
	
	
	//initialVel.x = *velocity * cos((gravity->getpi() / 180) *  *launchAngle)* sin((gravity->getpi() / 180) *  *launchAngle);
	//initialVel.y = *velocity * sin((gravity->getpi() / 180) *  *launchAngle) * sin((gravity->getpi() / 180) *  *launchAngle);
	//initialVel.z = *velocity *  cos((gravity->getpi() / 180)*  *launchAngle);
	while (posXy->y>=0)
	{

		gravity->setTimeS(gravity->getTimeS() + *h);

		velPos.x = (ForceVector.x * *givenTime)/ *mass*  + gravity->getTimeS();
		velPos.y = (ForceVector.y * *givenTime)/ *mass  - gravity->getG() * gravity->getTimeS();
		velPos.z = (ForceVector.z * *givenTime)/ *mass  +  gravity->getTimeS();

		

		posXy->x += velPos.x*gravity->getTimeS();
		cout << "X:" << posXy->x << " vel x " << velPos.x << endl;
		posXy->y += velPos.y*gravity->getTimeS();
		cout << "Y:" << posXy->y << "  vel y " << velPos.y << endl;
		posXy->z += velPos.z*gravity->getTimeS();
		cout << "z:" << posXy->z << "  vel z " << velPos.z << endl;

		cout << gravity->getTimeS() << endl;
	}
	return *posXy;
}
Vector2D Vector2DMaths::Momentum(Vector2D velXY, Vector2D vectorComponent, Vector2D initialVel, Vector2D velXY2, Vector2D acceleration, Vector2D posXY2, Vector2D ballVel2, double *angle, double *force, double *mass1, double *mass2, double *radius, double *radius2, double *h)
{
	//U^2 = Va^2 + Vb^2
	Vector2DMaths *constants = new Vector2DMaths();
	
	constants->setvelocityB(sqrt((initialVel.y * initialVel.y) - (constants->getVelocityA() * constants->getVelocityA())));
	constants->setvelocityA(initialVel.y *  sin(*angle * (constants->getpi() / 180)));

	velXY = constants->angle2D(constants->getVelocityA(), *angle);

	velXY2 = constants->angle2D(constants->getVelocityB(), *angle);


	Vector2D *ballpos = new Vector2D;
	while (!Collision(posXY2, *ballpos, *radius, *radius2))
	{
		
		constants->setTimeS(constants->getTimeS() + *h);
		vectorComponent.x = velXY.x + acceleration.x *  constants->getTimeS();
		vectorComponent.y = velXY.y + acceleration.y * constants->getTimeS();
		velXY = vectorComponent;

		ballpos->x += vectorComponent.x * constants->getTimeS();
		cout << "X:" << ballpos->x << " vel x " << vectorComponent.x << endl;
		ballpos->y += vectorComponent.y * constants->getTimeS();
		cout << "Y:" << ballpos->y << "  vel y " << vectorComponent.y << endl;



		if (Collision( posXY2, *ballpos, *radius, *radius2) == false)

		{
			cout << "IMAPCT" << endl;
			
			while (vectorComponent.y>=0)
			{
				constants->setTimeS(constants->getTimeS() + *h);
				vectorComponent.x = -velXY2.x + acceleration.x *  constants->getTimeS();
				vectorComponent.y = velXY2.y + acceleration.y * constants->getTimeS();
				velXY2 = vectorComponent;

				ballpos->x += vectorComponent.x * constants->getTimeS();
				cout << "X:" << ballpos->x << " vel x " << vectorComponent.x << endl;
				ballpos->y += vectorComponent.y * constants->getTimeS();
				cout << "Y:" << ballpos->y << "  vel y " << vectorComponent.y << endl;

			}

		}


		//a = F/mass
		//deltaV = a * deltaT
		//deltaP = v*deltaT    
		// -v1 = v2 *
		//deltaT = 1 - (deltad/deltaD)

		return *ballpos;
	}
}

bool Vector2DMaths::Collision(Vector2D vecoll1, Vector2D vecColl2, double radius1, double radius2)
{
	double sqrY = vecColl2.y -vecoll1.y;
	int radSum = radius1 + radius2;

	int collide =  (sqrY * sqrY) <= radSum * radSum;

	return collide;
}