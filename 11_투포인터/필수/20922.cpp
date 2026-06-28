#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int k, const vector<int>& arr) {
	vector<int> cnt(100001, 0);

	int left = 0;
	int answer = 0;

	for (int right = 0; right < n; right++) {
		cnt[arr[right]]++;

		while (cnt[arr[right]] > k) {
			cnt[arr[left]]--;
			left++;
		}

		answer = max(answer, right - left + 1);
	}

	return answer;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solution(n, k, arr);

	return 0;
}