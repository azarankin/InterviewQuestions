#include <stack>
#include <string>

bool isValidBrackets(const std::string& s) {
    std::stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) return false;

            char top = stk.top();
            stk.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stk.empty(); // כל הסוגרים נסגרו
}
