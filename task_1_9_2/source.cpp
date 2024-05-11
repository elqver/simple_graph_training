#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int val;
			cin >> val;
			g[i][j] = val;
		}
	}
	vector<int> color(n);
	for (int i = 0; i < n; ++i) cin >> color[i];
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[i][j] && color[i] != color[j]) ++res;
		}
	}

	cout << res / 2 << endl;

	return 0;
}

