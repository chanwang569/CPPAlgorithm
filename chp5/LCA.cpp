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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int iData ) : mData(iData),right(nullptr), left(nullptr) {
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
// The idea is calculate whether A and B is left or right tree of the Tree.
// A & B on left tree. LCA is on the left tree. 
// A & B on the right tree. LCA is on the right tree. 
// A & B on different sub tee. Root is the result. 
// This way, hCovers will be called multipule times for each node, which is not efficient. 
   TreeNode* LCA(TreeNode* ipRoot,TreeNode* ipA, TreeNode* ipB)
    {
        if(!ipRoot) 
            return nullptr; 
       // A and B in the left tree
       if(hCovers(ipRoot->left, ipA) && hCovers(ipRoot->left, ipB))
       {
           return LCA(ipRoot->left, ipA, ipB);
       }
       // A and B in the right tree
       if(hCovers(ipRoot->right, ipA) && hCovers(ipRoot->right,ipB))
       {
           return LCA(ipRoot->right, ipA, ipB);
       }
       // A and B not in the same sub tree. Current Node is the result. 
       return ipRoot;
    }

    TreeNode * LCA2(TreeNode* ipRoot, TreeNode* ipA, TreeNode* ipB)
    {
        if(ipRoot == nullptr || ipRoot == ipA || ipRoot == ipB)
            return ipRoot;// return nullptr means A and B share no root. 
        TreeNode* lLeftChild = LCA2(ipRoot->left, ipA, ipB);
        TreeNode* lRightChild = LCA2(ipRoot->right, ipA, ipB);
        if(lLeftChild != nullptr && lRightChild != nullptr) 
            return ipRoot;// A & B belongs to different sub tree. 
            
        return lLeftChild != nullptr? lLeftChild : lRightChild; // A and B on the same subtree
    }
private:
    bool hCovers(TreeNode* ipRoot, TreeNode * ipNode)
    {
        if(ipRoot == nullptr)
            return false;
        if(ipRoot == ipNode)
            return true;

        return hCovers(ipRoot->left, ipNode) || hCovers(ipRoot->right, ipNode);
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lTreeDatas;
    lTreeDatas.push_back(std::make_tuple(1, 2, 3)) ;
    lTreeDatas.push_back(std::make_tuple(2, 4, 5));
    lTreeDatas.push_back(std::make_tuple(4, 6, 7));
    lTreeDatas.push_back(std::make_tuple(5, 8, 9));
    lTreeDatas.push_back(std::make_tuple(6, 10, 11));
    map<int, TreeNode*> lDataNodeMap;
    TreeNode *lpTree = Utils::CreateTree(lTreeDatas, lDataNodeMap);
    Solution S1;
    
    assert(S1.LCA(lpTree,lDataNodeMap[2], lDataNodeMap[3])->mData== 1);
    assert(S1.LCA(lpTree,lDataNodeMap[4], lDataNodeMap[9])->mData== 2);
    assert(S1.LCA2(lpTree,lDataNodeMap[2], lDataNodeMap[3])->mData== 1);
    assert(S1.LCA2(lpTree,lDataNodeMap[4], lDataNodeMap[9])->mData== 2);
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
