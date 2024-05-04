#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	edges.reserve(m);
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		edges.push_back(make_pair(from, to));
	}
	int k;
	cin >> k;
	const auto &t = edges[k - 1];
	cout << -1 + count_if(edges.begin(), edges.end(), 
		       [&t](auto p){return t.first == p.first || t.first == p.second || t.second == p.first || t.second == p.second;});
}

