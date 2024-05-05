#include<iostream>
#include<vector>
#include<set>


using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < m; ++i) {
		int first, second;
		cin >> first >> second;
		v[first - 1]++; v[second - 1]++;
	}
	cout << (set<int>(v.begin(), v.end())).size();
}
