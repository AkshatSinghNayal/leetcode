class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;
        for (int i = 0; i < operations.size(); i++) {
            string a = operations[i];
            char c = a[0];
            if ((c >= '0' && c <= '9') || c == '-') { // carefull -2 have 0 and 1 index 
                arr.push_back(stoi(a)); 
            }

            else if (c == 'C')
                arr.pop_back();
            else if (c == 'D') {
                int digit = arr.back() * 2;
                arr.push_back(digit);
            } else if (c == '+') {
                int size = arr.size();
                int digit = arr[size - 1] + arr[size - 2];
                arr.push_back(digit);
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};