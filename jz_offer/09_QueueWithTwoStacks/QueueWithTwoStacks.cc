/*********************************************
 * file:   QueueWithTwoStacks.cpp
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-19 02:52:37
 **********************************************/
#include <iostream>
using namespace std;

#include "Queue.h"

// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[]) {
    Queue<char> queue;

    queue.push('a');
    queue.push('b');
    queue.push('c');

    char head = queue.pop();
    Test(head, 'a');

    head = queue.pop();
    Test(head, 'b');

    queue.push('d');
    head = queue.pop();
    Test(head, 'c');

    queue.push('e');
    head = queue.pop();
    Test(head, 'd');

    head = queue.pop();
    Test(head, 'e');

    //empty queue!
    queue.pop();

    return 0;
}

