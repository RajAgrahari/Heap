//https://leetcode.com/problems/maximum-subsequence-score/description/
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int,int>> vp;
        int n = nums1.size();
        for(int i=0;i<n;i++)
        vp.push_back({nums2[i],nums1[i]});

        sort(vp.rbegin(),vp.rend());
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push(vp[i].second);
            sum += vp[i].second;
        }
        long long ans = sum*(long long)vp[k-1].first;
        for(int i=k;i<n;i++)
        {
            sum -= pq.top();
            pq.pop();
            pq.push(vp[i].second);
            sum += vp[i].second;
            ans = max(ans,(long long)((sum)*vp[i].first));
        }
        return ans;
        
    }
