// https://leetcode.com/problems/ipo/
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = capital.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minpq;
        priority_queue<int> maxpq;
        for(int i=0;i<n;i++)
        minpq.push({capital[i],profits[i]});
        while(k>0)
        {
            while(!minpq.empty() && w>=minpq.top().first)
            {
                maxpq.push(minpq.top().second);
                minpq.pop();
            }
            if(maxpq.empty())
            break;
            w += maxpq.top();
            maxpq.pop();
            k--;
        }
        return w;
    }
