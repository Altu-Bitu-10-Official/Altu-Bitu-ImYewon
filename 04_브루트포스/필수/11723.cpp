#include <iostream>

using namespace std;

void commandProcess(string cmd, int& s) {
    if (cmd == "add") {
        int x;
        cin >> x;
        s |= (1 << (x - 1));
    }

    if (cmd == "remove") {
        int x;
        cin >> x;
        s &= ~(1 << (x - 1));
    }

    if (cmd == "check") {
        int x;
        cin >> x;
        if (s & (1 << (x - 1))) {
            cout << 1 << '\n';
        } 
        else {
            cout << 0 << '\n';
        }
    }

    if (cmd == "toggle") {
        int x;
        cin >> x;
        s ^= (1 << (x - 1));
    }

    if (cmd == "all") {
        s = -1; //https://dev-gorany.tistory.com/115#google_vignette 블로그 참고
    }

    if (cmd == "empty") {
        s &= 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    int s = 0;

    while (m--) {
        string cmd;
        cin >> cmd;

        commandProcess(cmd, s);
    }
}