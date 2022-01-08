#ifndef _intarray_h
#define _intarray_h

class IntArray {
public:
  IntArray(int n);
  ~IntArray();
  int size() const;
  int get(int k) const;
  void put(int k, int value);
  int operator[](int index);

private:
  int *array;
  int count;

  IntArray(const IntArray &src);
  IntArray &operator=(const IntArray &src);
};

#endif
