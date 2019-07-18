/*********************************************
* file:   3_FindDuplication.cc
* author: AIWWZ(wzj1524@qq.com)
* date:   2019-07-17 13:01:24
**********************************************/
#include <iostream>
using namespace std;

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

inline void Swap(int &num1, int &num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

bool FindDuplication(int A[], int length, int &duplication) {
    if(nullptr == A || length <= 0) {
        return false;
    }

    for(int i = 0; i < length; ++i) {
        if(A[i] > length-1 || A[i] < 0) { //非法输入
            return false;
        }
    }

    for(int i = 0; i < length; ) {
        if(A[i] == i) {
            ++i;
        }
        else if(A[i] != A[A[i]]) {
            Swap(A[i], A[A[i]]); //将A[i]放到它实际应当存在的位置
        }
        else { //找到重复数字
            duplication = A[i];
            return true;
        }
    }

    return false;
}
 
int main() {
    int duplication;
    //测试
    int A1[] = {2, 3, 1, 0, 2, 5, 3};
    int A2[] = {2, 3, 1, 0, 5};
    int A3[] = {2, 3, 1, 0, 2, 5, 7};
    int *A4 = nullptr;

    if(FindDuplication(A1, sizeof(A1)/sizeof(int), duplication)) {
        cout << "输入有效，并且数组A1中存在重复的数字" << duplication << endl;
    }
    else {
        cout << "输入无效，或者数组A1中没有重复的数字" << endl;
    }

    if(FindDuplication(A2, sizeof(A2)/sizeof(int), duplication)) {
        cout << "输入有效，并且数组A2中存在重复的数字" << duplication << endl;
    }
    else {
        cout << "输入无效，或者数组A2中没有重复的数字" << endl;
    }

    if(FindDuplication(A3, sizeof(A3)/sizeof(int), duplication)) {
        cout << "输入有效，并且数组A3中存在重复的数字" << duplication << endl;
    }
    else {
        cout << "输入无效，或者数组A3中没有重复的数字" << endl;
    }
    
    if(FindDuplication(A4, sizeof(A4)/sizeof(int), duplication)) {
        cout << "输入有效，并且数组A4中存在重复的数字" << duplication << endl;
    }
    else {
        cout << "输入无效，或者数组A4中没有重复的数字" << endl;
    }
 
    return 0;
}
