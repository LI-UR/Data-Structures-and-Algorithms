/*****二分查找*****/
#include <iostream>
using std::cout;  using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

const int NotFound = -1;

int BinarySearch(vector<string> &v, int start, int end, string key) {
	if (start > end) {
		return NotFound;
	}
	int mid = (start + end) / 2;
	if (v[mid] == key) {
		return mid;
	}
	else if (key < v[mid]) {
		return BinarySearch(v, start, mid - 1, key);
	}
	else {
		return BinarySearch(v, mid + 1, end, key);
	}
}

int main() {
	vector<string> v = { "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg"};
	cout << BinarySearch(v, 0, 6, "ggg") << endl;

	return 0;
}