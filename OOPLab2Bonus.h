#pragma once

class Rational
{
private:
	 
	int numerator;
	int denominator;

public:

	Rational(); //Default Constructor

	Rational(int num, int denom); //Constructor for a value given in the form: numerator/denominator 

	void set_num(int num); //numerator setter

	int get_num() const; //numerator getter

	void set_denom(int denom); //denominator setter

	int get_denom() const; //denominator getter

	void simplify(); //Simplify form of the Rational Number

	Rational add(const Rational obj); //Add obj to our Rational Number 
										//-It doesn't change our Rational Number.

	Rational mul(const Rational obj); //Multiply obj with our Rational Number 
										//-It doesn't change our Rational Number.

	Rational div(const Rational obj); //Divide our Rational Number to obj
										//-It doesn't change our Rational Number.

	Rational& operator=(const Rational& obj); //Assigment operator

	Rational(const Rational& other); //Copy Constructor

	void show_rat() const; //Print Rational Number on standard output stream 

	double abs() const ; //Print the absolute value of our Rational Number

};