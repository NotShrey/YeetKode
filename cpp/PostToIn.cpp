#include<bits/stdc++.h>
using namespace std;

string postToInfix(string a) {
    stack<string>s;
    for(int i=0;i<a.size();i++){

        if((a[i]>='A' &&a[i]<='z')){
            string ans="";
            ans=a[i];
            s.push(ans);
        }
        else{
            string y=s.top();
            s.pop();
            string x=s.top();
            s.pop();
            string res="";
            res='('+x+a[i]+y+')';
            s.push(res);
        }
    }
    return s.top();
}


int main()
{
    string s = "abcd^e-fgh*+^*+i-";
    cout << "Post: " << s << endl;
    cout << "Pin: " << postToInfix(s) << endl;
    return 0;
}


