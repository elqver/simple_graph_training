#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	vector<int> visited(n + 1, false);
	stack<int> s;
	s.push(1);

	while (!s.empty()) {
		int from = s.top();
		s.pop();
		if (visited[from]) continue;
		cout << from << " ";
		visited[from] = 1;
		for (int to : g[from]) {
			if (!visited[to]) s.push(to);
		}
	}
	cout << endl;

	return 0;
}

