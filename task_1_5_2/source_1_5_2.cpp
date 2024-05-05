#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>


using namespace std;


void dfs(set<int> &visited, int target, const map<int, set<int>> &g) {
	visited.insert(target);
	if (!g.count(target)) return ;
	for (auto elem: g.at(target)) if (!visited.count(elem)) dfs(visited, elem, g);
}

int main() {
	int n, m;
	cin >> n >> m;

	map<int, set<int>> g;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		if (from == to) continue;
		g[from].insert(to);
		g[to].insert(from);
	}

	vector<vector<int>> components;
	set<int> allVisited;
	set<int> visited;
	for (int t = 1; t <= n; t++) {
		visited = {};
		if (!allVisited.count(t)) {
			dfs(visited, t, g);
			allVisited.insert(visited.begin(), visited.end());
			components.push_back({visited.begin(), visited.end()});
			sort(components.back().begin(), components.back().end());
		}
	}
	cout << components.size() << endl;
	for (const auto &c: components) {
		cout << c.size() << endl;
		for (auto elem: c) {
			cout << elem << " ";
		}
		cout << endl;
	}

	return 0;
}

