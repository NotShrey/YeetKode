#include <bits/stdc++.h>
#include <stack>
using namespace std;

int pre(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

string infixToPostfix(string exp)
{
    int n = exp.length();
    stack<char> st;
    string res = "";

    for (int i = 0; i < n; i++)
    {
        if (isalnum(exp[i]))// isalnum is used to check wheather a the ip is an alphabet or a number
            res += exp[i];
        else if (exp[i] == '(') // as this has higher precedence
            st.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from stack
        }
        else// for cases of *, /, +, -
        {
            while (!st.empty() && pre(exp[i]) <= pre(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << exp << endl;
    cout << "Postfix Expression: " << infixToPostfix(exp) << endl;
    return 0;
}
