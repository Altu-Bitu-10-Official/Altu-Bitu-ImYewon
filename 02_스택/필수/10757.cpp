#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    deque<int> da, db;
    deque<int> result;

    for (int i = 0; i < a.size(); i++) {
        da.push_back(a[i] - '0'); //char to int
    }

    for (int i = 0; i < b.size(); i++) {
        db.push_back(b[i] - '0');
    }

    int carry = 0;

    while (!da.empty() || !db.empty() || carry != 0) {
        int sum = carry;
        if (!da.empty()) {
            sum += da.back();
            da.pop_back();
        }
        if (!db.empty()) {
            sum += db.back();
            db.pop_back();
        }

        result.push_front(sum % 10);
        carry = sum / 10;
    }

    while (!result.empty()) {
        cout << result.front();
        result.pop_front();
    }

}