/*****回文检查*****/
#include <string>
using std::string;
#include <iostream>
using std::cin;  using std::cout;  using std::endl;

bool IsPlindrome(string s) {
	if (s.length() <= 1)
		return true;
	else
		return s[0] == s[s.length() - 1] && IsPlindrome(s.substr(1, s.length() - 2));

}

int main() {
	string s;
	cin >> s;

	if (IsPlindrome(s))
		cout << "Plindrome!" << endl;
	else
		cout << "Not plindrome!" << endl;

	return 0;
}