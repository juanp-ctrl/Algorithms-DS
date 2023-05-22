#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

bool isValid(string s) {
    if(s.size()%2 == 1){
        return false;
    }
    else{
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
    }
    return true;
}

//More memory but with a handy trick using a hash table
bool isValid2(string s) {
    if(s.size()%2 == 1){
        return false;
    }
    else{
        stack<char> st;
        unordered_map<char, char> hashtable = {{')','('}, {'}','{'}, {']','['}};
        for(int i=0; i<s.size(); i++){
            if(hashtable.find(s[i]) != hashtable.end()){
                if(st.empty() || st.top() != hashtable[s[i]]) return false;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "(({{[]}}))";

    if(isValid(s)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
