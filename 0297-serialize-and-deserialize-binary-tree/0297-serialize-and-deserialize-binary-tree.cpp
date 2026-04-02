/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root ==NULL) return "";

        queue<TreeNode*> q;
        q.push(root);

        string s = "";

        while (!q.empty()) {
            TreeNode*node = q.front();
            q.pop();

            if (node ==NULL) {
                s += "#,";
                continue;
            }

            s += to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()== 0) return NULL;

        stringstream ss(data);
        string token;

        getline(ss,token,',');
        TreeNode* root  = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss,token,',');
            if (token != "#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            getline(ss,token,',');
            if (token != "#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));