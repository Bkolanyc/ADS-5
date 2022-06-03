// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

const int s = 100;

template<typename type, int s>
class TStack {
 private:
    type a[100];
    int top;
 public:
    TStack() : top(-1) { }
    type get() const {
        return a[top];
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == s - 1;
    }
    void pop() {
        if (top >= 0)
            top--;
    }
    void push(type item) {
        if (top < s - 1)
            a[++top] = item;
    }
};
#endif  // INCLUDE_TSTACK_H_
