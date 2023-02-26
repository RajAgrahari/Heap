// https://leetcode.com/problems/top-k-frequent-elements/
vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<pair<int,int>> vp;
        for(int x:nums)
        mp[x]++;
        for(auto it:mp)
        vp.push_back({it.second,it.first});
        sort(vp.rbegin(),vp.rend());
        for(int i=0;i<k;i++)
        ans.push_back(vp[i].second);
        return ans;
    }
