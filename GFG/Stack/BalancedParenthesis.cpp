#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkchar(char top, char s)
{
    return ((top == '(' && s == ')') || (top == '{' && s == '}') || (top == '[' && s == ']'));
}

bool checkParenthesis(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else
        {
            if (stack.size() > 0 && checkchar(stack.top(), s[i]))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter the parenthesis expression";
    getline(cin, s);

    if (checkParenthesis(s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}