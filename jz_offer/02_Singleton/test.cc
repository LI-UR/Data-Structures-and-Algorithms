#include <iostream>
using namespace std;

class Test {
public:
    static int a;

};

int Test::a;

int main() {
    cout << Test::a << endl;

    return 0;
}

