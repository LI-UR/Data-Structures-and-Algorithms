#include <iostream>
#include <cstring>
#include <ostream>
using std::cout; using std::endl;
using std::ostream;

class String {
    friend ostream& operator<<(ostream &os, const String &str);
public:
    String(char *str = nullptr) : m_data(nullptr) {
        if(nullptr != str) {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }

    String& operator=(const String &rhs) {
        if(this != &rhs) { //防止自赋值
            String tmp(rhs);
            swap(tmp);
        }
    
        return *this;
    }

    void swap(String &tmp) {
        char *pTmp = m_data;
        m_data = tmp.m_data;
        tmp.m_data = pTmp;
    }

private:
    char *m_data;
};

ostream& operator<<(ostream &os, const String &str) {
    os << str.m_data;
    return os;
}


int main() {
    String str1 = "aaa", str2 = "bbb";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    str2 = str1;
    cout << "After assign!" << endl;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    str2 = str2;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    str1 = "bbb";
    str2 = str2 = str1;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    return 0;
}
