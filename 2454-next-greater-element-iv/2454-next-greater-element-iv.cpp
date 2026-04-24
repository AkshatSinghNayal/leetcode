class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n  = nums.size(); 
        stack<int> first , second ; // store indexes
        vector<int>ans(n,-1); 
        for(int i = 0 ; i< n; i++  ){

            while(!second.empty() and nums[i] > nums[second.top()]){
                ans[second.top()] = nums[i]; 
                second.pop(); 
            }

            stack<int>temp; 
            while(!first.empty() and nums[first.top()] < nums[i] ){
                temp.push(first.top()); 
                first.pop(); 
            }
            first.push(i); 


            while(!temp.empty()){
                second.push(temp.top()); 
                temp.pop(); 
            }

        }
        return ans; 
    }
};