#include <map>
#include <set>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
const int gcEmptyNode = -1;
struct TreeNode
{
    TreeNode *left;
    char mData;
    TreeNode *right;
    TreeNode(char iData) : mData(iData), right(nullptr), left(nullptr) {}
};

class Utils
{
public:
    static TreeNode * CreateTree(string iPreOrderStr, string iInorderStr);
    static void DeleteTree(TreeNode *ipHead);
};

void Case1()
{
    string lPreOrder = "ABDECF" ;
    string lInOrder = "DBEAFC";
    TreeNode *lpRoot = Utils::CreateTree(lPreOrder, lInOrder);
    Utils::DeleteTree(lpRoot);
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

TreeNode *Utils::CreateTree(string iPreOrderStr, string iInorderStr)
{
    // Stop Condition
    if (iPreOrderStr.length() == 0)
        return nullptr;

    TreeNode *lpNode = new TreeNode(iPreOrderStr[0]);
    size_t lPosInInorder = 0;

    for (lPosInInorder = 0; lPosInInorder < iInorderStr.length(); lPosInInorder++)
    {
        if (iInorderStr[lPosInInorder] == lpNode->mData)
            break;
    }
    size_t lLeftChildCount = lPosInInorder;
    size_t lRightChildCount = iPreOrderStr.length() - lPosInInorder - 1 ;

    if (lLeftChildCount > 0)
        lpNode->left = CreateTree(iPreOrderStr.substr(1, lLeftChildCount),
                                  iInorderStr.substr(0, lLeftChildCount));
    if (lRightChildCount > 0)
        lpNode->right = CreateTree(iPreOrderStr.substr(lPosInInorder + 1, lRightChildCount),
                                   iInorderStr.substr(lPosInInorder + 1, lRightChildCount));
    return lpNode;
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
