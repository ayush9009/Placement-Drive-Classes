class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    bool static comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

vector<int> sortByFreq(int arr[], int n) {
    vector<int> ans;
    vector<pair<int, int>> result;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    for (auto it : mp) {
        result.push_back({ it.first, it.second });
    }
    sort(result.begin(), result.end(), comp);
    for (auto it : result) {
        while (it.second) {
            ans.push_back(it.first);
            it.second--;  // Decrement the count after adding each element
        }
    }
    return ans;
}
};
