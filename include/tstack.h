// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
T ar[100];
int k, m;
public:
TPQueue() : k(0), m(0) {}
void push(T znach) {
int i = m++;
while ((--i >= k) && (ar[i % size].prior < znach.prior)) {
ar[(i + 1) % size] = ar[i % size];
}
ar[(i + 1) % size] = znach;
}
T pop() {
return ar[(k++) % size];
}
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
