#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


using namespace std;


// check if there is a loop
bool dfs(const map<int, set<int>> &g, vector<int> &p, int v) {
	if (!g.count(v)) return false;
	for (auto elem : g.at(v)) {
		if (p[v] == elem) continue;
		if (p[elem]) return true;
		p[elem] = v;
		if (dfs(g, p, elem)) return true;
	}
	return false;
}


bool solution() {
	int n, m;
	cin >> n >> m;
	if (m != n - 1) return false;

	map<int, set<int>> g;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].insert(to);
		g[to].insert(from);
	}

	vector<int> p(n + 1);
	p[1] = -1;
	if (dfs(g, p, 1) || count(p.begin(), p.end(), 0) != 1) return false;
	return true;
}


int main() {
	cout << (solution() ? "YES" : "NO");

	return 0;
}

