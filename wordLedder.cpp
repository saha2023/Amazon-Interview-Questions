//The time complexity of the solution is O(N * w * 26^w), where N is the number of words in the wordList and w is the length of the words in the wordList.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        
        for(string str:wordList){
            st.insert(str);
        }
        
        queue<string>que;
        que.push(beginWord);
        
        int rad = 0;
        
        while(que.size()){
            int sz = que.size();
            while(sz--){
                string top = que.front();
                que.pop();
                if(top == endWord) return rad+1;
                string tmp = top;
                for(int i=0;i<tmp.size();i++){
                    for(char ch = 'a'; ch<= 'z'; ch++){
                        tmp[i] = ch;
                        if(tmp != top and st.count(tmp)){
                            que.push(tmp);
                            st.erase(tmp);
                        }
                    }
                    tmp[i] = top[i];
                    // tmp = top;
                }
            }
            rad++;
        }
        return 0;
    }
};