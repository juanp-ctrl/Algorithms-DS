#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

/*
    * @param strs: a list of strings
    * @return: encodes a list of strings to a single string.
    */
string encode(vector<string> &strs) {
    stringstream ss;
    for(string s : strs){
        if(s == ":"){
            ss << " " << ":";
        }
        else{
            ss << s << ":";
        }
    }
    string result = ss.str();
    return result;
}

/*
    * @param str: A string
    * @return: dcodes a single string to a list of strings
    */
vector<string> decode(string &str) {
    vector<string> result;
    istringstream ss(str);
    string word;
    while(getline(ss, word, ':')){
        if(word == " "){
            result.push_back(":");
        }
        else{
            result.push_back(word);
        }
    }
    return result;
}

int main(){
    vector<string> strs = {"eat","tea","tan",":","nat","bat"};

    string coded = encode(strs);

    vector<string> decoded = decode(coded);

    for(string s : decoded){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
