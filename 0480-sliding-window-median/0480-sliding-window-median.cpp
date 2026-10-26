class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<pair<double,int>>leftSide; 
        multiset<pair<double,int> ,greater<pair<double,int>>>rightSide;
        int left =0 , right =0 , n = nums.size(); 
        vector<double>ans;

        while( right < n ){

            leftSide.insert({nums[right],right}); 
            if( leftSide.size() - rightSide.size() > 1 ){
                rightSide.insert(*prev(leftSide.end()));
                leftSide.erase(prev(leftSide.end()));
            }
            if( rightSide.size() >0 and  prev(leftSide.end())->first > prev(rightSide.end())->first){
                leftSide.insert(*prev(rightSide.end())); 
                rightSide.erase(prev(rightSide.end()));
                rightSide.insert(*prev(leftSide.end())); 
                leftSide.erase(prev(leftSide.end()));
            }

            if( right - left +1 == k ){
                if(k%2 ==1){
                    double toPush = prev(leftSide.end())->first; 
                    ans.push_back(toPush); 
                }
                else{
                    double toPush = (prev(leftSide.end())->first + prev(rightSide.end())->first)/2.0;
                    ans.push_back(toPush); 
                }

                pair<double,int> toFind = { nums[left] , left }; 
                if(leftSide.find(toFind)!=leftSide.end()) leftSide.erase(toFind);
                else rightSide.erase(toFind); 
                left++;
            }
            right++; 
        }

        return ans;

    }
};