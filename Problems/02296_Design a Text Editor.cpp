class TextEditor {
public:
    deque<char> dqLeft, dqRight;

    TextEditor() {
        // the cursor is between the deques
        // back -- dqLeft -- front   |cursor|   back -- dqRight -- front
    }

    void addText(string text) {
        for(char ch: text)
            dqLeft.push_front(ch);
    }

    int deleteText(int k) {
        int ans = min(k, (int)dqLeft.size());
        if(ans == dqLeft.size()) dqLeft.clear();
        else while(k-- && !dqLeft.empty()) dqLeft.pop_front();

        return ans;
    }

    string cursorLeft(int k) {
        string ans;
        char ch;
        int times = 10;
        deque<char>::iterator it;

        while(k-- && !dqLeft.empty())
        {
            ch = dqLeft.front(); dqLeft.pop_front();
            // if(helper.size() < 10) helper.push(ch);
            dqRight.push_back(ch);
        }

        if(dqLeft.empty()) return "";

        it = dqLeft.begin();
        while(it != dqLeft.end() && --times) it++;
        if(it == dqLeft.end()) it--;
        while(it != dqLeft.begin()) ans.push_back(*it), it--;
        ans.push_back(*it);

        return ans;
    }

    string cursorRight(int k) {
        string ans;
        char ch;
        int times = 10;
        deque<char>::iterator it;

        while(k-- && !dqRight.empty())
        {
            ch = dqRight.back(); dqRight.pop_back();
            // if(ans.size() < 10) ans.push_back(ch);
            dqLeft.push_front(ch);
        }

        if(dqLeft.empty()) return "";

        it = dqLeft.begin();
        while(it != dqLeft.end() && --times) it++;
        if(it == dqLeft.end()) it--;
        while(it != dqLeft.begin()) ans.push_back(*it), it--;
        ans.push_back(*it);

        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
