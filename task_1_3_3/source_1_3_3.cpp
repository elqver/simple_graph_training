#include <iostream>


using namespace std;


int main() {
	int n;
	cin >> n;
	int even=0, odd=0;
	for (int i = 0; i < n; ++i) {
		int counter = 0;
		for (int j = 0; j < n; ++j) {
			int val; 
			cin >> val;
			counter += i == j ? 0 : val;
		}
		even += (1 + counter) % 2;
		odd += counter % 2;
	}
	cout << even << " " << odd;
	return 0;
}

