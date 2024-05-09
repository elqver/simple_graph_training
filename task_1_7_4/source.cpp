#include <iostream>
#include <map>
#include <vector>
#include <utility>


using namespace std;


pair<int, int> dfs(const map<int, vector<int>> &g, int prev, int curr) {
	if (g.find(curr) == g.end()) return {0, 0};

	pair<int, int> res = {0, curr};
	for (auto next : g.at(curr)){
		if (next != prev) {
			auto sup = dfs(g, curr, next);
			if (sup.first > res.first) res = sup;
		}
	}
	res.first++;

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
	auto first_end = dfs(g, 0, 1).second;
	cout << dfs(g, 0, first_end).first - 1 << endl;
	return 0;
}

