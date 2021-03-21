#include <map>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include<iostream>
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
   void PrintBSTRange(TreeNode* ipRoot)
   {
       stack<TreeNode*> lCurrentLevelStack;
       stack<TreeNode*> lNextLevelStack;
        bool lReverseOrder = true; 
        lCurrentLevelStack.push(ipRoot);
        while (!lCurrentLevelStack.empty())
        {
            TreeNode* lpNode = lCurrentLevelStack.top();
            if(!lpNode) continue;
            cout<< lpNode->mData << "\t";
            if(!lReverseOrder)
            {
                if(lpNode->right)
                    lNextLevelStack.push(lpNode->right);
                if(lpNode->left)
                    lNextLevelStack.push(lpNode->left);
            }else
            {
                if(lpNode->left)
                    lNextLevelStack.push(lpNode->left);
                if(lpNode->right)
                    lNextLevelStack.push(lpNode->right);
            }

            lCurrentLevelStack.pop();
            if(lCurrentLevelStack.empty())
            {   
                cout<< endl;
                lReverseOrder = !lReverseOrder;   
                swap(lCurrentLevelStack, lNextLevelStack);
            }
        }
        
   }
};

void Case1()
{
    vector<tuple<int, int, int> > lSourceDatas;
    lSourceDatas.push_back(std::make_tuple(1,2,3));
    lSourceDatas.push_back(std::make_tuple(2,4,5));
     lSourceDatas.push_back(std::make_tuple(3, 6,7));
    TreeNode* lpSourceTree = Utils::CreateTree(lSourceDatas);
    Solution S1;
    S1.PrintBSTRange(lpSourceTree);
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
