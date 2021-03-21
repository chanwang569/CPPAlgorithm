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
    bool isBinarySearchTree(TreeNode* ipRoot, TreeNode* ipTarget)
    {
        if(ipTarget == nullptr)
            return true;
        if(ipRoot == nullptr) // ipRoot == nullptr, we cannot find a node can match to target.
            return false;
        if(ipRoot->mData == ipTarget->mData && hIsMatchTree(ipRoot, ipTarget))
            return true;
     
        return isBinarySearchTree(ipRoot->left, ipTarget) || isBinarySearchTree(ipRoot->right, ipTarget);
        
    }
    // Check exactly Same tree 
    bool hIsMatchTree(TreeNode* ipSource, TreeNode* ipTarget)
    { 
        if(ipSource == nullptr && ipTarget == nullptr )
            return true;

        if(ipSource == nullptr || ipTarget == nullptr || ipSource->mData != ipTarget->mData)
            return false;    
       
        return hIsMatchTree(ipSource->left, ipTarget->left) 
                && hIsMatchTree(ipSource->right, ipTarget->right);
        
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lSoureDatas;
    lSoureDatas.push_back(std::make_tuple(1,2,3));
    TreeNode* lpSourceTree = Utils::CreateTree(lSoureDatas);
    TreeNode* lpTargetTree = Utils::CreateTree(lSoureDatas);
    Solution S1;
    assert(S1.isBinarySearchTree(lpSourceTree, lpTargetTree) == true);
}
void Case2()
{
    vector<tuple<int, int, int> > lSourceDatas;
    lSourceDatas.push_back(std::make_tuple(1,2,3));
    lSourceDatas.push_back(std::make_tuple(2,4,5));
    TreeNode* lpSourceTree = Utils::CreateTree(lSourceDatas);
    
    vector<tuple<int, int, int> > lTargetDatas;
    lTargetDatas.push_back(std::make_tuple(2,4,5));
    TreeNode* lpTargetTree = Utils::CreateTree(lTargetDatas);

    Solution S1;
    assert(S1.isBinarySearchTree(lpSourceTree, lpTargetTree) == true);
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
