#ifndef _rational_h
#define _rational_h

#include <iostream>
#include <string>

class Rational {

public:
  Rational();
  Rational(int n);
  Rational(int xd, int y);

  std::string toString();

  friend Rational operator+(Rational r1, Rational r2);
  friend Rational operator-(Rational r1, Rational r2);
  friend Rational operator*(Rational r1, Rational r2);
  friend Rational operator/(Rational r1, Rational r2);
  friend bool operator==(Rational r1, Rational r2);
  friend bool operator!=(Rational r1, Rational r2);
  friend bool operator<(Rational r1, Rational r2);
  friend bool operator<=(Rational r1, Rational r2);
  friend bool operator>(Rational r1, Rational r2);
  friend bool operator>=(Rational r1, Rational r2);
  friend Rational operator+=(Rational &r1, Rational r2);
  friend Rational operator-=(Rational &r1, Rational r2);
  friend Rational operator*=(Rational &r1, Rational r2);
  friend Rational operator/=(Rational &r1, Rational r2);
  friend Rational operator++(Rational &r);
  friend Rational operator++(Rational &r, int);
  friend Rational operator--(Rational &r);
  friend Rational operator--(Rational &r, int);

private:
  int num;
  int den;
};

std::ostream &operator<<(std::ostream &os, Rational rat);
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);
bool operator==(Rational r1, Rational r2);
bool operator!=(Rational r1, Rational r2);
bool operator<(Rational r1, Rational r2);
bool operator<=(Rational r1, Rational r2);
bool operator>(Rational r1, Rational r2);
bool operator>=(Rational r1, Rational r2);
Rational operator+=(Rational &r1, Rational r2);
Rational operator-=(Rational &r1, Rational r2);
Rational operator*=(Rational &r1, Rational r2);
Rational operator/=(Rational &r1, Rational r2);
Rational operator++(Rational &r);
Rational operator++(Rational &r, int);
Rational operator--(Rational &r);
Rational operator--(Rational &r, int);

#endif
