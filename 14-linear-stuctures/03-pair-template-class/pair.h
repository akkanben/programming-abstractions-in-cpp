#ifndef _pair_h
#define _pair_h

template <typename ValueTypeA, typename ValueTypeB> class Pair {
public:
  Pair();
  Pair(ValueTypeA t1, ValueTypeB t2);
  ~Pair();
  ValueTypeA getFirst();
  ValueTypeB getSecond();

private:
  ValueTypeA first;
  ValueTypeB second;
};

template <typename ValueTypeA, typename ValueTypeB>
Pair<ValueTypeA, ValueTypeB>::Pair() {
  ValueTypeA first;
  ValueTypeB second;
}

template <typename ValueTypeA, typename ValueTypeB>
Pair<ValueTypeA, ValueTypeB>::Pair(ValueTypeA t1, ValueTypeB t2) {
  first = t1;
  second = t2;
}

template <typename ValueTypeA, typename ValueTypeB>
Pair<ValueTypeA, ValueTypeB>::~Pair() {
  delete first;
  delete second;
}

template <typename ValueTypeA, typename ValueTypeB>
ValueTypeA Pair<ValueTypeA, ValueTypeB>::getFirst() {
  return first;
}

template <typename ValueTypeA, typename ValueTypeB>
ValueTypeB Pair<ValueTypeA, ValueTypeB>::getSecond() {
  return second;
}
#endif
