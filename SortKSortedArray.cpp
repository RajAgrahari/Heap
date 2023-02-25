// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-k-sorted-arrays
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<K;i++)
        {
           pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            ans.push_back(p.first);
            if(p.second.second+1 < K)
            pq.push({arr[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
        }
        return ans;
    }
