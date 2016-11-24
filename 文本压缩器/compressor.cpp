#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "chash.h"

const int D = 4099,	//散列函数的除数
codes = 4096,	//2^12
ByteSize = 8,
excess = 4,		//12 - ByteSize
alpha = 256,	//2^ByteSize
mask1 = 255,	//alpha - 1
mask2 = 15;		//2^excess - 1

class element {
	friend void Compress();
public:
	operator unsigned long() const { return key; }
	element& operator = (unsigned long y) {
		key = y;
		return *this;
	}
private:
	int code;
	unsigned long key;

};

int LeftOver,	//尚未输出代码位
status = 0;		//0意味着在LeftOver中没有未输出的位
std::ifstream in;
std::ofstream out;
void main(int argc, char* argv[]) {
	SetFiles(argc, argv);
	Compress();
}