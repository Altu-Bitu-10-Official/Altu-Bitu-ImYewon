#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

int similarity(string base, string compare) {
	int cnt = 0;
	int differ_len = abs((int)base.length() - (int)compare.length());

	if (differ_len > 1) {
		return 0;
	}

	vector<int> alpha(26, 0);

	for (char c : base) {
		alpha[c - 'A']++;
	}

	for (char c : compare) {
		alpha[c - 'A']--;
	}

	int differ = 0;
	for (int i : alpha) {
		differ += abs(i);
	}

	if (differ_len == 0 && differ <= 2) {
		return 1;
	}
	if (differ_len == 1 && differ <= 1) {
		return 1;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	
	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = 0;

	for (int i = 1; i < n; i++) {
		result += similarity(v[0], v[i]);
	}

	cout << result;
	return 0;
}