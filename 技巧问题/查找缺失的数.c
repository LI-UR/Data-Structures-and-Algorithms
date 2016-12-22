/*
有1-10亿数字的乱序数组，其中少了一个数，怎么快速找到这个丢失的数字？
*/

#include <iostream>
#include <stdlib.h>
using std::cin; using std::cout; using std::endl;

int data[1000000];

int main() {
	FILE *fp;

	/*从data.txt中读取排好序的10亿个整数*/
	int i = 0;
	fp = fopen("data.txt", "r");
	for (i = 0; i < 1000000; i++) {
		fscanf(fp, "%d", &data[i]);
	}
	fclose(fp);

	/*查找1-1000000000中缺失的数*/
	int result;
	double tmp, sum = 0;
	for (i = 0; i < 1000000; i++) {
		sum += data[i];
	}
	tmp = 1000000.0 * 1000001 / 2;
	result = tmp - sum;

	cout << result << endl;

	return 0;
}
