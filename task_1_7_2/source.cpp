#include <iostream>
#include <vector>
#include <map>


using namespace std;


int dfs(const map<int, vector<int>> &g, int v, vector<int> &count, int parent) {
	if (!g.count(v)) return 0;
	int res = 1;
	for (auto elem : g.at(v)) if (elem != parent) res += dfs(g, elem, count, v);
	count[v] = res;
	return res;
}


int main() {
	int n;
	cin >> n;
	map<int, vector<int>> g;
	for (int i = 2; i <= n; ++i) {
		int val;
		cin >> val;
		g[i].push_back(val);
		g[val].push_back(i);
	}
	vector<int> res(n + 1, 0);
	dfs(g, 1, res, 0);
	for (int i = 1; i <= n; ++i) cout << res[i] << " ";

	return 0;
}

