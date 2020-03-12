#include <iostream>
#include "OOPLab2Bonus.h"
#include <vector>

using namespace std;

void Rational::set_num(int new_num) //numerator setter
{
    numerator = new_num;
}

int Rational::get_num() const //numerator getter
{
    return numerator;
}

void Rational::set_denom(int new_denom) //denominator setter
{
    if (new_denom == 0) 
    {
        throw exception{ "Can't set Denominator to 0!" };
    }
    else {
        denominator = new_denom;
    }
}

int Rational::get_denom() const //denominator getter
{
    return denominator;
}

Rational::Rational() //Default Constructor 
{
    set_num(0);
    set_denom(1);
    
}

Rational::Rational(int num, int denom) //Constructor for a value given in the form: numerator/denominator
{
    if (denom == 0)
        throw exception{ "Denominator can't be set to 0!" };

    if ((denom < 0) && (num < 0)) 
    {   
        num = num - (2 * num);
        denom = denom - (2 * denom);
        set_num(num);
        set_denom(denom);
    }
    
    if ((num > 0) && (denom < 0))
    {
        num = num - (2 * num);
        denom = denom - (2 * denom);
        set_num(num);
        set_denom(denom);
    }
    else 
    {
        set_num(num);
        set_denom(denom);
    }
}

int gcd(int a, int b) // Greatest Common Divisor
{
    if (a < 0) { a = a - (2 * a); };

    if (b < 0) { b = b - (2 * b); };

    if (a == b) { return a; };

    if ((a == 1) || (b == 1)) { return 1; };

    if (a == 0) { return b; };

    if (b == 0) { return a; };

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    };

    return a;
}

void Rational::simplify() //Simplifier
{

    int d = gcd(numerator, denominator);
    numerator = numerator / d;
    denominator = denominator / d;

}

Rational Rational::add(const Rational obj) //Add obj to our Rational Number 
{
    Rational Add;

    Add.numerator = (numerator * obj.denominator) + (denominator * obj.numerator);
    Add.denominator = denominator + obj.denominator;

    Add.simplify();

    Add.show_rat();

    return Add;
}

Rational Rational::mul(const Rational obj) //Multiply obj with our Rational Number
{   
    Rational Mul;

    Mul.numerator = numerator * obj.numerator;
    Mul.denominator = denominator * obj.denominator;
    Mul.simplify();

    Mul.show_rat();

    return Mul;

}

Rational Rational::div(const Rational obj) //Divide our Rational Number to obj
{   
    Rational Div;

    Rational temp_1(numerator, denominator);
    Rational temp_2(obj.denominator, obj.numerator);

    Div = temp_1.mul(temp_2);

    Div.show_rat();

    return Div;
}

Rational& Rational::operator=(const Rational& obj) //Assigment operator
{
    numerator = (obj.numerator);
    denominator = (obj.denominator);

    return *this;
}

Rational::Rational(const Rational& other) //Copy Constructor
{
    numerator = other.numerator;
    denominator = other.denominator;
}
      
void Rational::show_rat() const //Print Rational Number on standard output stream 
{   
    
    if (denominator == 1)
    {
        cout << "Our Rational Number is: " << numerator << " (" << numerator << "/" << denominator << ") " << "\n";
    }
    else if (denominator == -1)
    {
        int my_num = -numerator;
        int my_denom = -denominator;
        cout << "Our Rational Number is: " << my_num << " (" << my_num << "/" << my_denom << ") " << "\n";
    }
    else if ((denominator < 0) && (numerator > 0))
    {
        int my_num = -numerator;
        int my_denom = -denominator;
        cout << "Our Rational Number is : " << my_num << "/" << my_denom << "\n";
    }
    else
    {
        cout << "Our Rational Number is : " << numerator << "/" << denominator << "\n";
    }

}

double Rational::abs() const //Print the absolute value of our Rational Number on standard output stream
{
    Rational Abs;

    Abs.numerator = -numerator;
    Abs.denominator = denominator;

    double numu = Abs.numerator;
    double deno = Abs.denominator;

    double result = numu / deno;
    
    cout << "The absolut value of ";
    Abs.show_rat();
    cout << "OR " << result;

    return result;
}

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
}

void Summe(std::vector<Rational> vecti)
{
    Rational sum;

    typedef vector<Rational>::size_type vector_size;
    vector_size size = vecti.size();

    for (int i = 0; i < size; i++)
    {
        sum = sum.add(vecti[i]);
    }

    cout << "After the Summation of the Vector of Rational Numbers, The Result is also a Rational Number:\n";
    sum.show_rat();
}


int main()
{
    Rational r1(3, -2);
    Rational r2(-1, 2);

}
