#ifndef PHYSICALTEST_HPP_
#define PHYSICALTEST_HPP_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;



class PhysicalTest
{
protected:
	string comment;
	bool normal; // used to determine whether the patient has normal results
	bool testtaken; // 0 if data hasn't been inputted and 1 if it has
public:
	PhysicalTest();
	string writecomment(); //allows nurse/ doctor/ radiologist to comment
	bool istesttaken(); // determines if test has been taken for the use of a later results function
};


class Urinalysis: public PhysicalTest
{
protected:
	double UrinaryCalcium;
	double Sodium;
public:
	void taketest();
	void show();
	void checkhealthy(); 
	void addcomment();
};






class Vitals: public PhysicalTest
{
protected:
	int pulse;
	int respiratory;
public:
	void taketest();
	void show();
	void checkhealthy();
	void addcomment();
};


class BloodPressure: public PhysicalTest
{
protected:
	int SystolicPressure;
	int DiastolicPressure;
public:
	void taketest();
	void show();
	void checkhealthy();
	void addcomment();
};	


#endif //PHYSICALTEST_HPP_