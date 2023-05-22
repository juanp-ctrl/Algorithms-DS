#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;


bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numbers;
    for(int i : nums){
        if(numbers.insert(i).second == false){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int> nums = {1,2,3,1,2};

    if(containsDuplicate(nums)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
