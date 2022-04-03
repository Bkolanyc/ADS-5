// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char a) {
  switch (a) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
      return -1;
  }
}
std::string infx2pstfx(std::string inf) {
  // добавьте код
  std::string str;
  char head = 0;
  TStack <char, 100> stack1;
  for (int i = 0; i < inf.length(); i++) {
    int prior;
    prior = priority(inf[i]);
    if (prior > -1) {
      if ((prior == 0 || prior > priority(head) ||
           stack1.isEmpty()) && inf[i] != ')') {
        if (stack1.isEmpty())
          head = inf[i];
        stack1.push(inf[i]);
      } else if (inf[i] == ')') {
        while (stack1.get() != '(') {
          str.push_back(stack1.get());
          str.push_back(' ');
          stack1.pop();
        }
        stack1.pop();
        if (stack1.isEmpty())
          head = 0;
      } else {
        while (!stack1.isEmpty() && priority(stack1.get()) >= prior) {
          str.push_back(stack1.get());
          str.push_back(' ');
          stack1.pop();
        }
        if (stack1.isEmpty())
          head = inf[i];
        stack1.push(inf[i]);
      }
    } else {
      str.push_back(inf[i]);
      str.push_back(' ');
    }
  }
  while (!stack1.isEmpty()) {
    str.push_back(stack1.get());
    str.push_back(' ');
    stack1.pop();
  }
  str.erase(str.end() - 1, str.end());
  return str;
}
int calculator(char operate, int x, int y) {
  switch (operate) {
    case '+':
      return x + y;
      break;
    case '-':
      return x - y;
      break;
    case '/':
      return x / y;
      break;
    case '*':
      return x * y;
      break;
  }
  return 0;
}

int eval(std::string pref) {
  // добавьте код
  TStack <int, 100> stack2;
  int i = 0, result = 0;
  char ch = pref[i];
  while (ch) {
    if (ch >= '0' && ch <= '9') {
      int numb = 0;
      int dec = 1;
      while (ch != ' ') {
        numb += (ch - 48) * dec;
        dec *= 10;
        ch = pref[++i];
      }
      stack2.push(numb);
    } else {
      char operate = ch;
      i++;
      int number2 = stack2.get();
      stack2.pop();
      int number1 = stack2.get();
      stack2.pop();
      int result = calculator(operate, number 1, number 2);
      stack2.push(result);
    }
    if (i < pref.size())
      ch = pref[++i];
    else
      ch = 0;
  }
  result = stack2.get();
  stack2.pop();
  return result;
}
