 long long minCost(long long arr[], long long n) {
        if(n==1)
        return 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i=0;i<n;i++)
        pq.push(arr[i]);
        
        long long sum=0;
        while(pq.size()>1)
        {
          long long ele1=pq.top();
          pq.pop();
          long long ele2=pq.top();
          pq.pop();
          sum += ele1+ele2;
          pq.push(ele1+ele2);
        }
        return sum;
    }
