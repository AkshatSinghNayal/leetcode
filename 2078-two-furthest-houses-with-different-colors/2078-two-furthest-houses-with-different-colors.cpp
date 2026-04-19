class Solution {
public:
    int maxDistance(vector<int>& colors) {
    int n = colors.size(), maxi = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] != colors[0]) maxi = max(maxi, i);
        if (colors[i] != colors[n - 1]) maxi = max(maxi, n - 1 - i);
    }
    return maxi;
}
};