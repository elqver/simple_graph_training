#include <iostream>


using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) {
			int val;
			cin >> val;
			cout << (i == j ? 0 : (val ? 0 : 1)) << " ";
		}
		cout << endl;
	}
	return 0;
}

