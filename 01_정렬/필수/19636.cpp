#include <iostream>
#include <cmath>

using namespace std;

void noChange(int w0, int i0, int i, int a, int d, int &w) {
	w = w0;

	for (int j = 0; j < d; j++) {
		int total_consumption = i0 + a;
		w += i - total_consumption;
	}

}

void change(int w0, int i0, int i, int a, int d, int t, int& w, int& bmr) {
	
	w = w0;
	bmr = i0;

	for (int j = 0; j < d; j++) {
		int total_consumption = bmr + a;	
		w += i - total_consumption;

		if (abs(i - total_consumption) > t) {
			bmr += (int)floor((double)(i - total_consumption) / 2);
		}

	}
}

int main() {

	int w0, i0, t, d, i, a;
	int w1, w2, bmr2;

	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	noChange(w0, i0, i, a, d, w1);

	if (w1 <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << w1 << " " << i0 << '\n';
	}
	
	change(w0, i0, i, a, d, t, w2, bmr2);
	if (w2 <= 0 || bmr2 <= 0) {
		cout << "Danger Diet";
	}
	else {
		cout << w2 << " " << bmr2 << " ";

		if (i0 > bmr2) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}
	return 0;
}