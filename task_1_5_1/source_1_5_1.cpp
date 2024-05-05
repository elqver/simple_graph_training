#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>


using namespace std;


void dfs(set<int> &visited, int target, const map<int, set<int>>& g) {
	visited.insert(target);
	if (!g.count(target)) return;
	for (const auto &elem: g.at(target)) {
		if (!visited.count(elem)) dfs(visited, elem, g);
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	map<int, set<int>> g;
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		if (first == second) continue;
		g[first].insert(second);
		g[second].insert(first);
	}
	set<int> visited;
	dfs(visited, 1, g);
	vector<int> res(visited.begin(), visited.end());
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto elem: res) cout << elem << " ";
	cout << endl;

	return 0;
}
