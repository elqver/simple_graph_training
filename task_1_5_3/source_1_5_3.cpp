#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


using namespace std;


void dfs(set<int> &visited, int target, const map<int, set<int>> &g) {
	visited.insert(target);
	if (!g.count(target)) return ;
	for (auto elem : g.at(target)) if(!visited.count(elem)) dfs(visited, elem, g);
}


int main() {
	int n, m;
	cin >> n >> m;
	map<int, set<int>> g;
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		g[second].insert(first);
	}
	set<int> visited;
	dfs(visited, 1, g);
	vector<int> res(visited.begin(), visited.end());
	sort(res.begin(), res.end());
	for (auto elem : res) cout << elem << " ";
	cout << endl;

	return 0;
}

