#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

int longestConsecutiveS(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int longest{1}, temp{1};
    set<int> oset;
    for(int i=0; i<nums.size(); i++){
        oset.insert(nums[i]);
    }
    vector<int> redus;
    for(int i : oset){
        redus.push_back(i);
    }
    if(redus.size() > 1){
        for(int i=0; i<redus.size()-1; i++){
            if(redus[i+1] != redus[i]+1){
                if(temp >= longest){
                    longest = temp;
                    temp = 1;
                }
                else{
                    temp = 1;
                }
            }
            else{
                temp++;
            }
        }
        if(temp > longest){
            longest = temp;
        }
    }
    return longest;
}

//Using a hashset, we get rid of the repeated numbers and then by looking at the previous position of
//the number if it is empty we know that the sequence starts there and ends whenever the next position
//doesn't correspond to the increment of the previous number
int longestConsecutive(vector<int>& nums) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_set<int> hashset;
    int longestSequence{}, currentLongest{}, currentNumber{};

    for(int i : nums){
        hashset.insert(i);
    }
    for(int num : hashset){
        if(hashset.find(num-1) == hashset.end()){
            currentLongest = 1;
            currentNumber = num;
            while(hashset.find(currentNumber+1) != hashset.end()){
                currentLongest++;
                currentNumber++;
            }
            longestSequence = max(longestSequence, currentLongest);
        }
    }
    return longestSequence;
}


int main(){
    vector<int> nums = {100,4,200,1,3,2};

    int longestCons = longestConsecutive(nums);
    cout << longestCons << endl;
    return 0;
}
