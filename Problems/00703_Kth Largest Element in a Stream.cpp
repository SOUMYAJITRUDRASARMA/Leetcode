class KthLargest {
public:
    // priority_queue<int> pqLower;
    priority_queue<int, vector<int>, greater<int>> pqUpper;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) add(num);
    }

    int add(int val) {
        if(pqUpper.size() < k){ pqUpper.push(val); return (pqUpper.size() == k)? pqUpper.top(): -1; }

        if(val > pqUpper.top())
        {
            /* pqLower.push(pqUpper.top()); */ pqUpper.pop();
            pqUpper.push(val);
        }
        // else pqLower.push(val);

        return pqUpper.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
