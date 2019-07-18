/*********************************************
* file:   Singleton4.cc
* author: AIWWZ(wzj1524@qq.com)
* date:   2019-07-17 12:19:57
**********************************************/
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

class Singleton {
public:
    static Singleton* getInstance() {
        if(nullptr == m_instance) {
            pthread_once(&m_once_control, init_routine);
        }
        return m_instance;
    }

    void print() {
        cout << "I am a Singleton objest!" << endl;
    }


private:
    Singleton() { 
        cout << "Singleton()" << endl;
    }

    ~Singleton() {
        cout << "~Singleton()" << endl;
    }

    static void init_routine() {
        m_instance = new Singleton();
        atexit(destroy); //注册销毁函数
        cout << "init_routine()" << endl;
    }

    static void destroy() {
        if(m_instance) {
            delete m_instance;
        }
    }

private:
    static Singleton *m_instance;
    static pthread_once_t m_once_control;
};

Singleton *Singleton::m_instance = nullptr;
pthread_once_t Singleton::m_once_control = PTHREAD_ONCE_INIT;

int main() {
    Singleton::getInstance()->print();
    Singleton::getInstance()->print(); //只会调用一次init_routine()
     
    return 0;
}
