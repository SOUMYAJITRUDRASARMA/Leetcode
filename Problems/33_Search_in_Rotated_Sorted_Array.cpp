class Solution {
public:
    int searchHelper(vector<int> &a, int l, int h, int key){
        //complete the function here
        int mid = (l + h) / 2;
        if(a[mid] == key) return mid;
        if(h < l) return -1;

        if(a[mid] < key)
        {
            if(a[mid] < a[l])
            {
                if(a[l] > key) return searchHelper(a, mid + 1, h, key);
                else return searchHelper(a, l, mid - 1, key);
            }
            else return searchHelper(a, mid + 1, h, key);
        }
        else
        {
            if(a[h] < a[mid])
            {
                if(a[h] >= key) return searchHelper(a, mid + 1, h, key);
                else return searchHelper(a, l, mid - 1, key);
            }
            else return searchHelper(a, l, mid - 1, key);
        }
    }

    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
};
