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
    vector< vector<int> > GetPathSum(TreeNode* ipRoot, int sum)
    {
        vector<int> lPath;
        vector<vector<int> > lResult;
        hGetPathSum(ipRoot, sum, lPath, lResult);
        return lResult;
    }
private:
// iExistingPath is pass by value. we know this is not efficient. 
// We use it for avoiding unecessary side-effor of using reference. 
    void hGetPathSum(TreeNode* ipRoot, int sum, vector<int> iExistingPath, vector<vector<int> >& irResult)
    {
        if(!ipRoot)
            return; 
        iExistingPath.push_back(ipRoot->mData);
        if(ipRoot->mData == sum)
            irResult.push_back(iExistingPath);
        hGetPathSum(ipRoot->left, sum - ipRoot->mData, iExistingPath, irResult);
         hGetPathSum(ipRoot->right, sum - ipRoot->mData, iExistingPath, irResult);
    }
};

void Case1()
{
    vector<tuple<int, int, int> > lSoureDatas;
    lSoureDatas.push_back(std::make_tuple(1,2,3));
    TreeNode* lpSourceTree = Utils::CreateTree(lSoureDatas);

    Solution S1;
    auto result =  S1.GetPathSum(lpSourceTree,3); 
    assert(result.size() == 1);
}
void Case2()
{
   vector<tuple<int, int, int> > lSoureDatas;
    lSoureDatas.push_back(std::make_tuple(3,4,2));
    lSoureDatas.push_back(std::make_tuple(4,5,1));
    lSoureDatas.push_back(std::make_tuple(2,6,7));
    TreeNode* lpSourceTree = Utils::CreateTree(lSoureDatas);

    Solution S1;
    auto result =  S1.GetPathSum(lpSourceTree,12); 
    assert(result.size() == 2);
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
