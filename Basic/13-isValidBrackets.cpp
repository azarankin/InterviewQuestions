#include <stack>
#include <string>

bool isValidBrackets(const std::string& s) {
    std::stack<char> 
    ;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            char reversed = c == ')' ? '(' : ']' ? '[' : '{';

            char top = stk.top();
            stk.pop();

            if (top != reversed) {
                return false;
            }
        }
    }
    return stk.empty(); // כל הסוגרים נסגרו
}
