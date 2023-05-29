#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        if(nums[i] > 0) break;
        if(i > 0 && nums[i-1] == nums[i]) continue;

        int l = i+1, r = nums.size()-1;
        while(l < r){
            int ThreeSum = nums[i] + nums[l] + nums[r];
            if(ThreeSum > 0){
                r--;
            }
            else if(ThreeSum < 0){
                l++;
            }
            else{
                res.push_back({ nums[i], nums[l], nums[r] });
                l++;
                while(nums[l-1] == nums[l] && l < r){
                    l++;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(nums);
    for(auto i : ans){
        for(int j : i){
            cout << j << " ";
        }
    }
    cout << endl;
    return 0;
}
