#include <iostream>
#include <numeric>
#include <vector>


using namespace std;


int main() {
	int n;
	cin >> n;

	vector<int> source(n, 1);
	vector<int> sink(n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int val;
			cin >> val;
			source[j] = source[j] && !val;
			sink[i] = sink[i] && !val;
		}
	cout << std::accumulate(source.begin(), source.end(), 0) << " " << std::accumulate(sink.begin(), sink.end(), 0);
	return 0;
}
