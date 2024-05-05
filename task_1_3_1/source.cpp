#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> edges;
	edges.reserve(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int val;
			cin >> val;
			if (i < j && val) 
				edges.push_back({i + 1, j + 1});
		}
	}
	sort(edges.begin(), edges.end());
	for (const auto& [first, second] : edges ) {
		std::cout << first << " " << second << endl;
	}
	return 0;
}

