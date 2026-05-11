#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;

    unordered_map<int, int> num_list;

    while (n--) {
        int input_num;
        cin >> input_num;

        num_list[input_num]++;
    }

    cin >> m;
    while (m--) {
        int input_num;
        cin >> input_num;

        cout << num_list[input_num] << " ";
    }

    cout << '\n';

    return 0;
}