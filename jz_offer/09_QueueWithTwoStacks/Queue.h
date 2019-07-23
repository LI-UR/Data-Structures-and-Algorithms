/*********************************************
* file:   Queue.h
* author: AIWWZ(wzj1524@qq.com)
* date:   2019-07-19 03:03:11
**********************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stack>
#include <iostream>
using std::cout;  using std::endl;
using std::stack;
 
template <typename T> 
class Queue {
public:
    Queue() {}
    ~Queue() {}
    
    void push(const T &elem) {
        st1.push(elem);
    }
    
    T pop() {
        T front;
        if(!st2.empty()) {
            front = st2.top();
            st2.pop();
        }
        else if(!st1.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            front = st2.top();
            st2.pop();
        }
        else {
            cout << "Empty stack!!!" << endl;
            exit(-1);
        }
        return front;
    }

private:
    stack<T> st1;
    stack<T> st2;
};
 
#endif /* __QUEUE_H__ */
