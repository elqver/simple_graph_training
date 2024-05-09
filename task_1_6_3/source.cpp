#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;


bool dfs(const map<int, set<int>> &g, 
		vector<int> &p, 
		vector<int> &trace,
		int v) {
	if (!g.count(v)) return false;

	trace.push_back(v);
	vector<int> elems(g.at(v).begin(), g.at(v).end());
	sort(elems.begin(), elems.end());
	for (auto elem : elems) {
		if (p[v] == elem) continue; 
		if (p[elem]) return true;
		p[elem] = v;
		if (dfs(g, p, trace, elem)) return true;
	}
	trace.pop_back();
	return false;
}


vector<int> find_loop(const map<int, set<int>> &g, int n, int m) {
	vector<int> p(n + 1, 0);
	p[1] = -1;
	vector<int> trace;
	for (int v = 1; v <= n; ++v) {
		if (p[v] > 0) continue ;
		if (dfs(g, p, trace, v)) return trace;
	}
	return trace;
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

	auto loop = find_loop(g, n, m);
	if (loop.empty()) {
		cout << "NO" << endl;
		return 0;
	}
	cout <<"YES" << endl;
	cout << loop.size() << endl;
	for (auto elem : loop) cout << elem << " ";
	cout << endl;

	return 0;
}

