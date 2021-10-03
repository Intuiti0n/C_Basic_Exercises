# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
      stack<T> stack_val;
      stack<T> stack_min;
      public:
             bool empty() const // verifica se a pilha está vazia
             { return stack_val.empty();}
             T top() const // Obtém o próximo elemento
             { return stack_val.top();}
             void pop() // Remove elemento
             { 
                  if (!stack_val.empty())
                  {if (stack_val.top()==stack_min.top())
                     stack_min.pop();
                  stack_val.pop();}
                  }
             void push(const T & val) // insere elemento
             {
                  if (stack_min.empty()||val<stack_min.top())
                     stack_min.push(val);
                  stack_val.push(val);}
             T findMin() const // retorna valor menor elemento
             { return stack_min.top();}
      };
