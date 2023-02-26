//https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
    priority_queue<int> sh, lh;
    public:
    MedianFinder() { }
    
    void addNum(int num) 
    {
        lh.push(-num);
        sh.push(-lh.top());
        lh.pop();
        
        if (sh.size() > lh.size())
            lh.push(-sh.top()), sh.pop();
    }
    
    double findMedian() 
    {
        if (sh.size() == lh.size())
            return (sh.top() - lh.top()) / 2.0;
        return -lh.top();
    }
};
