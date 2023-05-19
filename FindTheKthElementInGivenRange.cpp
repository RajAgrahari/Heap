//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1
vector<int> kthSmallestNum(int n, vector<vector<int>>& intervals, int q, vector<int>queries)
    {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        pq.push(intervals[i]);
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            pq.pop();
            int idx = temp[0];
            int mx = temp[1];
            while(!pq.empty() && mx>=pq.top()[0])
            {
                mx = max(mx,pq.top()[1]);
                pq.pop();
            }
            temp.clear();
            temp.push_back(idx);
            temp.push_back(mx);
            ans.push_back(temp);
        }
        
        vector<int> pre(ans.size());
        pre[0] = (ans[0][1]-ans[0][0]+1);
        for(int i=1;i<ans.size();i++)
        pre[i] = pre[i-1]+(ans[i][1]-ans[i][0]+1);
        vector<int> res;
        for(int i=0;i<q;i++)
        {
            int idx = lower_bound(pre.begin(),pre.end(),queries[i])-pre.begin();
            if(idx==pre.size())
            res.push_back(-1);
            else
            {
                if(idx==0)
                res.push_back(ans[idx][0]+queries[i]-1);
                else
                res.push_back(ans[idx][0]+(queries[i]-pre[idx-1])-1);
            }
        }
        return res;
        
    } 
