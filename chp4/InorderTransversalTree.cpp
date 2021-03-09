#include<stack>
#include<vector>

using namespace std;

struct  TreeNode
{
    TreeNode* right; 
    TreeNode* left; 
    int mData;
    TreeNode(int iData):mData(iData),right(nullptr),left(nullptr){}
};
void InOrderTransversalTree(TreeNode* iRoot, vector<int>& irValues)
{
    stack<TreeNode*> lStack;
    TreeNode* lpNode = iRoot;
    if(iRoot == nullptr)
        return; 
    lStack.push(lpNode);
    while (!lStack.empty()|| lpNode)
    {
       if(lpNode)
       {
           lStack.push(lpNode);
           lpNode = lpNode->left;
       }
       else
       {
           TreeNode* lpTop = lStack.top();
           irValues.push_back(lpTop->mData);
           lStack.pop();
           lpNode = lpTop->right;
       }       
    }
    
    
}
void testAcceptance()
{
    TreeNode lpNode1(1);
    TreeNode lpNode2(2);
    TreeNode lpNode3(3);
    TreeNode lpNode4(4);
    TreeNode lpNode5(5);
    TreeNode lpNode6(6);
    TreeNode lpNode7(7);
    lpNode1.left = & lpNode2;
    lpNode1.right = & lpNode3;
    lpNode2.left = &lpNode4;
    lpNode2.right = & lpNode5;
    lpNode3.left = & lpNode6;
    lpNode4.right = & lpNode7;
    vector<int> lInOrder; 
    InOrderTransversalTree(&lpNode1, lInOrder);
    assert(lInOrder[0] == 4);
    assert(lInOrder[1] == 7);
    assert(lInOrder[2] == 2);
    assert(lInOrder[3] == 5);
    assert(lInOrder[4] == 1);
    assert(lInOrder[5] == 6);
    assert(lInOrder[6] == 3);
}
int main()
{
    testAcceptance();
    return 0;
}