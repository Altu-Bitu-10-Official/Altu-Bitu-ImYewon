#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(int left, int right, int target, vector<int>& card) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] >= target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int binarySearchCard(vector<int>& card, int target) {
	int idx = lowerBound(0, card.size() - 1, target, card);

	if (idx < card.size() && card[idx] == target) {
		return 1;
	}
	return 0; 
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n, m;
	cin >> n;

	vector<int> card(n);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		cout << binarySearchCard(card, target) << ' ';
	}
	return 0;
}