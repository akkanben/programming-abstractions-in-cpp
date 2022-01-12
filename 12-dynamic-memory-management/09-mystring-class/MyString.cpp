#include "MyString.h"
#include "../../StanfordCPPLib/include/error.h"

#include <string>

MyString::MyString(std::string str) {
  count = 0;
  while (str[count])
    count++;
  array = new char[count];
  for (int i = 0; i < count; i++)
    array[i] = str[i];
}

MyString::~MyString() { delete[] array; }

std::string MyString::toString() const {
  std::string output = "";
  for (int i = 0; i < this->count; i++)
    output += array[i];
  return output;
}

int MyString::length() const { return count; }

MyString MyString::substr(int start, int n) const {
  if (start < 0 || start > count || n < 0 || n > count)
    error("Index out of bounds.");
  std::string temp = "";
  for (int i = start; i < start + n; i++) {
    temp += array[i];
  }
  return MyString(temp);
}

MyString MyString::substr(int start) const {
  return this->substr(start, count);
}

char MyString::operator[](int index) const {
  if (index < 0 || index > count)
    error("Index out of bounds.");
  return array[index];
}

MyString::MyString(const MyString &src) { deepCopy(src); }

MyString &MyString::operator=(const MyString &src) {
  if (this != &src) {
    delete[] array;
    deepCopy(src);
  }
  return *this;
}

MyString operator+(MyString a, MyString b) {
  return MyString(a.toString() + b.toString());
}

MyString operator+=(MyString a, char ch) { return MyString(a.toString() + ch); }

MyString operator+=(MyString a, std::string str) {
  return MyString(a.toString() + str);
}

MyString operator+=(MyString a, MyString str) {
  return MyString(a.toString() + str.toString());
}

void MyString::deepCopy(const MyString &src) {
  array = new char[src.count];
  for (int i = 0; i < src.count; i++)
    array[i] = src.array[i];
  count = src.count;
}

std::ostream &operator<<(std::ostream &os, MyString str) {
  return os << str.toString();
}

bool operator==(MyString a, MyString b) {
  if (a.count != b.count)
    return false;
  int i = 0;
  while (a.array[i] == b.array[i]) {
    if (i == a.count - 1)
      return true;
    else
      i++;
  }
  return false;
}

bool operator!=(MyString a, MyString b) { return a == b ? false : true; }

bool operator>(MyString a, MyString b) {
  int i = 0;
  while (a.array[i] >= b.array[i]) {
    if (a.array[i] > b.array[i])
      return true;
    if (i == a.count - 1) {
      return a.count > b.count ? true : false;
    }
    i++;
  }
  return false;
}

bool operator>=(MyString a, MyString b) { return (a > b || a == b); }

bool operator<(MyString a, MyString b) {
  int i = 0;
  while (a.array[i] <= b.array[i]) {
    if (a.array[i] < b.array[i])
      return true;
    if (i == a.count - 1) {
      return a.count < b.count ? true : false;
    }
    i++;
  }
  return false;
}

bool operator<=(MyString a, MyString b) { return (a < b || a == b); }
