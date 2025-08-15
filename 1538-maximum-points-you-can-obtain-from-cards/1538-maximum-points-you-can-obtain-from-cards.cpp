class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start =0; 
        int end = cardPoints.size()-1;
        int sum = 0;
        int maxSum=0;
        while(start<k){
            sum+=cardPoints[start];
            if(start == k-1) break;
            start++;
        }
            maxSum = max(maxSum , sum);

        while(start>=0){

            sum = (sum- cardPoints[start--]) + cardPoints[end--];

            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};