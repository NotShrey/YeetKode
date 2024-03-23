#include <bits/stdc++.h>
#include <stack>
using namespace std;

string postfixToPrefix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i])) // Check if character is a letter
        {
            string ans = "";
            ans += s[i]; // Convert char to string
            st.push(ans);
        }
        else
        {
            string res;
            string y = st.top();
            st.pop();
            string x = st.top();
            st.pop();
            res = s[i] + x + y; // Correct the order of x and y
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string s = "abcd^e-fgh*+^*+i-";
    cout << "Post: " << s << endl;
    cout << "Pre: " << postfixToPrefix(s) << endl;
    return 0;
}
