#include <iostream>


using namespace std;

int main() {
	int val, n, edges = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			edges += val;
		}
	}

	cout << edges;
	return 0;
}

