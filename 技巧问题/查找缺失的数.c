/*
��1-10�����ֵ��������飬��������һ��������ô�����ҵ������ʧ�����֣�
*/

#include <iostream>
#include <stdlib.h>
using std::cin; using std::cout; using std::endl;

int data[1000000];

int main() {
	FILE *fp;

	/*��data.txt�ж�ȡ�ź����10�ڸ�����*/
	int i = 0;
	fp = fopen("data.txt", "r");
	for (i = 0; i < 1000000; i++) {
		fscanf(fp, "%d", &data[i]);
	}
	fclose(fp);

	/*����1-1000000000��ȱʧ����*/
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
