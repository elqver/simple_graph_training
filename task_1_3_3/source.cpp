#include <iostream>
#include <vector>


using namespace std;


bool solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		first--; second--;
		matrix[first][second] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (matrix[i][j] + matrix[j][i] != 1) return false;
		}
	}
	return true;
}


int main() {
	cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}

