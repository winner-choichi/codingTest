#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    unordered_set<int> cards;
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        cards.insert(num);
    }

    cin >> m;

    for (int i=0; i<m; ++i) {
        int num;
        cin >> num;
        if (cards.find(num) == cards.end()) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    }
    cout << endl;

    return 0;
}