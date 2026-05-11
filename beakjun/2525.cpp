#include <iostream>
using namespace std;

int main() {
    int h, m, cook_time;
    const int day_2_minute = 60 * 23 + 59;

    cin >> h >> m >> cook_time;

    int current_time = 60 * h + m + cook_time;


    if (current_time - day_2_minute >= 0) {
        current_time = current_time - (current_time / day_2_minute) * day_2_minute - 1;
    }

    cout << current_time / 60 << " " << current_time % 60 << endl;

    return 0;
}