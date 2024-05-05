#include <iostream>
#include <vector>


using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		if (first == second) continue;
		v[--first]++;
		v[--second]++;
	}
	int k;
	cin >> k;
	cout << v[--k] << endl;
	return 0;
}

