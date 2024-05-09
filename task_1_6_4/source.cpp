#include <iostream>
#include <vector>

using namespace std;


int solution(int p, int k) {
	if (!(k % p)) return 0;
	vector<int> g(p, 0);
	for (int i = 1; i < p; ++i) g[i] = (i * k) % p;
	vector<int> v(p, 0);
	int res = 0;
	for (int node = 1; node < p; ++node) {
		if (v[node]) continue;
		int cur = node;
		while (!v[cur]) {
			v[cur] = 1;
			cur = g[cur];
		}
		res++;
	}

	return res;
}


int main() {
	int p, k;
	cin >> p >> k;
	cout << solution(p, k);

	return 0;
}

