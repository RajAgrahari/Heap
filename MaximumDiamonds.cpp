//https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1
long long maxDiamonds(int A[], int N, int k) 
    {
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<N;i++)
        pq.push(A[i]);
        while(!pq.empty() && k>0)
        {
            int x = pq.top();
            pq.pop();
            ans += (long long)x;
            pq.push(x/2);
            k--;
        }
        return ans;
    }
