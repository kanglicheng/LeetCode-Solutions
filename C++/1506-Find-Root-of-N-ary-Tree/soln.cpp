/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int val = 0;
        for(const auto & node : tree) {
            val += node->val;
            for(const auto & child : node->children) {
                val -= child->val;
            }
        }
        for(const auto & node : tree) {
            if(node->val == val) return node;
        }
        return nullptr;
    }
};