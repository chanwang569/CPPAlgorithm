#include <map>
#include <set>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
const int gcEmptyNode = -1;
struct TreeNode
{
    int mData;
    TreeNode *left;
    
    TreeNode *right;

    TreeNode(int iData) : mData(iData), right(nullptr), left(nullptr) {}
};
class Solution
{
public:
    int getTreeHeight(TreeNode *ipRoot, queue<int> &irNodeProcesse)
    {
        if (ipRoot)
        {
            irNodeProcesse.push(ipRoot->mData);
        }
        else
        {
            irNodeProcesse.push(-1);
        }

        if (ipRoot == nullptr)
            return 0;
        int lLeftHeight = getTreeHeight(ipRoot->left, irNodeProcesse);
        int lRightHeight = getTreeHeight(ipRoot->right, irNodeProcesse);
        return lLeftHeight > lRightHeight ? lLeftHeight + 1 : lRightHeight + 1;
    }

    bool isBalanceTree(TreeNode *ipRoot, queue<int> &irNodeProcesse)
    {
        if (ipRoot == nullptr)
        {
            return true;
        }
        int lLeftHeight = getTreeHeight(ipRoot->left, irNodeProcesse);
        int lRightHeight = getTreeHeight(ipRoot->right, irNodeProcesse);
        int lSubtreeAbs = abs(lLeftHeight - lRightHeight);
        return (lSubtreeAbs <= 1 && isBalanceTree(ipRoot->left, irNodeProcesse) && isBalanceTree(ipRoot->right, irNodeProcesse));
    }
};
class Solution2
{
public:
    int hIsBalancedTree(TreeNode *ipRoot)
    {
        if (ipRoot == nullptr)
            return 0;
        int lLeftHeight = hIsBalancedTree(ipRoot->left);
        if (lLeftHeight == -1)
            return -1;
        int lRightHeight = hIsBalancedTree(ipRoot->right);
        if (lRightHeight == -1)
            return -1;
        return max(lLeftHeight, lRightHeight) + 1;
    }
    bool isBalanceTree(TreeNode *ipRoot)
    {
        return hIsBalancedTree(ipRoot) != -1;
    }
};
 class Utils
{
public:
    static TreeNode *CreateTree(map<int, tuple<int, int> > &irData);
    static void DeleteTree(TreeNode *ipHead);
};

void iSBalancedTreeAcceptance()
{
    map<int, tuple<int, int> > lTreeDataMap;
    lTreeDataMap[1] = std::make_tuple(2, 3);
    lTreeDataMap[2] = make_tuple(4, 5);
    lTreeDataMap[3] = make_tuple(6, 7);
    lTreeDataMap[4] = make_tuple(8, 9);
    TreeNode *lpTree = Utils::CreateTree(lTreeDataMap);
    queue<int> lQueue;
    Solution S1;
    bool lIsBalancedTree = S1.isBalanceTree(lpTree, lQueue);
    assert(lIsBalancedTree == true); // lQueue.size() == 50
    Solution2 S2;
    lIsBalancedTree = S2.isBalanceTree(lpTree);
    assert(lIsBalancedTree == true);
    Utils::DeleteTree(lpTree);
}
int main()
{
    iSBalancedTreeAcceptance();
    return 0;
}

TreeNode *Utils::CreateTree(map<int, tuple<int, int> > &irData)
{
    map<int, TreeNode *> lCreatedNodes;
    TreeNode *lpHead = nullptr;
    for (auto &it : irData)
    {
        auto [left, right] = it.second;
        TreeNode *lpNode = nullptr;

        if (lCreatedNodes.find(it.first) == lCreatedNodes.end())
        {
            lpNode = new TreeNode(it.first);
            lCreatedNodes[it.first] = lpNode;
            if (lpHead == nullptr)
                lpHead = lpNode;
        }
        else
        {
            lpNode = lCreatedNodes[it.first];
        }
        if (left != gcEmptyNode)
        {
            if (lCreatedNodes.find(left) != lCreatedNodes.end())
            {
                lpNode->left = lCreatedNodes[left];
            }
            else
            {
                TreeNode *tmp = new TreeNode(left);
                lpNode->left = tmp;
                lCreatedNodes[left] = tmp;
            }
        }
        if (right != gcEmptyNode)
        {
            if (lCreatedNodes.find(right) != lCreatedNodes.end())
            {
                lpNode->right = lCreatedNodes[right];
            }
            else
            {
                TreeNode *tmp = new TreeNode(right);
                lpNode->right = tmp;
                lCreatedNodes[right] = tmp;
            }
        }
    }
    return lpHead;
}

void Utils::DeleteTree(TreeNode *ipHead)
{
    if (ipHead == nullptr)
        return;
    if (ipHead->left == nullptr && ipHead->right == nullptr)
    {
        delete ipHead;
    }
    else
    {
        if (ipHead->left)
            DeleteTree(ipHead->left);
        if (ipHead->right)
            DeleteTree(ipHead->right);
        delete ipHead;
    }
}
