#define CAP 10

class Twitter {
public:
    struct Node
    {
        int tweet, time;
        Node *next, *prev;
        Node(int tweet = 0, int time = 0, Node *prev = nullptr, Node *next = nullptr){ this->tweet = tweet; this->time = time; this->next = next; this->prev = prev; }
    };

    static void insertHead(Node *n, Node *&head, Node *&tail)
    {
        // n->next = n->prev = nullptr;
        if(!head) head = tail = n;
        else n->next = head, head->prev = n, head = n;
    }

    static void deleteTail(Node *&head, Node *&tail)
    {
        if(!head) return;
        else
        {
            Node *n = tail;
            tail = tail->prev;
            delete n;
            if(!tail) head = tail;
        }
    }

    struct LRUCache
    {
        Node *head, *tail;
        int curSize;
        LRUCache(){ head = tail = nullptr; curSize = 0; }
        void insert(int tweet, int time)
        {
            Node *n = new Node(tweet, time);
            insertHead(n, head, tail);
            if(curSize == CAP) deleteTail(head, tail);
            else curSize++;
        }
    };

    struct UserData
    {
        unordered_set<int> following;
        LRUCache tweetCache;
    };

    vector<UserData> v;
    int maxUserSize;
    int globalTime;

    Twitter() {
        globalTime = 1;
        maxUserSize = 500;
        v.resize(maxUserSize + 1);
    }

    void postTweet(int userId, int tweetId) {
        v[userId].tweetCache.insert(tweetId, globalTime++);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        vector<Node *> feedList;
        if(v[userId].tweetCache.head) feedList.push_back(v[userId].tweetCache.head);
        for(int people: v[userId].following) if(v[people].tweetCache.head) feedList.push_back(v[people].tweetCache.head);
        int rem = CAP, maxFeedPos, maxTime, n = feedList.size();

        while(rem--)
        {
            maxTime = INT_MIN;
            for(int i=0;i<n;i++)
                if(feedList[i] && feedList[i]->time > maxTime) maxTime = feedList[i]->time, maxFeedPos = i;

            if(maxTime == INT_MIN) break;

            feed.push_back(feedList[maxFeedPos]->tweet);
            feedList[maxFeedPos] = feedList[maxFeedPos]->next;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        v[followerId].following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        v[followerId].following.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
