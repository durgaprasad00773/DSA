class Solution {
public:
    vector<string> ans;
    int m, n;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


    struct trieNode
    {
        bool isend;
        trieNode* children[26];
        string word;
    };

    trieNode* getNode()
    {
        trieNode* root = new trieNode();
        root -> isend = false;
        root -> word = "";

        for(int i=0; i<26; i++)
        {
            root -> children[i] = NULL;
        }

        return root;
    }

    void insert(string s, trieNode* root)
    {
        trieNode* curr = root;
        for(int i=0; i<s.size(); i++)
        {
            int index = s[i] - 'a';
            if(curr -> children[index] == NULL)
            {
                curr -> children[index] = new trieNode();
            }
            curr = curr -> children[index];
        }
        curr -> isend = true;
        curr -> word = s;
    }
    void solve(int i, int j, vector<vector<char>> &board, trieNode* root)
    {
        if(i <0 || i>=m || j<0 || j>= n)
        return ;

        if(board[i][j] == '$' || root -> children[board[i][j]-'a'] == NULL)
        return ;

        root = root -> children[board[i][j] - 'a'];

        if(root -> isend == true)
        {
            ans.push_back(root -> word);
            root -> isend = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';

        for(auto &d : dirs)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            solve(ni, nj, board, root);
        }

        board[i][j] = temp;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        //create root
        trieNode* root = getNode();

        //insert
        for(auto &word : words)
        {
            insert(word, root);
        }

        //finding words
        //traversing only once
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(root -> children[board[i][j] - 'a'] != NULL)
                {
                    solve(i, j, board, root);
                }
            }
        }

        return ans;
    }
};