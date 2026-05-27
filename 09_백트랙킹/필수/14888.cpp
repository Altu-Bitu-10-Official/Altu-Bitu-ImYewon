#include <iostream>

using namespace std;

int n;
int operators[4]; // 연산자 (+, -, *, /)
int arr[11]; // 수열

int max_result = -1000000000;
int min_result = 1000000000;

void backtracking(int idx, int now) {
	if (idx == n) {
		max_result = max(max_result, now);
		min_result = min(min_result, now);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;

			if (i == 0) {
				backtracking(idx + 1, now + arr[idx]);
			}
			else if (i == 1) {
				backtracking(idx + 1, now - arr[idx]);
			}
			else if (i == 2) {
				backtracking(idx + 1, now * arr[idx]);
			}
			else if (i == 3) {
				backtracking(idx + 1, now / arr[idx]);
			}

			operators[i]++; // 재귀가 끝나고 돌아왔을 때 다시 복구
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	backtracking(1, arr[0]);

	cout << max_result << '\n';
	cout << min_result << '\n';

	return 0;
}