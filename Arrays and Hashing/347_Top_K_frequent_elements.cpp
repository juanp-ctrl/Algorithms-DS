#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

//Most efficient in terms of memory
vector<int> topKFrequentV1(vector<int>& nums, int k) {
    unordered_map<int, int> umap;   //Value : Frequency
    for(int i : nums){
        umap[i]++;
    }
    vector<int> top;
    while(k>0){
        int max{}, element{};
        for(auto it : umap){
            if(it.second > max){
                element = it.first;
                max = it.second;
            }
        }
        umap.erase(element);
        top.push_back(element);
        k--;
    }
    return top;
}

//Using ordered pairs - most efficient in terms of time
vector<int> topKFrequent(vector<int>& nums, int k) {
    if(nums.size() == 1) return nums;

    unordered_map<int,int> umap;    //Value : Frequency
    for(int i=0; i<nums.size(); i++){
        umap[nums[i]]++;
    }  

    vector<pair<int,int>> pairs;    //Pairs in freq : val

    for(auto it : umap){
        pairs.push_back({it.second,it.first});
    }
    sort(pairs.begin(),pairs.end());
    vector<int> top;
    int i = pairs.size()-1;
    while(k--){
        top.push_back(pairs[i].second);
        i--;
    }

    return top;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};

    vector<int> ans = topKFrequent(nums,2);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
