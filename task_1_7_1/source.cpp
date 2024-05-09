#include <iostream>
#include <vector>


using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> leaves(n + 1, 1);
	for (int i = 2; i <= n; ++i) {
		int val;
		cin >> val;
		leaves[val] = 0;
	}
	for (int i = 1; i <= n; ++i) if (leaves[i]) cout << i << " ";

	return 0;
}

