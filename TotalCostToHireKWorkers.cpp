//https://leetcode.com/problems/total-cost-to-hire-k-workers/description/
long long totalCost(vector<int>& costs, int k, int c) 
    {
        int n = costs.size();
        int ck = c*2+k-1;
        long long cst = 0;
        if (ck >= n)
        {
            sort(costs.begin(), costs.end());
            
            for (int i = 0; i < k; i++)
            {
                cst += costs[i];
            }
            
            return cst;
        }
        set<pair<int,int>> st;
        for(int i=0;i<c && i<n;i++)
        {
            st.insert({costs[i],i});
        }
        for(int i=n-1;i>(n-1-c) && i>=0;i--)
        {
            st.insert({costs[i],i});
        }
    
        int l = c-1,r = n-c;
        while(!st.empty() && k--)
        {
            auto [ele,ind] = *st.begin();
            st.erase(st.begin());
            cst += ele;
            if(ind <= l)
            {
                l++;
                if(l >= n)
                break;
                st.insert({costs[l],l});
            }
            else{
                r--;
                if(r<0)
                break;
                st.insert({costs[r],r});
            }
            
        }
        return cst;


    }
