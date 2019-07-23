/*********************************************
 * file:   QueueWithTwoStacks.cpp
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-19 02:52:37
 **********************************************/
#include <iostream>
using namespace std;

#include "Stack.h"

// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[]) {
    Stack<char> stack;

    stack.push('a');
    stack.push('b');
    stack.push('c');

    char top = stack.pop();
    Test(top, 'c');

    top = stack.pop();
    Test(top, 'b');

    stack.push('d');
    top = stack.pop();
    Test(top, 'd');

    stack.push('e');
    top = stack.pop();
    Test(top, 'e');

    top = stack.pop();
    Test(top, 'a');

    //emtpy stack
    stack.pop();

    return 0;
}

