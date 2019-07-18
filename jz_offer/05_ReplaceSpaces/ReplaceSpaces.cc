/*********************************************
 * file:   ReplaceSpaces.cc
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-18 03:07:08
 **********************************************/
#include <iostream>
#include <string.h>
using namespace std;

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceSpace(char str[], int length) {
    if(nullptr == str || length <= 0) {
        return;
    }

    int originalLength = 0;
    int numOfSpace = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        if(' ' == str[i]) {
            ++numOfSpace;
        }
        ++originalLength;
    }

    int newLength = originalLength + (numOfSpace << 1); //未包括末尾'\0'
    if(newLength >= length) {
        return;
    }

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfNew > indexOfOriginal) {
        if(str[indexOfOriginal] == ' ') {
            str[indexOfNew - 2] = '%';
            str[indexOfNew - 1] = '2';
            str[indexOfNew] = '0';
            indexOfNew -= 3;
        }
        else {
            str[indexOfNew] = str[indexOfOriginal];
            --indexOfNew;
        }
        --indexOfOriginal;
    }
}

// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceSpace(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
