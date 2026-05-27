#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

void backtracking(int idx, int n, int m, vector<int> &numbers, vector<int> &result) {

	if (idx == m) { // m개를 다 고르면 출력
		for (int i = 0; i < m; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	vector<bool> is_used(MAX, false); // 현재 index에서 중복 사용 방지

	for (int i = 0; i < n; i++) {
		if (is_used[numbers[i]] == true) {
			continue;
		}
		is_used[numbers[i]] = true;

		result.push_back(numbers[i]);
		backtracking(idx + 1, n, m, numbers, result);
		result.pop_back();
	}


}

int main() {
	
	int n, m;
	cin >> n >> m;

	vector<int> numbers(n);
	vector<int> result;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end()); // 정렬

	backtracking(0, n, m, numbers, result);

	return 0;
}