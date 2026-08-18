class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans; 
        int n  = firstList.size(); int j = 0 , m = secondList.size(); 

        for(int i  = 0 ;i<firstList.size() ;i++ ){
            int index=  i;
            while( index< firstList.size() and j<m ){
                int start = firstList[index][0] , end =  firstList[index][1]; 
                int currS = secondList[j][0] , currE =secondList[j][1] ; 
                int temp = index+1;
                
                if( currS>=start and currS <= end or  start>=currS and start<= currE ){
                    ans.push_back({ max(start , currS) , min( currE , end ) }); 

                    while( temp < n and currE >= firstList[temp][0]){
                        ans.push_back({firstList[temp][0] , min( currE , firstList[temp][1])});    
                        temp++; 
                    }
                }
                else if( start < currS and end < currS  ){
                    break;
                }
                j++; 


            }

        }

        return ans;
    }
};