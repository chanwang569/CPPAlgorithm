#include <map>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
const int gcEmptyNode = -1;
struct TreeNode
{
    int mData;
    TreeNode *parent; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int iData , TreeNode* ipParent = nullptr) : mData(iData),right(nullptr), left(nullptr) {
        parent = ipParent;
    }
};

 class Utils
{
public:
    static TreeNode* CreateTree(vector< tuple<int, int, int> > &irData, map<int, TreeNode*>& irDataNodeMap);
    static void DeleteTree(TreeNode *ipHead);
};
class Solution
{
public:
   TreeNode* FindNextNodeInBSTR(TreeNode* ipNode)
    {
        if(ipNode == nullptr)
            return nullptr;
        if(ipNode->right )
        {
            TreeNode* lpMostLeftNode  = ipNode->right;
            while(lpMostLeftNode->left)
            {
                lpMostLeftNode = lpMostLeftNode->left;
            }
            return lpMostLeftNode;
        }else 
        {
            TreeNode* lpParent = ipNode->parent;
            TreeNode* lCurrent = ipNode;
            // Current Node is the left node. Return parent.
            if(lpParent->left == ipNode) 
                return lpParent;
            // Current Node is a right node. We find parent with right most parent
            while(lpParent  != nullptr && lpParent->right == ipNode)
            {
                lCurrent = lpParent;
                lpParent = lpParent->parent;
            }     
            return lpParent == nullptr ? nullptr : lpParent->parent;
        }
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lTreeDatas;
    lTreeDatas.push_back(std::make_tuple(20, 8, 22)) ;
    lTreeDatas.push_back(std::make_tuple(8, 4, 12));
    lTreeDatas.push_back(std::make_tuple(12, 10, 14));
    map<int, TreeNode*> lDataNodeMap;
    TreeNode *lpTree = Utils::CreateTree(lTreeDatas, lDataNodeMap);
    Solution S1;
    assert(S1.FindNextNodeInBSTR(lDataNodeMap[4])->mData == 8);
    assert(S1.FindNextNodeInBSTR(lDataNodeMap[8])->mData == 10);
    assert(S1.FindNextNodeInBSTR(lDataNodeMap[14])->mData == 20);
    assert(S1.FindNextNodeInBSTR(lDataNodeMap[22])== nullptr);

    Utils::DeleteTree(lpTree);
}
void Case2()
{
     
}
int main()
{
    Case1();
    Case2();
    return 0;
}

TreeNode *Utils::CreateTree(vector< tuple<int, int, int> > &irData , map<int, TreeNode*>& irDataNodeMap)
{
    TreeNode *lpHead = nullptr;
    for (auto &it : irData)
    {
        auto [data, left, right] = it;
        TreeNode *lpNode = nullptr;

        if (irDataNodeMap.find(data) == irDataNodeMap.end())
        {
            lpNode = new TreeNode(data);
            irDataNodeMap[data] = lpNode;
            if (lpHead == nullptr)
                lpHead = lpNode;
        }
        else
        {
            lpNode = irDataNodeMap[data];
        }
        if (left != gcEmptyNode)
        {
            if (irDataNodeMap.find(left) != irDataNodeMap.end())
            {
                lpNode->left = irDataNodeMap[left];
            }
            else
            {
                TreeNode *tmp = new TreeNode(left);
                lpNode->left = tmp;
                irDataNodeMap[left] = tmp;
            }
            lpNode->left->parent = lpNode;
        }
        if (right != gcEmptyNode)
        {
            if (irDataNodeMap.find(right) != irDataNodeMap.end())
            {
                lpNode->right = irDataNodeMap[right];
            }
            else
            {
                TreeNode *tmp = new TreeNode(right);
                lpNode->right = tmp;
                irDataNodeMap[right] = tmp;
            }
            lpNode->right->parent = lpNode;
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
