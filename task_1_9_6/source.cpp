#include <iostream>
#include <vector>


using namespace std;


bool dfs(const vector<vector<int>> &g, vector<int> &color, int from) {
	for (auto to : g[from]) {
		if (color[to] == color[from]) return false;
		if (color[to]) continue;
		color[to] = (color[from] == 1 ? 2 : 1);
		if (!dfs(g, color, to)) return false;
	}
	return true;
}

// first element signals if solution is possible (1 = true, 0 = false)
// then indexes: {1 ... n} are for partitions (1 or 2) 
vector<int> possibleSit(const vector<vector<int>> &g) {
	int n = g.size() - 1;
	vector<int> color(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			color[i] = 1;
			if (!dfs(g, color, i)) return color;
		}
	}
	color[0] = 1;
	return color;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n + 1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	auto color = possibleSit(g);
	if (!color[0]) { 
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) if (color[i] == 1) cout << i << " ";

	return 0;
}
