#include <iostream>
#include <vector>


using namespace std;


void dfs(vector<int> &p, vector<int> &d, int t) {
	if (!d[p[t]]) dfs(p, d, p[t]);
	d[t] = d[p[t]] + 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1, 0);
	for (int i = 2; i <= n; ++i) cin >> p[i];

	vector<int> d(n + 1, 0);
	d[1] = 1;
	for (int i = 2; i <= n; ++i) dfs(p, d, i);
	vector<int> count(n + 1, 0);
	for (auto elem : d) count[elem] += 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) res += count[i] % 2;
	cout << res;

	return 0;
}
