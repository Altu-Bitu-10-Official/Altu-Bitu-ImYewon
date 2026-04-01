#include <iostream>
#include <vector>

using namespace std;

bool checkArr(vector<char>& arr, int point, char ch) {
	if (arr[point] != '?' && arr[point] != ch) {
		return false;
	}
	if (arr[point] == '?') {
		for (int i = 0; i < arr.size(); i++) {
			if (i != point && arr[i] == ch) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<char> arr(n, '?');
	bool flag = true;
	int point = 0;

	for (int i = 0; i < k; i++) {
		int s;
		char ch;
		cin >> s >> ch;

		point = (point - s % n + n) % n;

		if (!checkArr(arr, point, ch)) {
			flag = false;
		}
		else {
			arr[point] = ch;
		}
		
	}

	if (!flag) {
		cout << "!\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[(point + i) % n];
	}
	
	return 0;
}