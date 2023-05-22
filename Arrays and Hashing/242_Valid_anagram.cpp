#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

//Multiset approach - slow
bool isAnagramMS(string s, string t){
    if(s.length() != t.length()){
        return false;
    }
    else{
        multiset<char> letters, convert;
        for(int i=0; i<s.length(); i++){
            letters.insert(s[i]);
            convert.insert(t[i]);
        }

        for(char c : letters){
            if(letters.count(c) != convert.count(c)){
                return false;
            }
        }
        return true;
    }
}

//Sorting approach O(n long n)
bool isAnagramS(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
}

//Hashtable approach O(n) - fast
bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    int hashtable[256] = {};    //To handle all special characters in ASCII table
    for(int i=0; i<s.length(); i++){
        hashtable[s[i]]++;
        hashtable[t[i]]--;
    }
    for(int i=0; i<256; i++){
        if(hashtable[i] != 0){
            return false;
        }
    }
    return true;
}


int main(){
    string s = "alegria", t = "galeria";

    if(isAnagram(s,t)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
