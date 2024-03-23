#include<bits/stdc++.h>
#include<stack>
using namespace std;

string preToPost(string s){
    int n = s.length();
    stack<string> st;
    string res;

    for(int i=n-1; i>=0; i--){
        char c = s[i];
        if(c >= 'a' && c <= 'z') st.push(string(1,c));
        else {
            string st1 = st.top(); st.pop();
            string st2 = st.top(); st.pop();
            res = st1 + st2 + c;
            st.push(res);
        }
    }
    return res;
}

int main(){
    string exp = "-+ka-g+jo";
    cout << "Prefix: " << exp << endl;
    cout << "Postfix: " << preToPost(exp) << endl;
    return 0;
}
