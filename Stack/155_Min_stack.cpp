#include <bits/stdc++.h>
using namespace std;

//Using vectors due to their capabilities to resize in execution time and their O(1) operation times
class MinStack {
private:
    vector<int> stack;
    int minValue;
public:
    MinStack() {
        minValue = 2147483647;
    }
    
    void push(int val) {
        stack.push_back(val);
        minValue = min(minValue, val);
    }
    
    void pop() { 
        stack.pop_back();
        minValue = *min_element(stack.begin(), stack.end());
        if(stack.size() == 0) minValue = 2147483647; 
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minValue;
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    obj->pop();
    cout << obj->top();
    cout << obj->getMin();
    return 0;
}