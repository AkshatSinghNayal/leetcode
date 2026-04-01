class Solution {
public:

    class comp{
    public:
        bool operator()(const tuple<int,int,int>& a , const tuple<int,int,int>& b ){
            auto [sum, i, j] = a;
            auto [sum1, i1, j1] = b; 
            return sum > sum1;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, comp> pq;

        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;

        if(n == 0 || m == 0) return ans;

       
        for(int i = 0; i < n && i < k; i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(!pq.empty() and k-- ){
            auto [sum , i, j] = pq.top() ; pq.pop(); 
            ans.push_back({nums1[i] , nums2[j]}); 

            if( j+1< m ) pq.push({ nums1[i]+nums2[j+1] ,i,j+1});
        }

        return ans; 
    }
};