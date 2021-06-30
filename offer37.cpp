#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {

public:
	string serialize(TreeNode* root) {
		string r = "";
		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty())
        {
			auto c = q.front();
			if (c != nullptr)
            {
				q.push(c->left);//空指针也入队
				q.push(c->right);
			}

			q.pop();

			if (c == nullptr)
            {
				r.append("x");
			}
			else
            {
				r.append(to_string(c->val));
			}

			r.append(",");
		}
		return r;//无论root是不是null,结尾一定有，
	}

    // 从字符串s里按照","拆分出每个结果插入到队列里 
    void Transfer(queue<string>& v, const string& s)
	{
		int begin = 0;
        int n = s.size();
        int start = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ',')
            {
                v.emplace(s.substr(start, i - start));
                start = i + 1;//始终是第一个数字或#的位置
            }
        }
        //  默认总是有一个 , 所以无需担心结束情况
	}
    
	TreeNode* make(queue<string> & v)
	{
		TreeNode* root = nullptr;

		queue<TreeNode*> q;

        // 设置第一个根结点
		string head = v.front();
		if (head != "x") {
			root = new TreeNode(stoi(head));
			q.push(root);		
		}
		v.pop();

        int currSize;
		while (!v.empty())
		{   
            currSize = q.size();
            for (int i = 0; i < currSize; ++i)
            {
                TreeNode* curr = q.front();
                q.pop();
                string currLeft = v.front();
                v.pop();
                string currRight = v.front();
                v.pop();
                if (currLeft != "x")
                {
                    TreeNode* left = new TreeNode(stoi(currLeft));
                    curr->left = left;
                    q.push(left);
                }
                if (currRight != "x")
                {
                    TreeNode* right = new TreeNode(stoi(currRight));
                    curr->right = right;
                    q.push(right);
                }
            }
		}

		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
    {
		queue<string> q;
		Transfer(q, data);
		return make(q);
	}
};

int main()
{  

   int ans = 0;
   cout << ans << endl;
   return 0;
}
