#include <map>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
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
    void PrintBSTRange(TreeNode *ipRoot, int low, int high)
    {
        if (ipRoot == nullptr)
            return;
        if (ipRoot->mData >= low && ipRoot->mData <= high)
        {
            cout<< ipRoot->mData << "\t" ; 
        }
        if(ipRoot->mData > low && ipRoot->left)
        {
            PrintBSTRange(ipRoot->left, low, high);
        }
        if(ipRoot->mData < high && ipRoot->right)
        {
            PrintBSTRange(ipRoot->right, low, high);
        }
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lTreeDatas;
    lTreeDatas.push_back(std::make_tuple(20, 8, 22));
    lTreeDatas.push_back(std::make_tuple(8, 4, 12));
    lTreeDatas.push_back(std::make_tuple(12, 10, 14));
    TreeNode *lpSourceTree = Utils::CreateTree(lTreeDatas);
    Solution S1;
    S1.PrintBSTRange(lpSourceTree, 10, 22);
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
