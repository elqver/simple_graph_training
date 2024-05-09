#include <iostream>
#include <map>
#include <set>


using namespace std;



bool dfs(const map<int, set<int>> &g, set<int> &track, int v, set<int> &visited) {
	if (track.count(v)) return true;

	if (visited.count(v)) return false;
	visited.insert(v);

	if (!g.count(v)) return false;
	track.insert(v);
	for (auto elem: g.at(v))
		if (dfs(g, track, elem, visited)) return true;
	track.erase(v);

	return false;
}


int main() {
	int n, m;
	cin >> n;
	map<int, set<int>> g;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int val;
			cin >> val;
			if (val) g[i].insert(j);
		}
	}

	set<int> visited;
	set<int> tmp;
	for (int i = 0; i < n; ++i) {
		if (!visited.count(i) && dfs(g, tmp, i, visited)) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}

