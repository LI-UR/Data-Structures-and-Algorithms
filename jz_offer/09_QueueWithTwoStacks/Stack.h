/*********************************************
* file:   Stack.h
* author: AIWWZ(wzj1524@qq.com)
* date:   2019-07-19 03:17:43
**********************************************/
#ifndef __STACK_H__
#define __STACK_H__
#include <queue>
#include <iostream>
using std::cout;  using std::endl;
using std::queue;
 
template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T &elem);
    T pop();

private:
    queue<T> que1;
    queue<T> que2;
};

template <typename T> Stack<T>::Stack() { }
template <typename T> Stack<T>::~Stack() { }

template <typename T>
void Stack<T>::push(const T &elem) {
    queue<T> &que = !que1.empty() ? que1 : que2;

    que.push(elem);
}

template <typename T> 
T Stack<T>::pop() {
    queue<T> *pQueA, *pQueB;
    if(!que1.empty()) {
        pQueA = &que1;
        pQueB = &que2;
    }
    else if(!que2.empty()) {
        pQueA = &que2;
        pQueB = &que1;
    }
    else { //空栈
        cout << "Empty stack!!!" << endl;
        exit(-1);
    }

    T result;
    while(!pQueA->empty()) {
        result = pQueA->front();
        pQueA->pop();
        if(pQueA->empty()) {
            return result;
        }
        else {
            pQueB->push(result);
        }
    }
}
 
#endif /* __STACK_H__ */
