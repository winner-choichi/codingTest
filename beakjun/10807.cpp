#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, key;
    
    cin >> n;

    int a[n];

    for (int i=0; i<n; ++i){
        int num;
        cin >> num;
        a[i] = num;
    }

    cin >> key;

    cout << count(a, a + n, key) << endl;

    return 0;
}