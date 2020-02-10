#pragma once
#include "dependies.h"
class Fraction
{
private:
	int numerator;
	int denominator;
	int Whole_part;
	void Fraction_check();
	void common_denominator();
	void set_whole_part();
	static int summ_of_fractions;
public:
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);
	Fraction(Fraction& other);
	~Fraction();
	inline void Set_numerator(int numenator);
	inline void Set_denominator(int denominator);
	void Fraction_show();
	inline double Get_decimal();
	static inline int Get_summ_of_fractions();
	Fraction operator *(Fraction other);
	Fraction operator /(Fraction other);
	Fraction operator +(Fraction other);
	Fraction operator -(Fraction other);
	Fraction operator *(int a);
	Fraction operator /(int a);
	Fraction operator +(int a);
	Fraction operator -(int a);
	Fraction operator *(double a);
	Fraction operator /(double a);
	Fraction operator +(double a);
	Fraction operator -(double a);
	friend void Save_binary(const Fraction& a);
	friend void Load_binary( Fraction& a);
};




