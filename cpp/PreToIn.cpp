#include<bits/stdc++.h>
#include<stack>
using namespace std;

string prefixToInfixConversion(string &s){
    int n = s.length();
    stack<string> st;
    string res = "";
    for(int i=n-1; i>=0; i--){
        char c = s[i];
        if(c == '+' || c == '*' || c == '/' || c == '-'){
            string st1 = st.top(); st.pop();
            string st2 = st.top(); st.pop();
            res = "(" + st1 + c + st2 + ")";
            st.push(res);
        }
        else st.push(string(1, c));
    }
    return res;
}

int main()
{
    string exp = "-+ka-g+jo";
    cout << "Prefix Expression: " << exp << endl;
    cout << "Infix Expression: " << prefixToInfixConversion(exp) << endl;
    return 0;
}
