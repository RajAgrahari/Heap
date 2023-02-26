// https://leetcode.com/problems/top-k-frequent-elements/

//T.C = O(N*LogN) S.C. = O(N)
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

//T.C = O(K*LogK) S.C = O(N)
 vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int x:nums)
        mp[x]++;
        int temp=0;
        auto it = mp.begin();
        for(it=mp.begin();it!=mp.end() && temp<k;it++)
        {
            pq.push({it->second,it->first});
            temp++;
        }
        for(it;it!=mp.end() && temp<nums.size();it++)
        {
            if(!pq.empty() && pq.top().first < it->second)
            {
               pq.pop();
               pq.push({it->second,it->first});
            }
            temp++;
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
