class Solution {
public:

    class comp{
        public:
        bool operator()( const vector<int>& a , const vector<int>& b ){
            return a[0]>b[0];
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>, comp>pq; // element ,indexOfVec ,indexOfEle
        int start = 0 , end = INT_MAX , maxi = INT_MIN;
        int  k =nums.size(); 
        for(int i = 0 ;i<k ;i++){
            pq.push({nums[i][0] , i , 0 }); 
            maxi = max(maxi, nums[i][0]);
        }

        while(!pq.empty()){
            auto top  = pq.top(); pq.pop(); 
            int ele = top[0] ;
            int indexOfVec = top[1];
            int indexOfEle= top[2];

            if( end - start > maxi - ele ){
                start = ele;
                end = maxi;
            }

            if(indexOfEle+1 <nums[indexOfVec].size() ){
                    pq.push({ nums[indexOfVec][indexOfEle+1], indexOfVec , indexOfEle+1 });
                    maxi = max(maxi , nums[indexOfVec][indexOfEle+1]);
                }
                else{
                    break;
                }
                
           


        }
        return { start , end };

    }
};