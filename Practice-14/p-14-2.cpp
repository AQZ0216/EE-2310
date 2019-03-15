#include <iostream>
using namespace std;

class Stack{
   private:
      int *stack_buffer;
      int top;
      int max_size;

   public:
      Stack();
      Stack(int);
      void push(int elem);
      void display();
      int pop();
};

Stack::Stack(){
/* Do the following 3 things:
   1. Allocate memory to stack_ptr by creating a dynamic memory with size 5.
   2. set top to 0;
   3. set max_size to 5;
*/
    stack_buffer = new int[5];
    top = 0;
    max_size = 5;
}


Stack::Stack(int size){
/* Do the following 3 things:
   1. Allocate memory to stack_ptr by creating a dynamic memory with size "size".
   2. set top to 0;
   3. set max_size to size;
*/
    stack_buffer = new int[size];
    top = 0;
    max_size = size;
}


void Stack::push(int elem){
/* You need to check whether the stack is full before pushing into the stack.
If it's full, print "Stack is full!\n" on the screen.
Otherwise, push elem into stack, and remember doing top++ to record how many numbers has been pushed.
*/
    if(top == max_size)
    {
        cout << "Stack is full!" << endl;
        return;
    }
    else
    {
        *(stack_buffer+top) = elem;
        top++;
        return;
    }

}


void Stack::display(){
/* You need to check whether the stack is empty.
If it's empty, print "Empty" on the screen.
Otherwise, print all elements in the stack separated by a whitespace.
*/
    if(top == 0)
    {
        cout << "Empty" << endl;
        return;
    }
    else
    {
        for(int i = 0; i < top; i++)
        {
            cout << *(stack_buffer+i) << " ";
        }
        cout << endl;
        return;
    }
}

int Stack::pop(){
/* You need to check whether the stack is empty before popping.
If it's empty, print "Stack is empty!\n" on the screen and return -100000.
Otherwise, pop the latest element from the stack and return it.
*/
    if(top == 0)
    {
        cout << "Stack is empty!" << endl;
        return -100000;
    }
    else
    {
        top--;
        return *(stack_buffer+top+1);
    }
}


int main(){
   int temp;
   int n;
   cin >> n;
   Stack s1(n), s2;
   cout << "Push an integer in stack 1:" << endl;
   s1.push(5);
   s1.display();
   s1.push(9);
   s1.display();
   s1.push(1);
   s1.display();
   s1.push(3);
   s1.display();
   s1.push(7);
   s1.display();
   s1.push(12);
   s1.display();
   cout << "Pop an integer from stack 1:" << endl;
   temp = s1.pop();
   s1.display();
   temp = s1.pop();
   s1.display();
   temp = s1.pop();
   s1.display();
   cout << "Push an integer in stack 2:" << endl;
   s2.push(9);
   s2.display();
   s2.push(2);
   s2.display();
   s2.push(3);
   s2.display();
   s2.push(1);
   s2.display();
   cout << "Pop an integer from stack 2:" << endl;
   temp = s2.pop();
   s2.display();
   temp = s2.pop();
   s2.display();
   temp = s2.pop();
   s2.display();
   temp = s2.pop();
   s2.display();
   temp = s2.pop();
   s2.display();
   temp = s2.pop();
   s2.display();
   return 0;
}
