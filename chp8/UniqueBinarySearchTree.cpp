
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 void DeleteTree(TreeNode *ipHead)
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
 class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       return hGenerateTree(1, n);
    }
private:
    vector<TreeNode*> hGenerateTree(int iBegin, int iEnd)
    {
        if(iBegin > iEnd)
        {   
            vector<TreeNode*> lResult; 
            lResult.push_back(nullptr);
            return lResult;
        }
        vector<TreeNode*> lResult; 
        for(int mid = iBegin; mid <= iEnd; mid++)
        {
            vector<TreeNode*> lLeft = hGenerateTree(iBegin, mid - 1);
            vector<TreeNode*> lRight = hGenerateTree(mid + 1, iEnd);
            

            for(int i = 0 ; i < lLeft.size(); i++)
            {
                for(int j = 0 ; j < lRight.size();j++)
                {
                    TreeNode * lRoot = new TreeNode(mid);
                    lRoot->left = lLeft[i];
                    lRoot->right = lRight[j];
                    lResult.push_back(lRoot);
                }
            }
        }
        return lResult;
    }   
};

int main()
{
    Solution S1; 
    vector<TreeNode*> lResult = S1.generateTrees( 3 );
    assert(lResult.size() ==5);
    for(auto& it: lResult)
    {
        DeleteTree(it);
    }
    return 0 ;
}