#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int a = abs(arr[0] - s);

	for (int i = 1; i < n; i++) {
		int b = abs(arr[i] - s);
		a = gcd(a, b);
	}

	cout << a << '\n';
	return 0;
}