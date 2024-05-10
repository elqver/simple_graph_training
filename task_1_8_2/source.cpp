#include <stack>
#include <vector>
#include <iostream>


using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> visited(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	stack<int> s;
	int res = 0;
	s.push(1);
	while(!s.empty()) {
		if (s.size() > res) res = s.size();
		int from = s.top();
		s.pop();
		visited[from] = 1;
		for (int to : g[from]) {
			if (!visited[to]) s.push(to);
		}
	}
	cout << res;

	return 0;
}

