#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "Rational.h"

int gcd(int x, int y);

Rational::Rational() {
  num = 0;
  den = 1;
}

Rational::Rational(int n) {
  num = n;
  den = 1;
}

Rational::Rational(int x, int y) {
  if (y == 0) {
    error("Rational: Division by zero");
  }
  if (x == 0) {
    num = 0;
    den = 1;
  } else {
    int g = gcd(abs(x), abs(y));
    num = x / g;
    den = abs(y) / g;
    if (y < 0) {
      num = -num;
    }
  }
}

std::string Rational::toString() const {
  bool neg = false;
  int tempNum = num; // using a temp variable to keep const correct
  std::string output;
  if (num < 0) {
    neg = true;
    tempNum = -num; // work with positive numbers and add the - at the return
  }
  if (den == 1) {
    output = integerToString(tempNum);
  } else if (tempNum == den) {
    output = "1";
  } else if (tempNum > den) {
    Rational leftover = Rational(tempNum % den, den);
    output = integerToString(abs(tempNum / den)) + " " + leftover.toString();
  } else {
    output = integerToString(tempNum) + "/" + integerToString(den);
  }
  return neg ? "-" + output : output;
}

std::ostream &operator<<(std::ostream &os, Rational r) {
  return os << r.toString();
}

Rational operator+(const Rational r1, const Rational r2) {
  return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(const Rational r1, const Rational r2) {
  return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(const Rational r1, const Rational r2) {
  return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(const Rational r1, const Rational r2) {
  return Rational(r1.num * r2.den, r1.den * r2.num);
}

bool operator==(const Rational r1, const Rational r2) {
  if ((r1.num == r2.num) && (r1.den == r2.den)) {
    return true;
  } else {
    return false;
  }
}

bool operator!=(const Rational r1, const Rational r2) { return !(r1 == r2); }

bool operator<(const Rational r1, const Rational r2) {
  double a = (double)r1.num / (double)r1.den;
  double b = (double)r2.num / (double)r2.den;
  if (a < b) {
    return true;
  } else {
    return false;
  }
}

bool operator<=(const Rational r1, const Rational r2) {
  double a = (double)r1.num / (double)r1.den;
  double b = (double)r2.num / (double)r2.den;
  if (a <= b) {
    return true;
  } else {
    return false;
  }
}

bool operator>(const Rational r1, const Rational r2) {
  double a = (double)r1.num / (double)r1.den;
  double b = (double)r2.num / (double)r2.den;
  if (a > b) {
    return true;
  } else {
    return false;
  }
}

bool operator>=(const Rational r1, const Rational r2) {
  double a = (double)r1.num / (double)r1.den;
  double b = (double)r2.num / (double)r2.den;
  if (a >= b) {
    return true;
  } else {
    return false;
  }
}

Rational operator+=(Rational &r1, const Rational r2) {
  r1 = r1 + r2;
  return r1;
}

Rational operator-=(Rational &r1, const Rational r2) {
  r1 = r1 - r2;
  return r1;
}

Rational operator*=(Rational &r1, const Rational r2) {
  r1 = r1 * r2;
  return r1;
}

Rational operator/=(Rational &r1, const Rational r2) {
  r1 = r1 / r2;
  return r1;
}

Rational operator++(Rational &r, int) {
  Rational one(1, 1);
  Rational old = r;
  r = r + one;
  return old;
}

Rational operator++(Rational &r) {
  Rational one(1, 1);
  r = r + one;
  return r;
}

Rational operator--(Rational &r, int) {
  Rational one(1, 1);
  Rational old = r;
  r = r - one;
  return old;
}

Rational operator--(Rational &r) {
  Rational one(1, 1);
  r = r - one;
  return r;
}

int gcd(int x, int y) {
  int r = x % y;
  while (r != 0) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}
