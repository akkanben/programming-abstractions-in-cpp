#ifndef _mystring_h
#define _mystring_h

#include <string>

class MyString {
public:
  MyString(std::string str);
  ~MyString();
  MyString(const MyString &src);
  std::string toString() const;
  int length() const;
  MyString substr(int start, int n);
  MyString substr(int start);
  char operator[](int index) const;
  MyString &operator=(const MyString &src);
  friend MyString operator+(MyString a, MyString b);
  friend MyString operator+=(MyString a, char ch);
  friend MyString operator+=(MyString a, std::string str);
  friend MyString operator+=(MyString a, MyString str);
  friend bool operator==(MyString a, MyString b);
  friend bool operator!=(MyString a, MyString b);
  friend bool operator>(MyString a, MyString b);
  friend bool operator>=(MyString a, MyString b);
  friend bool operator<(MyString a, MyString b);
  friend bool operator<=(MyString a, MyString b);

private:
  char *array;
  int count;
  void deepCopy(const MyString &src);
};

std::ostream &operator<<(std::ostream &os, MyString str);
MyString operator+(MyString a, MyString b);
MyString operator+=(MyString a, char ch);
MyString operator+=(MyString a, std::string str);
MyString operator+=(MyString a, MyString str);
bool operator==(MyString a, MyString b);
bool operator!=(MyString a, MyString b);
bool operator>(MyString a, MyString b);
bool operator>=(MyString a, MyString b);
bool operator<(MyString a, MyString b);
bool operator<=(MyString a, MyString b);

#endif
