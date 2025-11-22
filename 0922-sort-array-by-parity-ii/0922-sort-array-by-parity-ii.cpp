class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans1 , ans3 ; 
        for( auto &it : nums ){
            if( it % 2 == 0  ){
                ans1.push_back(it); 
            }else{
                ans3.push_back(it);
            }

        }
        for( int i = 0 ;i<nums.size() ; i++){
           if( i%2 == 0 ) { nums[i] = ans1.back();
            ans1.pop_back();  
           }
           else  {
            nums[i] = ans3.back(); ans3.pop_back(); 
           }
            
        }
        return nums;
    }
};