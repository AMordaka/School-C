#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>


using namespace std;

class Complex
{
private:
    double re;
    double im;
    
public:
    Complex();
    Complex(double rzecz, double zesp);	
    
    double zwraca_re();
    double zwraca_im();
    double amplituda(); 
    double faza();
    
    Complex& operator=(const Complex& liczba);
    Complex& operator+=(const Complex & liczba);
    Complex& operator-=(const Complex & liczba);
    Complex& operator*=(const Complex & liczba);
    Complex& operator/=(const Complex & liczba);
    
  
    Complex operator+(const double n) const;
    Complex operator-(const double n) const;
    Complex operator*(const double n) const;
    Complex operator/(const double n) const;
    
    
    Complex operator*(const Complex & liczba) const;
    Complex operator/(const Complex & liczba) const;
    Complex operator+(const Complex & liczba) const;
    Complex operator-(const Complex & liczba) const;
    bool operator==(const Complex & liczba) const;
    
    friend Complex operator*(double n, const Complex & liczba);
    friend Complex operator+(double n, const Complex & liczba);
    friend Complex operator-(double n, const Complex & liczba);
    friend Complex operator/(double n, const Complex & liczba);
    friend ostream& operator<<(ostream& os, const Complex & liczba);
    
};


#endif
