class Solution {
public:
    string decodeString(string s) {

        stack<int> r_stack;
        stack<string> s_stack;

        r_stack.push(0);
        s_stack.push("");

        for (const char& c: s) {
            if (isdigit(c)) {
                int n = c - '0';
                int t = r_stack.top();
                r_stack.pop();
                t = t * 10 + n;
                r_stack.push(t);
            } else if (isalpha(c)) {
                string c_str(1,c);
                string t = s_stack.top();
                s_stack.pop();
                t = t + c_str;
                s_stack.push(t);
            } else if (c == '[') {
                r_stack.push(0);
                s_stack.push("");
            } else if (c == ']') {
                while (r_stack.top() == 0) r_stack.pop();
                int repeat = r_stack.top();
                r_stack.pop();
                r_stack.push(0);
                
                string s_repeat = s_stack.top();
                cout << repeat <<  ' ' << s_repeat << '\n';
                s_stack.pop();

                string s_append;
                s_append.reserve(s_repeat.size() * repeat);
                for (int i=0; i<repeat; i++) {
                    s_append = s_append + s_repeat;
                }
                if (s_stack.empty()) {
                    s_stack.push(s_append);
                } else {
                    string t = s_stack.top();
                    s_stack.pop();
                    t = t + s_append;
                    s_stack.push(t);
                }
            } else {
                cout << "error" << endl;
                return "error";
            }
        }

        return s_stack.top();
    }
};
