#include "complex.h"
#include <cmath>
#define PI 3.14
using namespace std;

    Complex::Complex()
    {
        re = 0;
        im = 0;
    }
    
    Complex::Complex(double rzecz, double zesp)
    {
        this->re = rzecz;
        this->im = zesp;
    }
     
    double Complex::zwraca_re()
    {
        double rzecz;
        rzecz = this->re;
        return rzecz;
    }
    
    double Complex::zwraca_im()
    {
        double img;
        img = this->im;
        return img;
    }
    
    double Complex::amplituda()
	{
		return sqrt(re * re + im * im);
	}
	
	double Complex::faza()
	{
		if(re > 0)
		{
			return(atan(im / re));
		}
		else if(re < 0)
		{
			return(atan(im / re)) + PI;
		}
		else if((re == 0) && (im > 0))
		{
			return PI/2;
		}
		else if((re == 0) && (im < 0))
		{
			return PI/2;
		}
		else 
		{
			return 0;
		}
		
		
	}
	
    Complex& Complex::operator=(const Complex & liczba)
    {
    	this->re = liczba.re;
    	this->im = liczba.im;
    	return *this;
	}
	
	Complex& Complex::operator+=(const Complex & liczba)
	{
		this->re = this->re + liczba.re;
		this->im = this->im + liczba.im;
		return *this;
	}
	
	Complex& Complex::operator-=(const Complex & liczba)
	{
		this->re = this->re - liczba.re;
		this->im = this->im - liczba.im;
		return *this;
	}
	
	Complex& Complex::operator*=(const Complex & liczba)
	{
		double temp = this->re;
		this->re = (temp * liczba.re) - (this->im * liczba.im);
		this->im = (temp * liczba.im) + (this->im * liczba.re);
		return *this;
	}
	
	Complex& Complex::operator/=(const Complex & liczba)
	{
		double temp = this->re;
    	this->re = (temp * liczba.re + this->im * liczba.im) / (liczba.re * liczba.re + liczba.im * liczba.im);
    	this->im = -(temp * liczba.im - this->im * liczba.re) / (liczba.re * liczba.re + liczba.im * liczba.im);
    	return *this;
	}
	

	Complex Complex::operator*(const double n) const
	{
		return Complex(this->re * n, this->im * n);
	}
	
	Complex Complex::operator/(const double n) const
	{
		return Complex(this->re / n, this->im / n);
	}
	
	Complex Complex::operator+(const double n) const
	{
		return Complex(n + this->re, this->im);
	}
	
	Complex Complex::operator-(const double n) const
	{
		return Complex(this->re - n, this->im);
	}
	
	Complex Complex::operator*(const Complex & liczba) const
	{
		Complex wynik;
		wynik.re = (this->re * liczba.re) - (this->im * liczba.im);
		wynik.im = (this->re * liczba.im) + (this->im * liczba.re);
		return wynik;
	}
	

		Complex Complex::operator/(const Complex & liczba) const
	{
	    Complex wynik;
	    wynik.re = (this->re * liczba.re + this->im * liczba.im) / (liczba.re * liczba.re + liczba.im * liczba.im);
	    wynik.im = -(this->re * liczba.im - this->im * liczba.re) / (liczba.re * liczba.re + liczba.im * liczba.im);
	    return wynik;
	}
	
	Complex Complex::operator+(const Complex & liczba) const
	{
		Complex wynik;
		wynik.re = this->re + liczba.re;
		wynik.im = this->im + liczba.im;
		return wynik;
	}
	
	Complex Complex::operator-(const Complex & liczba) const
	{
		Complex wynik;
		wynik.re = this->re - liczba.re;
		wynik.im = this->im - liczba.im;
		return wynik;
	}
	
	bool Complex::operator==(const Complex & liczba) const
	{
		if((this->re == liczba.re) && (this->im == liczba.im)) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	Complex operator*(double m, const Complex & liczba)
	{
		return Complex(liczba.re * m, liczba.im * m);
	}
	
	Complex operator+(double m, const Complex & liczba)
	{
		return Complex(liczba.re + m, liczba.im);
	}
	
	Complex operator-(double m, const Complex & liczba)
	{
		return Complex(m - liczba.re, liczba.im);
	}
	
	Complex operator/(double m, const Complex & liczba)
	{
		return Complex( ((m * liczba.re) / (liczba.re * liczba.re + liczba.im * liczba.im)), (-(m * liczba.im) / (liczba.re * liczba.re + liczba.im * liczba.im)));
	}

	




	 ostream& operator<<(ostream& os, const Complex & liczba) 
	{
		os<<"("<<liczba.re<<","<<liczba.im<<"i)";

		return os;
	}
	
