// Copyright[2022.11.10] Shan

#include <iostream>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int top;
} SqStack;
void InitStack(SqStack &st) { st.top = -1; }
void DestoryStack(SqStack st) {}
bool Push(SqStack &st, ElemType x) {
  if (st.top != MaxSize - 1) {
    st.top++;
    st.data[st.top] = x;
    return true;
  } else {
    return false;
  }
}
ElemType Pop(SqStack &st, ElemType x) {
  if (st.top != -1) {
    x = st.data[st.top];
    st.top--;
    return x;
  } else {
    return false;
  }
}
ElemType GetTop(SqStack st, ElemType x) {
  if (st.top != -1) {
    x = st.data[st.top];
    return x;
  } else {
    return false;
  }
}
bool StackEmpty(SqStack st) {
  if (st.top == -1) {
    return true;
  } else {
    return false;
  }
}
int main() {
  SqStack st;
  InitStack(st);
  Push(st, 1);
  Push(st, 2);
  Push(st, 3);
  int top = 0;
  top = GetTop(st, top);
  cout << top << endl;
  for (int i = 0; i <= st.top; i++) {
    cout << st.data[i] << " ";
  }
  DestoryStack(st);
  return 0;
}