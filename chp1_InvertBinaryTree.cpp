#include <iostream>
#include <vector>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int mData; 
    TreeNode* mLeftNode;
    TreeNode* mRightNode;
    TreeNode(int iData): mData(iData),mLeftNode(nullptr),mRightNode(nullptr){}
};

TreeNode* CreateTree(stack<int>& irDataStack)
{
    if(irDataStack.empty())
    {
        return nullptr;
    }    
    cout<<"Begin to Create Node" << endl;
    // Root Node
    TreeNode* lRoot  = new TreeNode(irDataStack.top());
    irDataStack.pop();
    deque<TreeNode*> lNodeQueue;
    lNodeQueue.push_back(lRoot);
    cout<< "\t" << lRoot->mData;
    TreeNode * lCurrentNode = nullptr;
    while(!irDataStack.empty())
    {
        TreeNode* lNode = new TreeNode(irDataStack.top());
        cout<< "\t" << lNode->mData;
        irDataStack.pop();
        if(lCurrentNode == nullptr)
        {
            lCurrentNode = lNodeQueue.front();
            lNodeQueue.pop_front();
            lCurrentNode->mLeftNode = lNode;
        } else if(lCurrentNode != nullptr)
        {
            lCurrentNode->mRightNode = lNode;
            lCurrentNode = nullptr;
        }
        lNodeQueue.push_back(lNode);
    }
    cout<<endl;
    return lRoot;
   
};
void PrintNodeInOrder(TreeNode* ipRoot)
{
    if(ipRoot==nullptr)
        return;
    cout<< ipRoot->mData << "\t" ;
    PrintNodeInOrder(ipRoot->mLeftNode);
    PrintNodeInOrder(ipRoot->mRightNode);
}
void DeleteNode(TreeNode* ipRoot)
{
    if(!ipRoot) return;
    DeleteNode(ipRoot->mLeftNode);
    DeleteNode(ipRoot->mRightNode);
   
    delete ipRoot;
    ipRoot = nullptr;
}
void InvertBinaryTree(TreeNode* ipRoot)
{
    if(!ipRoot)
        return;
    TreeNode* lTmp = ipRoot->mLeftNode;

    ipRoot->mLeftNode = ipRoot->mRightNode;
    ipRoot->mRightNode = lTmp;
    InvertBinaryTree(ipRoot->mLeftNode);
    InvertBinaryTree(ipRoot->mRightNode);
}
int main()
{
    vector<int>lVec{4,7,2,9,6,3,1};
    
    stack<int> lStack;
    for(int i = lVec.size() -1 ; i >=0; i--)
    {
        lStack.push(lVec[i]);
    }
    TreeNode * lTree = CreateTree(lStack);
    cout<<"Pre Order: " << endl;
    cout<<"Before Inverted Tree:"<<endl;
    PrintNodeInOrder(lTree);
    InvertBinaryTree(lTree);
    cout<<"\nAfter Inverted Tree:"<<endl;
    PrintNodeInOrder(lTree);
    DeleteNode(lTree);
  
    return 0;
}