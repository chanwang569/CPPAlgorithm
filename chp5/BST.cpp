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
    static TreeNode* CreateTree(vector< tuple<int, int, int> > &irData);
    static void DeleteTree(TreeNode *ipHead);
};
class Solution
{
public:
    bool isBinarySearchTree(TreeNode* ipRoot, int min, int max)
    {
        if(ipRoot == nullptr)
        {
            return true;
        }    
        int data = ipRoot->mData;
        bool lbCurrentNode  = data > min && data < max && max > min;
        if(!lbCurrentNode)
            return false; 
        bool lbLeftNode = isBinarySearchTree(ipRoot->left, min, data);
        if(!lbLeftNode)
            return false;
        
        return isBinarySearchTree(ipRoot->right, data, max);
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lTreeDatas;
    lTreeDatas.push_back(std::make_tuple(4,3, 6)) ;
    lTreeDatas.push_back(std::make_tuple(3, 1, 2));
    lTreeDatas.push_back(std::make_tuple(6,5,7));
    TreeNode *lpTree = Utils::CreateTree(lTreeDatas);
    queue<int> lQueue;
    Solution S1;
    bool lbBST = S1.isBinarySearchTree(lpTree, INT_MIN, INT_MAX);
    assert(lbBST == false);
    
    Utils::DeleteTree(lpTree);
}
void Case2()
{
    vector<tuple<int, int, int> > lTreeDatas;
    lTreeDatas.push_back(std::make_tuple(4,2, 6)) ;
    lTreeDatas.push_back(std::make_tuple(2, 1, 3));
    lTreeDatas.push_back(std::make_tuple(6,5,7));
    TreeNode *lpTree = Utils::CreateTree(lTreeDatas);
    queue<int> lQueue;
    Solution S1;
    bool lbBST = S1.isBinarySearchTree(lpTree, INT_MIN, INT_MAX);
    assert(lbBST == true);
    
    Utils::DeleteTree(lpTree);
}
int main()
{
    Case1();
    Case2();
    return 0;
}

TreeNode *Utils::CreateTree(vector< tuple<int, int, int> > &irData)
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
