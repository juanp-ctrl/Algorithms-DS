#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size()-1;
    int twosum;
    while(l<r){
        twosum = numbers[l]+numbers[r];
        if(twosum > target){
            r--;
        }
        else if(twosum < target){
            l++;
        }
        else{
            return {l+1,r+1};
        }
    }
    return {};
}

int main(){
    vector<int> nums = {1,5,9,10,11,17};

    vector<int> ans = twoSum(nums,28);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
