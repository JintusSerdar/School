class BinaryNode
{
public:
    int value;
    BinaryNode *left, *right;
    BinaryNode()
    {
        value = 0;
        left = right = 0;
    }
};

class BinaryTree
{
private:
    BinaryNode *root;
    int FindLeftMostLeaf(BinaryNode *node)
    {
        if (node == nullptr)
            return -1; // empty tree

        if (node->left == nullptr && node->right == nullptr)
            return node->value;

        if (node->left != nullptr)
            return FindLeftMostLeaf(node->left);

        return FindLeftMostLeaf(node->right);
    }

public:
    int FindLeftMostLeaf()
    {
        return FindLeftMostLeaf(root);
    }
};