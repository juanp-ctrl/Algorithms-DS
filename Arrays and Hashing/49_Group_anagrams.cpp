#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

//For the next solution since the unordered map doesnt support vectors as keys we define a hash function to be used by the unordered_map
struct VectorHasher {
  size_t operator()(const vector<int>& V) const {
    size_t hash = V.size();
    for (auto i : V)
      hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    return hash;
  }
};

//Only using a HashMap
vector<vector<string>> groupAnagramsU(vector<string>& strs) {
    
    vector<vector<string>> anagrams;
    unordered_map<vector<int>, vector<string>, VectorHasher> hashtable;   //Valor : Indices

    for(int i=0; i<strs.size(); i++){
        vector<int> array(26);
        for(char c : strs[i]){
            array[c-'a']++;
        }
        hashtable[array].push_back(strs[i]);
    }
    for(auto it : hashtable){
        anagrams.push_back(it.second);
    }
    return anagrams;
}

//Sorting and using a HashMap - O(m·n log n) - faster
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> hashtable;   //Valor : Indices

    for(int i=0; i<strs.size(); i++){
        string aux = strs[i];
        sort(aux.begin(), aux.end());
        hashtable[aux].push_back(strs[i]);
    }
    for(auto it : hashtable){
        anagrams.push_back(it.second);
    }
    return anagrams;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> anagrams = groupAnagrams(strs);

    for(auto s : anagrams){
        for(string str : s){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
