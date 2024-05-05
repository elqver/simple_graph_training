#include <iostream>


using namespace std;


int main() {
	int n, loops = 0;
	cin >> n;

	int val;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;
			if (j == i && val == 1) {
				loops++;
			}
		}
	}

	cout << loops << endl;

	return 0;
}
