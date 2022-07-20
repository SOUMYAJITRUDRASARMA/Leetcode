class Solution {
public:
    struct Person
    {
        int fruit1, cnt1;
        int fruit2, cnt2;
        Person(){ fruit1 = fruit2 = -1; cnt1 = cnt2 = 0; }
        bool canCollect(int fruit){ return fruit1 == -1 || fruit2 == -1 || fruit1 == fruit || fruit2 == fruit; }
        void collect(int fruit)
        {
            if(fruit1 == -1){ fruit1 = fruit, cnt1 = 1; }
            else if(fruit1 == fruit) cnt1++;
            else if(fruit2 == -1){ fruit2 = fruit, cnt2 = 1; }
            else if(fruit2 == fruit) cnt2++;
        }
        void remove(int fruit)
        {
            if(fruit1 == fruit)
            {
                cnt1--;
                if(!cnt1) fruit1 = -1;
                if(fruit2 != -1) swap(fruit1, fruit2), swap(cnt1, cnt2);
            }
            else if(fruit2 == fruit)
            {
                cnt2--;
                if(!cnt2) fruit2 = -1;
            }
        }
        int size(){ return cnt1 + cnt2; }
    };

    int totalFruit(vector<int>& fruits) {
        Person p;
        int ptr1 = 0, ptr2 = 0, n = fruits.size(), MAX = INT_MIN;
        while(ptr1 < n)
        {
            while(!p.canCollect(fruits[ptr1])) p.remove(fruits[ptr2++]);
            p.collect(fruits[ptr1++]);
            MAX = max(MAX, p.size());
        }

        return MAX;
    }
};
