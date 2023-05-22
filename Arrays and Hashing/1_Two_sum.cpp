#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;   //Value : Index
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            auto it = umap.find(diff);
            if(it != umap.end()){
                return {it->second, i};
            }
            else{
                umap.insert(make_pair(nums[i], i));
            }
        }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};

    vector<int> ans = twoSum(nums,9);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
