#include <iostream>
#include <vector>


using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> res(n, 0);

	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		res[--from]++;
		res[--to]++;
	}

	for (auto elem : res) cout << elem << " ";
	cout << endl;

	return 0;
}

