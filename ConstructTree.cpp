/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不包含重复的数字。
例如输入前序遍历｛1，2，4，7，3，5，6，8｝和中序遍历｛4，7，2，1，5，3，8，6｝，则输出如图所示的二叉树并返回它的头结点。
                1
             /    \
           2       3
        /         /  \
      4         5    6
        \             /
          7         8
*/

#include<iostream>
#include<exception>
using namespace std;
struct BinaryTreeNode{
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    //前序遍历序列的第一个数字是根节点的值
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder&&*startPreorder == *startInorder)
            return root;
        else
            throw std::exception();
    }
    //在中序遍历中找到根节点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder&&*rootInorder != rootValue)
        rootInorder++;
    if (rootInorder == endInorder&&*rootInorder != rootValue)
        throw std::exception();
    int leftLen = rootInorder - startInorder;
    int* leftPreordererEnd = startPreorder + leftLen;
    if (leftLen>0)
    {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreordererEnd, startInorder, rootInorder - 1);
    }
    if (leftLen<endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreordererEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}
BinaryTreeNode*  Construct(int* preorder, int * inorder, int len)
{
    if (preorder == NULL || inorder == NULL || len <= 0)
        return NULL;
    return ConstructCore(preorder, preorder + len - 1, inorder, inorder + len - 1);
}
void preorderInput(BinaryTreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->m_nValue << " ";
    preorderInput(root->m_pLeft);
    preorderInput(root->m_pRight);
}
void inorderInput(BinaryTreeNode* root)
{
    if (root == NULL)
        return;
    inorderInput(root->m_pLeft);
    cout << root->m_nValue << " ";
    inorderInput(root->m_pRight);
}
int main(int argc, char const *argv[])
{
    int preorderArray1[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorderArray1[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int preorderArray2[8] = { 1, 2, 4, 3, 5, 6, 8 };
    int inorderArray2[8] = { 9, 2, 4, 3, 5, 6, 8 };
    int preorderArray3[8] = { 1, 2, 4, 3, 5, 6, 8 };
    int *inorderArray3=NULL;
    BinaryTreeNode* bt1 = Construct(preorderArray1, inorderArray1, 8);
    preorderInput(bt1);
    cout << endl;
    inorderInput(bt1);
    cout << endl;

    BinaryTreeNode* bt2 = Construct(preorderArray2, inorderArray2, 8);
    preorderInput(bt2);
    cout << endl;
    inorderInput(bt2);
    cout << endl;

    BinaryTreeNode* bt3 = Construct(preorderArray3, inorderArray3, 8);
    preorderInput(bt3);
    cout << endl;
    inorderInput(bt3);
    cout << endl;
    return 0;
}
