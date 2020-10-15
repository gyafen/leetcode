#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        queue<int> depth;

        q.push(root);
        depth.push(1);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            int level = depth.front();
            depth.pop();

            if (front != nullptr)
            {
                q.push(front->left);
                depth.push(level + 1);
                q.push(front->right);
                depth.push(level + 1);

                if ((!q.empty()))
                {
                    if (q.front() != nullptr)
                    {
                        if (level == depth.front())
                        {
                            front->next = q.front();
                        }
                        else
                        {
                            front->next = nullptr;
                        }
                        
                    }
                }
            }
        }
        return root;
    }
};