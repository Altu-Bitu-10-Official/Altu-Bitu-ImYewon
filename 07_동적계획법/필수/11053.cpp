#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n); 
	vector<int> dp(n, 0);
	int len = 0;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		len = 0;

		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				len = max(len, dp[j]);
			}
		}
		dp[i] = len + 1;
		answer = max(answer, dp[i]);
		
	}

	cout << answer;

	return 0;
}