#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    double total_score = 0.0;   
    int class_count = 0;

    const unordered_map<string, double> score_map = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0},
    };

    string name, score;
    double credit;
    while (cin >> name >> credit >> score) {
        if (score == "P") {
            continue;
        } else {
            total_score += credit * score_map.at(score);
            class_count += credit;
        }
    }

    cout << total_score / double(class_count) << endl;

    return 0;
}