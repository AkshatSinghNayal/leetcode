class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<pair<long,int>>rightSide;
        multiset<pair<long,int>,greater<pair<long,int>>> leftSide;
        vector<double>ans; 
        int n = nums.size() , left =0 ; 
        for(int right = 0 ;right< n ; right++ ){
            pair<long,int> newPair = {nums[right],right}; 
            rightSide.insert(newPair);
            auto it  = prev(rightSide.end());
            leftSide.insert(*it);
            rightSide.erase(it);

            if(leftSide.size()-1 > rightSide.size() ){
                auto it  = prev(leftSide.end());
                rightSide.insert(*it);
                leftSide.erase(it);
            }

            if( left <=n-k and right-left +1 > k ){ // this is the case when we have more element in multiset
                pair<long , int> toRemove = {nums[right-k],right-k}; 
                if( leftSide.find(toRemove)!=leftSide.end()) leftSide.erase(toRemove);
                else if(rightSide.find(toRemove)!=rightSide.end()) rightSide.erase(toRemove);

                if(leftSide.size() > rightSide.size()+1 ){
                    auto it  = prev(leftSide.end());
                    rightSide.insert(*it);
                    leftSide.erase(it);
                }
                else if (leftSide.size() < rightSide.size()){
                    auto it = prev(rightSide.end()); 
                    leftSide.insert(*it);
                    rightSide.erase(it); 
                }
                left++; 
            }

            if( right -left +1 == k  ){
                double median; 
                if( k%2 != 0 ){
                    auto it = prev(leftSide.end()); 
                    median = it->first;
                }
                else{
                    auto it = prev(leftSide.end());
                    auto itt = prev(rightSide.end());
                    median = (it->first+itt->first)/2.0; 
                }
                ans.push_back(median);
            }
        } 
        return ans; 
    }
};