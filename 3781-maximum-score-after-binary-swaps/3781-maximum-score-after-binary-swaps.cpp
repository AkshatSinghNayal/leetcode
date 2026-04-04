class Solution {
public:

    class comp{
        public: 
        bool operator()( const int a , const int b ){
            return a> b ; 
        }
    }; 

    long long maximumScore(vector<int>& nums, string s) {
        long long ans  = 0  ; 
        int count1 =0 ; 
        int n  = nums.size(); long long sum = 0; 
        priority_queue<int , vector<int> , comp > pq ; 
        for(int i = n-1 ; i>=0 ;i-- ){
            if( s[i] == '1') count1++; 

            if(count1>0 or s[i] == '1'){
                pq.push(nums[i]); 
                sum+=nums[i]; 
            }

            while(pq.size() > count1 ){
                sum-=pq.top();
                pq.pop();
            }

        }
        return sum; 
    }
};