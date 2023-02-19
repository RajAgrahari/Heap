vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) 
    {
        priority_queue<pair<int,pair<int,int>>> pq;

        sort(A.begin(),A.end());

        sort(B.begin(),B.end());

        for(int i=0;i<N;i++)
        pq.push({A[i]+B[N-1],{i,N-1}});
        vector<int> ans;
        while(!pq.empty() && K--)
        {
            auto it=pq.top();
            pq.pop();
            int data=it.first;
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back(data);
            if(y!=0)
            pq.push({A[x]+B[y-1],{x,y-1}});

        }
        return ans;
    }
