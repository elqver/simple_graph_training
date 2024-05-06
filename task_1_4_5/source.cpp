#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;



vector<int> dfs(const map<int, set<int>>&g, set<int> &visited, int curr, int target) {
	if (visited.count(curr) || !g.count(curr)) return {};
	if (curr == target) return {target};
	visited.insert(curr);
	vector<int> next(g.at(curr).begin(), g.at(curr).end());
	sort(next.begin(), next.end());
	for (auto elem: next) {
		auto res = dfs(g, visited, elem, target);
		if (size(res)) {res.push_back(curr); return res;}
	}

	return {};
}


int main() {
	int n, m;
	cin >> n >> m;

	map<int, set<int>> g;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].insert(to);
		g[to].insert(from);
	}

	int u, v;
	cin >> u >> v;
	set<int> tmp;
	auto res = dfs(g, tmp, u, v);
	for (auto it = res.rbegin(); it != res.rend(); ++it)
		cout << *it << " ";
	if (!res.size())
		cout << "no solution";

	return 0;
}	
