#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void answer(priority_queue<int, vector<int>, greater<int>>& pq, int n, int x) {
	pq.push(x);

	if (pq.size() > n) {
		pq.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			answer(pq, n, x);
		}
	}

	cout << pq.top();
}