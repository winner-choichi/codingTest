#include <iostream>
using namespace std;

int main() {
    int total_price, n;
    
    cin >> total_price >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int amount, price;

        cin >> amount >> price;

        sum += amount * price;
    }

    if (sum == total_price) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}