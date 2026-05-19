class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        
        bool is_first = true;
        for (int i: asteroids) {
            if (is_first) {
                s.push_back(i);
                is_first = false;
            }
            else if (i<0) {
                bool is_break = false;
                while (!s.empty() && s.back() > 0 && !is_break) {
                    if (-1 * i == s.back()) {
                        s.pop_back();
                        is_break = true;
                        break;
                    } else if (-1 * i > s.back()) {
                        s.pop_back();
                    } else {
                        is_break = true;
                    }
                }

                if (!is_break) s.push_back(i);
            } else {
                s.push_back(i);
            }
        }

        return s;
    }
};

