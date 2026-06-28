#include <iostream>
#include <vector>

using namespace std;

bool canLight(int h, int n, vector<int>& arr) {
    int m = arr.size();

    if (arr[0] - h > 0) {
        return false;
    }

    if (arr[m - 1] + h < n) {
        return false;
    }
    // 가로등 사이에 어두운 구간이 있는 경우
    for (int i = 1; i < m; i++) {
        if (arr[i] - arr[i - 1] > 2 * h) {
            return false;
        }
    }

    return true;
}

int binarySearchH(int n, vector<int>& arr) {
    int left = 0;
    int right = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canLight(mid, n, arr)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    cout << binarySearchH(n, arr);

    return 0;
}