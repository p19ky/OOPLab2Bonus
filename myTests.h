#pragma once
#include "OOPLab2Bonus.h"
using namespace std;
void sorti(std::vector<Rational> vecti)
{
    typedef vector<Rational>::size_type vector_size;
    vector_size size = vecti.size();

    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            double r1 = vecti[i].abs();
            double r2 = vecti[j].abs();
            if (r1 > r2)
            {
                Rational aux = vecti[i];
                vecti[i] = vecti[j];
                vecti[j] = aux;
            }
        }

	for (int i = 0; i < vecti.size(); i++)
		vecti[i].show_rat();
	cout << endl;
}

void Summe(std::vector<Rational> vecti)
{

    typedef vector<Rational>::size_type vector_size;
    vector_size size = vecti.size();

    for (int i = 1; i < size; i++)
        vecti[0] = vecti[0].add(vecti[i]);

    cout << "Sum is also a rational number, ";
    vecti[0].show_rat();
	cout << endl;
}

void myTests()
{
	Rational r1(-1, 2);
	Rational r2(6, 12);
	Rational r3(-5, 4);

	vector <Rational> v;
	v.push_back(r1);
	v.push_back(r2);
	v.push_back(r3);

	cout << "Test constructor\n";
	for (int i = 0; i < v.size(); i++)
		v[i].show_rat();
	cout << endl;

	cout << "Test simplify\n";
	for (int i = 0; i < v.size(); i++)
	{
		v[i].simplify();
		cout << "Simplified rational number(if possible): ";
		v[i].show_rat();
	}
	cout << endl;

	cout << "Test sum (all elements)\n";
    Summe(v);

	cout << "Test sort (all elements)\n";
	sorti(v);

	cout << "Test multiplication (r1 * r2)\n";
	r1.mul(r2);
	cout << endl;

	cout << "Test division (r1 / r2)\n";
	r1.div(r2);

}