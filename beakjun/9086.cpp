#include <iostream>
using namespace std;

void print_first_last(char *a);

int main() {
    int l;

    cin >> l;

    while (l--) {
        char a[1001];

        cin >> a;

        print_first_last(a);
    }
    
    return 0;
}

void print_first_last(char *a) {
    char first, last;

    first = a[0];

    int i = 0;
    while(1) {
        if (a[i] == '\0') {
            last = a[i-1];
            break;
        }
        i++;
    }
    
    cout << first << last << endl;
}