class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) 
    {
        int n = nums.size();
        this->K = k;
        for(int i=0;i<k && i<n;i++)
        pq.push(nums[i]);
        for(int i=k;i<n;i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    int add(int val) {
         pq.push(val);
        if(pq.size()>K)
        pq.pop();
        return pq.top();
    }
};
