#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> d;

    for (int i = 0; i < n; i++) {
        d.push_back(i + 1);
    }

    while (d.size() > 1) {
        int temp;
        d.pop_front();
        temp = d.front();
        d.pop_front();
        d.push_back(temp);
    }

    cout << d.front();
    return 0;

}