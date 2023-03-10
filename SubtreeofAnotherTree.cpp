//most optimised solution O(n) n->number of nodes of root

class Solution {
private:
    void serialise(TreeNode* root, string &str){
        if(!root){
            str+='+';
            return;
        }
        str += to_string(root->val);
        serialise(root->left, str);
        serialise(root->right, str);
    }
    vector<int>kmp(string txt, string pat){
        //making of pi table
        int n = txt.size();
        int m = pat.size();
        
        vector<int>pi(m,0);
        int j = 0;
        for(int i=1;i<m;i++){
            while(j>0 and pat[i] != pat[j]){
                j = pi[j-1];
            }
            if(pat[j] == pat[i])
                j++;
            pi[i] = j;
        }
        
        vector<int>occurance;
        j=0;
        for(int i=0;i<n;i++){
            while(j>0 and pat[j] != txt[i]){
                j = pi[j-1];
            }
            if(pat[j] == txt[i])
                j++;
            if(j == m){
                occurance.push_back(i-m+1);
                j = pi[j-1];
            }
        }
        return occurance;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root->left and !root->right){
            return root->val == subRoot->val;
        }
        string str = "";
        serialise(root, str);

        string pat = "";
        serialise(subRoot, pat);
        
        return kmp(str, pat).size();
    }
};