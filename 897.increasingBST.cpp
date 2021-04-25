

    void save(TreeNode* root, vector<int>& vec){
        if(!root) return;
        if(root->left){
            save(root->left, vec);
        }
        vec.push_back(root->val);
        if(root->right){
            save(root->right, vec);
        }

    }

    TreeNode* solve(vector<int> vec){
        TreeNode* head = new TreeNode(-1);
        TreeNode* tmp, *lst = head;
        for(int i = 0; i < vec.size(); ++i){
            tmp = new TreeNode(vec[i]);
            lst->right = tmp;
            lst = tmp;
        }
        return head->right;
    }



    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vec;//中序遍历存储值
        save(root, vec);
        TreeNode* res = solve(vec);
        return res;

    }