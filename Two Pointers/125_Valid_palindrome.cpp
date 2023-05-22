#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

bool isPalindrome(string s) {
    string str{};
    for(char c : s){
        if((c >= 48 && c <= 57) || (c>=97 && c<=122)){
            str+=c;
        }
        else if(c >=65 && c <=90){
            str+= (c+32);
        }
    }
    //Using two pointers, you could also reverse the string and compare it to the original
    int l=0, r=str.size()-1;
    while(l < r){
        if(str[l] != str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome(s)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
