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
    TreeNode *left;
    int mData;
    TreeNode *right;
    TreeNode(int iData) : mData(iData), right(nullptr), left(nullptr) {}
};

class Utils
{
public:
    static TreeNode *CreateTree(vector<tuple<int, int, int> > &irData);
    static void DeleteTree(TreeNode *ipHead);
};
class Solution
{
public:
    TreeNode *SortedArraryToBST(vector<int> &irData)
    {
        return hCreateBSTRWithArrary(irData, 0, irData.size() - 1);
    }

private:
    TreeNode *hCreateBSTRWithArrary(vector<int> &irData, int iBegin, int iEnd)
    {
        if (iBegin > iEnd)
            return nullptr;
        int lMiddle = iBegin + (iEnd - iBegin) / 2;

        TreeNode *lLeftNode = hCreateBSTRWithArrary(irData, iBegin, lMiddle - 1);
        TreeNode *lRightNode = hCreateBSTRWithArrary(irData, lMiddle + 1, iEnd);
        TreeNode *lRoot = new TreeNode(irData[lMiddle]);
        lRoot->left = lLeftNode;
        lRoot->right = lRightNode;
        return lRoot;
    }
};

void Case1()
{
    vector<int> lVec = {1, 2, 3};
    Solution S1;
    auto lResult = S1.SortedArraryToBST(lVec);
    assert(lResult != nullptr);
}
void Case2()
{
    vector<int> lVec = {1, 2, 3, 4};
    Solution S1;
    auto lResult = S1.SortedArraryToBST(lVec);
    assert(lResult != nullptr);
}
int main()
{
    Case1();
    Case2();
    return 0;
}

TreeNode *Utils::CreateTree(vector<tuple<int, int, int> > &irData)
{
    map<int, TreeNode *> lCreatedNodes;
    TreeNode *lpHead = nullptr;
    for (auto &it : irData)
    {
        auto [data, left, right] = it;
        TreeNode *lpNode = nullptr;

        if (lCreatedNodes.find(data) == lCreatedNodes.end())
        {
            lpNode = new TreeNode(data);
            lCreatedNodes[data] = lpNode;
            if (lpHead == nullptr)
                lpHead = lpNode;
        }
        else
        {
            lpNode = lCreatedNodes[data];
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
