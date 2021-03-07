#include "LinkList.h"
#include<iostream>
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
    cout<<"Begin to print LinkList:\t";
    while (lNode)
    {
        cout<< lNode->mData <<"\t" <<"->";
        lNode = lNode->next;
    }
    cout<<endl;
    cout<<"Finished to print LinkList:\t";
}

LinkListNode* RemoveDuplicateNode(LinkListNode* iHead)
{
    LinkListNode* lCurrent  = iHead;
    while (lCurrent)
    {
        if(lCurrent->next && lCurrent->next->mData == lCurrent->mData)
        {
            LinkListNode * tmp = lCurrent->next;
            lCurrent->next = tmp->next;
            delete tmp;
        }
        else
        {
            lCurrent = lCurrent->next;
        }
    }
    return iHead;
}

void case_RemoveDuplicateNode_acceptance()
{
    vector<int> lVec = {1,1,2,2,2,3};
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    RemoveDuplicateNode(lHead);
    Utils::PrintLinkList(lHead);
    Utils::deleteLinkList(lHead);
}
LinkListNode* RemoveDuplicateNodeII(LinkListNode* iHead)
{
    LinkListNode lDummyNode(0);
    lDummyNode.next = iHead;
    LinkListNode* lNode = &lDummyNode;
    while (lNode->next && lNode->next->next)
    {
        if(lNode->next->mData == lNode->next->next->mData)
        {
            int data = lNode->next->mData;
            while (lNode->next && lNode->next->mData == data)
            {
                LinkListNode* lTmp = lNode->next;
                lNode->next = lNode->next->next;
                delete lTmp;
            }
        }else
        {
            lNode = lNode->next;
        }
    }

    return lDummyNode.next;
}

void case_RemoveDuplicateNodeII_acceptance()
{
    vector<int> lVec = {1,1,2,2,2,3};
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    LinkListNode* lResult = RemoveDuplicateNodeII(lHead);
    Utils::PrintLinkList(lResult);
     Utils::deleteLinkList(lHead);
}
LinkListNode* Partition(LinkListNode* iHead, int iValue)
{
    LinkListNode lLeftNode(-1);
    LinkListNode* lpLeft = &lLeftNode;
    LinkListNode lRightNode(-1);
    LinkListNode* lpRight = &lRightNode;
    LinkListNode lMiddelNode(-1);
    LinkListNode* lpMiddleNode = &lMiddelNode;
    LinkListNode* lNode = iHead;
    while(lNode)
    {
        if(lNode->mData < iValue)
        {
            lpLeft->next = lNode;
            lpLeft = lpLeft->next;
        }
        else if(lNode->mData == iValue)
        {
            lpMiddleNode->next = lNode;
            lpMiddleNode = lpMiddleNode->next;
        }
        else
        {
            lpRight->next = lNode;
            lpRight = lpRight->next;
        }
        lNode = lNode->next;
    }
    lpRight->next = nullptr;
    lpMiddleNode->next = lRightNode.next;
    lpLeft->next = lMiddelNode.next;
    return lLeftNode.next;
}

void case_Partition_acceptance()
{
    vector<int> lVec = {4, 5, 1, 3, 0,2};
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    LinkListNode* lResult = Partition(lHead, 3);
    Utils::PrintLinkList(lResult);
     Utils::deleteLinkList(lHead);
}
LinkListNode* GetMiddlePoint(LinkListNode* iHead)
{
    LinkListNode* lpSlow = iHead;
    LinkListNode* lpFast = lpSlow;
    while(lpFast->next && lpFast->next->next && lpSlow->next)
    {
        lpFast = lpFast->next->next;
        lpSlow = lpSlow->next;
    }
    return lpSlow;
}

LinkListNode* case_MiddlePoint_acceptance()
{
    vector<int> lVec = {4, 5, 1, 3, 0};
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    LinkListNode* lResult = GetMiddlePoint(lHead);

    assert(lResult->mData ==1);
     Utils::deleteLinkList(lHead);
}

LinkListNode* LastKthNode(LinkListNode* iHead, int k)
{
    if(k <= 0 )
        return nullptr;
    LinkListNode* lFast = iHead;
    int i = 0; 
    while(i<k & lFast!=nullptr)
    {
        lFast = lFast->next;
        i++;
    }
    if(lFast == nullptr)
        return nullptr;

    LinkListNode* lSlow = iHead;
    while(lFast != nullptr)
    {
        lSlow = lSlow->next;
        lFast = lFast->next;
    }
    return lSlow;
}

LinkListNode* case_LastKthNode_acceptance()
{
    vector<int> lVec = {4, 5, 1, 3, 0};
    LinkListNode* lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    LinkListNode* lResult = LastKthNode(lHead , 2);
    assert(lResult->mData ==3);

    LinkListNode* lResult2 = LastKthNode(lHead , 0);
    assert(lResult2 == nullptr);

    LinkListNode* lResult3 = LastKthNode(lHead , 6);
    assert(lResult3 == nullptr);
    Utils::deleteLinkList(lHead);
}

bool HasCircle(LinkListNode* iHead )
{
    LinkListNode* lpSlow = iHead;
    LinkListNode* lpFast = iHead;
    while( lpFast->next && lpFast->next->next)
    {
        lpSlow = lpSlow->next;
        lpFast = lpFast->next->next;
        if(lpFast == lpSlow)
        {
            return true;
        }
        
    }

    return false;
}
LinkListNode* GetCircleEntry(LinkListNode* iHead)
{
    LinkListNode* lpSlow = iHead;
    LinkListNode* lpFast = iHead;
    while( lpFast->next && lpFast->next->next)
    {
        lpSlow = lpSlow->next;
        lpFast = lpFast->next->next;
        if(lpFast == lpSlow)
        {
            break;
        }
    }

    if(lpFast == lpSlow)
    {
        lpFast = iHead;
        while (lpFast != lpSlow)
        {
            lpFast = lpFast->next;
            lpSlow = lpSlow->next;
        }
        return lpFast;
    }

    return nullptr;
}
void case_hasCircle_acceptance()
{
    vector<int> lVec = {1,2,3,4,5,6,7,8};
    LinkListNode* lHead = Utils::CreateLinkList(lVec,4);
    bool lResult = HasCircle(lHead);
    assert(lResult == true);
    LinkListNode* lResult2 = GetCircleEntry(lHead);
    assert(lResult2->mData == 4);
    // delete Link List. 
    LinkListNode * lpNode  = lHead;
    int i = 0;
    while(lpNode)
    {
        if(lResult2 != nullptr && lpNode == lResult2)
        {
            if(i == 1) 
            {
                break; 
            }else 
            { 
                i++;
            }
        }
        LinkListNode* lNext = lpNode->next;
        delete lpNode;
        lpNode = lNext;
    }
     
}

int main()
{
    //case_RemoveDuplicateNode_acceptance();
    //case_RemoveDuplicateNodeII_acceptance();
    //case_Partition_acceptance();
    //case_MiddlePoint_acceptance();
    //case_LastKthNode_acceptance();
    case_hasCircle_acceptance();
    return 0;
}