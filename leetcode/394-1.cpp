class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        int currentNum = 0;
        string currentString;

        for (const char& c: s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }
            
            else if (c == '[') {
                countStack.push(currentNum);
                stringStack.push(currentString);

                currentNum = 0;
                currentString.clear();
            }
            
            else if (c == ']') {
                currentNum = countStack.top();
                countStack.pop();

                string repeated;
                repeated.reserve(currentString.size() * currentNum);

                for (int i=0; i<currentNum; i++) repeated += currentString;
                currentString = stringStack.top() + repeated;
                stringStack.pop();

                currentNum = 0;
            }
            
            else {
                currentString += c;
            }
        }

        return currentString;
        
    }
};
