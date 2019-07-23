/*********************************************
 * file:   Fibonacci.cc
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-19 04:46:02
 **********************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

long long Fibonacci_Solution1(int n) {
    if(n <= 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2); 
    }
}

unsigned long long Fibonacci_Solution2(int n) {
    if(n <= 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        unsigned long long fib_n_minus_2 = 0;
        unsigned long long fib_n_minux_1 = 1;
        unsigned long long fib_n = 0;
        for(int i = 2; i <= n; ++i) {
            fib_n = fib_n_minus_2 + fib_n_minux_1;
            fib_n_minus_2 = fib_n_minux_1;
            fib_n_minux_1 = fib_n;
        }
        return fib_n;
    }
}

int Fibonacci_Solution3(int n) {
    
    return n;
}

// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);
    cout << (unsigned long long)Fibonacci_Solution2(93) << endl;

    return 0;
}
