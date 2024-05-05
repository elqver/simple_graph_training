#include <iostream>
#include <algorithm>
#include <map>


using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int res = 0;
	map<pair<int, int>, int> edges;
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		if (first == second) continue;
		if (second < first) swap(first, second);
		edges[{first, second}]++;
	}

	cout << count_if(edges.begin(), edges.end(), [](const auto& pair){
		  return pair.second >= 2;}) << endl;
	return 0;
}

