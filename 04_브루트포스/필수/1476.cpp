#include <iostream>

using namespace std;

int getDate(int e, int s, int m) {
	int year = 1;

	while (true) {
		int temp_e = (year - 1) % 15 + 1;
		int temp_s = (year - 1) % 28 + 1;
		int temp_m = (year - 1) % 19 + 1;

		if (temp_e == e && temp_s == s && temp_m == m) {
			return year;
		}

		year++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m;

	cin >> e >> s >> m;

	int ans = getDate(e, s, m);

	cout << ans;
}