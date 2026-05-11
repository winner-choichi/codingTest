#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;

    cin >> n;

    set<string> workers;

    while(n--) {
        string name, status;
        cin >> name >> status;
        
        if (status == "enter") {
            workers.insert(name);
        } else {
            workers.erase(name);
        }
    }

    for (auto it = workers.rbegin(); it != workers.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}