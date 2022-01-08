#ifndef _intarray_h
#define _intarray_h

class IntArray {
public:
  IntArray(int n);
  ~IntArray();
  IntArray(const IntArray &src);

  int size() const;
  int get(int k) const;
  void put(int k, int value);
  int operator[](int index);
  IntArray &operator=(const IntArray &src);

private:
  int *array;
  int count;

  void deepCopy(const IntArray &src);
};

#endif
