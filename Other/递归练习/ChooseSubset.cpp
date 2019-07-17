/*****n个元素中选择包含k个元素的集合个数*****/
#include <iostream>
using std::cout;  using std::endl;

int Choose(int n, int k){
	if(k == 0 || k == n){
		return 1;
	}
	else{
		return Choose(n - 1, k - 1) + Choose(n - 1, k);
	}
}

int main(){
	int n = 6, k = 2;
	cout << Choose(n, k) << endl;
	
	return 0;
}