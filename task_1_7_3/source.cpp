#include <iostream>
#include <vector>
#include <map>


using namespace std;


int dfs(const map<int, vector<int>> &g, vector<int> &d, int prev, int curr) {
	if (g.find(curr) == g.end()) return 0;
	int res = 0;
	for (auto next : g.at(curr)) 
		if (next != prev) 
			res = max(res, dfs(g, d, curr, next));
	d[curr] = ++res;
	return res;
}


int main() {
	int n;
	cin >> n;
	
	map<int, vector<int>> g;
	for (int i = 2; i <= n; i++) {
		int val;
		cin >> val;
		g[i].push_back(val);
		g[val].push_back(i);
	}

	vector<int> d(n + 1);
	dfs(g, d, 0, 1);
	for (int i = 1; i <= n; ++i) cout << d[i] << " ";

	return 0;
}

