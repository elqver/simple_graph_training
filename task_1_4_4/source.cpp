#include <iostream>

using namespace std;


int solution(int n, int k){
	if (k > n) return min(n, k / 2);
	return k / 2 + 1;
}


int main() {
	int n, k;
	cin >> n >> k;
	cout << solution(n, k);
	return 0;
}
