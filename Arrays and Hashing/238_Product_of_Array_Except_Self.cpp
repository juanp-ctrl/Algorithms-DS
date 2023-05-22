#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(),1);
    for(int i=0; i<nums.size()-1; i++){
        answer[i+1] = answer[i] * nums[i];
    }
    int postfix{1};
    for(int i=nums.size()-1; i>=0; i--){
        answer[i] *= postfix;
        postfix *= nums[i]; 
    }
    return answer;
}

int main(){
    vector<int> nums = {1,2,3,4};

    vector<int> ans = productExceptSelf(nums);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
