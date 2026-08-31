class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i: nums){
            if(pq.size() < k)
                pq.push(i);
            else if(pq.top() < i){
                pq.pop();
                pq.push(i);
            }
        }
    }
    
    int add(int val) {
        int i = val;
        if(pq.size() < k)
                pq.push(i);
            else if(pq.top() < i){
                pq.pop();
                pq.push(i);
            }
        return pq.top();
    }
};
