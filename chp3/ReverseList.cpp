#include"LinkList.h"
#include<iostream>
void  ReverseLinkList(LinkListNode*& iHead )
{
   LinkListNode* lPre = nullptr;
   LinkListNode* lCurrent = iHead;
   while(lCurrent)
   {
       LinkListNode* lNext = lCurrent->next;
       lCurrent->next = lPre;
       lPre = lCurrent;
       lCurrent = lNext;
   }
   iHead = lPre;
}
LinkListNode* ReverseListRecursively(LinkListNode* iHead)
{
    if(iHead == nullptr || iHead->next == nullptr)
        return iHead;
    LinkListNode* lNewNode  = ReverseListRecursively(iHead->next);
    // question? Why the iHead->next is the tail of the link list? 
    // Because it is never changed! Always point to the tail in the "reversed 
    iHead->next->next = iHead;
    iHead->next = nullptr;
    return lNewNode;
}

void case_RotateLinkListWithPosition_acceptance()
{
    vector<int> lVec = {10, 20, 30, 40, 50,60 };
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    ReverseLinkList(lHead);
    Utils::PrintLinkList(lHead);
    LinkListNode* lResult = ReverseListRecursively(lHead);
    Utils::PrintLinkList(lResult);
    Utils::deleteLinkList(lHead);
    
}
void case_ReverserListRecurision_acceptance()
{
    vector<int> lVec = {10, 20, 30, 40, 50,60 };
    //vector<int> lVec = {10, 20 };
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
 
    LinkListNode* lResult = ReverseListRecursively(lHead);
    Utils::PrintLinkList(lResult);
    Utils::deleteLinkList(lHead);
    
}
int main()
{
    //case_RotateLinkListWithPosition_acceptance();
    case_ReverserListRecurision_acceptance();
    return 0;
}

LinkListNode* Utils::CreateLinkList(vector<int>& irDataVec, int iCiclePos)
{
    LinkListNode* head = nullptr;
    LinkListNode*  lPrevious = nullptr;
    LinkListNode* lCircleEntry = nullptr;
    LinkListNode* lLastNode = nullptr;
    for(size_t i = 0 ; i < irDataVec.size(); i++)
    {
        LinkListNode* lpNode = new LinkListNode(irDataVec[i]);
        if(lpNode->mData == iCiclePos)
            lCircleEntry = lpNode;
        if(lPrevious)
        {
            lPrevious->next = lpNode;
            lPrevious = lPrevious->next;
            if(i == irDataVec.size() -1)
            {
                lpNode->next = lCircleEntry;
            }   
        }
        else
        {
            lPrevious = lpNode;
            head = lpNode;
        }
        
    }


    return head;
}

void Utils::deleteLinkList(LinkListNode* iHead)
{
    LinkListNode* lCurrent = iHead;
    while (lCurrent)
    {
        LinkListNode* lNext = lCurrent->next;
        delete lCurrent;
        lCurrent = lNext;
    }  
}

void Utils::PrintLinkList(LinkListNode* iHead)
{
    LinkListNode* lNode  = iHead;
    cout<<"Begin to print LinkList:\n";
    while (lNode)
    {
        cout<< lNode->mData;
        if(lNode->next)
            cout << "->";
        lNode = lNode->next;
    }
    cout<<endl;
    cout<<"Finished to print LinkList:\n";
}