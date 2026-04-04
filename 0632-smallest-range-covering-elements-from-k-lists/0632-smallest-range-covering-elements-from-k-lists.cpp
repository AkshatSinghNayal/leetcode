class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq ; // ele indexOfVector indexOfEle 
        int k = nums.size(); 

        int start = 0 , maxi  = INT_MIN , end = INT_MAX ; 
        for(int i =0 ;i< k ;i++ ){
            pq.push({nums[i][0] , i , 0 }); 
            maxi = max(maxi, nums[i][0]);

        } 


        while( true ){
            auto top =pq.top();pq.pop();
            int ele = top[0];
            int indexOfVector = top[1]; 
            int indexOfEle = top[2]; 

            if( maxi - ele < end -start ){
                start = ele ;
                end   = maxi;
            }

            if(indexOfEle+1 < nums[indexOfVector].size() ){
                pq.push({nums[indexOfVector][indexOfEle+1],indexOfVector, indexOfEle+1});
                maxi = max(maxi, nums[indexOfVector][indexOfEle+1]);
            }
            else{
                break;
            }


        }
        return{start ,end};

    }
};