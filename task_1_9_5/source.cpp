#include <iostream>
#include <vector>
#include <set>


using namespace std;


bool dfs(const vector<vector<int>> &g, vector<bool> &visited, int from, set<int> &path) {
	if (visited[from]) return false;
	visited[from] = true;
	path.insert(from);
	for (auto to : g[from]) {
		if (path.count(to)) return true;
		if (dfs(g, visited, to, path)) return true;
	}
	path.erase(from);

	return false;
}


bool findLoop(const vector<vector<int>> &g) {
	int n = g.size();
	vector<bool> visited(n, false);
	set<int> path;
	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue ;
		if (dfs (g, visited, i, path)) return true;
	}
	
	return false;
}


int main() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);

	for (int i = 0; i < n - 1; ++i) {
		string line;
		cin >> line;
		for (int j = i + 1; j < n; ++j) {
			if (line[j - i - 1] == 'R') g[i].push_back(j);
			else g[j].push_back(i);
		}
	}
	cout << (findLoop(g) ? "NO" : "YES") << endl;

	return 0;
}
