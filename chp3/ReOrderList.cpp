#include "LinkList.h"
#include <iostream>
using namespace Utils;
class Solution
{
public:
    void ReOrderList(LinkListNode* ipHead)
    {
        if(ipHead == nullptr || ipHead->next == nullptr)
            return; 
        LinkListNode* lpMiddle = hFindMiddle(ipHead);
        LinkListNode* lpBeginOfReverse = lpMiddle->next;
        hReverseLinkList(lpBeginOfReverse);
        lpMiddle->next = nullptr;
        hMergeList(ipHead, lpBeginOfReverse);
    }
private:
    LinkListNode* hFindMiddle(LinkListNode* ipHead)
    {
        if(ipHead == nullptr && ipHead->next ==nullptr)
            return ipHead;
        LinkListNode* lpSlow = ipHead;
        LinkListNode* lpFast = ipHead->next;
        while (lpFast != nullptr && lpFast->next != nullptr)
        {
            lpFast = lpFast->next->next;
            lpSlow = lpSlow->next;
        }
        return lpSlow;
    };

    void hReverseLinkList(LinkListNode *&iHead)
    {
        LinkListNode *lPre = nullptr;
        LinkListNode *lCurrent = iHead;
        while (lCurrent)
        {
            LinkListNode *lNext = lCurrent->next;
            lCurrent->next = lPre;
            lPre = lCurrent;
            lCurrent = lNext;
        }
        iHead = lPre;
    }
    LinkListNode* hMergeList(LinkListNode* ipFirst, LinkListNode* ipSecond)
    {
        LinkListNode lDummpy(-1);
        LinkListNode* lpNext = &lDummpy;
        while (ipFirst && ipSecond)
        {
            // Add the first node
            lpNext->next = ipFirst;
            lpNext = lpNext->next;
            ipFirst = ipFirst->next;
            
            // Add the second node
            lpNext->next = ipSecond;
            lpNext = lpNext->next;
            ipSecond = ipSecond->next;
        }
        lpNext->next = ipFirst !=nullptr? ipFirst : nullptr;
        
        return lDummpy.next;
    }
};


void case_acceptance()
{
    Solution S1;
    vector<int> lVec = {1,2,3};
    LinkListNode *lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    S1.ReOrderList(lHead);
    Utils::PrintLinkList(lHead);
    Utils::deleteLinkList(lHead);
}
void case_acceptance2()
{
    Solution S1;
    vector<int> lVec = {1,2,3,4};
    LinkListNode *lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    S1.ReOrderList(lHead);
    Utils::PrintLinkList(lHead);
    Utils::deleteLinkList(lHead);
}

int main()
{
    case_acceptance();
    case_acceptance2();
    return 0;
}

LinkListNode *Utils::CreateLinkList(vector<int> &irDataVec, int iCiclePos)
{
    LinkListNode *head = nullptr;
    LinkListNode *lPrevious = nullptr;
    LinkListNode *lCircleEntry = nullptr;
    LinkListNode *lLastNode = nullptr;
    for (size_t i = 0; i < irDataVec.size(); i++)
    {
        LinkListNode *lpNode = new LinkListNode(irDataVec[i]);
        if (lpNode->mData == iCiclePos)
            lCircleEntry = lpNode;
        if (lPrevious)
        {
            lPrevious->next = lpNode;
            lPrevious = lPrevious->next;
            if (i == irDataVec.size() - 1)
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

void Utils::deleteLinkList(LinkListNode *iHead)
{
    LinkListNode *lCurrent = iHead;
    while (lCurrent)
    {
        LinkListNode *lNext = lCurrent->next;
        delete lCurrent;
        lCurrent = lNext;
    }
}

void Utils::PrintLinkList(LinkListNode *iHead)
{
    LinkListNode *lNode = iHead;
    cout << "Begin to print LinkList:\n";
    while (lNode)
    {
        cout << lNode->mData;
        if (lNode->next)
            cout << "->";
        lNode = lNode->next;
    }
    cout << endl;
    cout << "Finished to print LinkList:\n";
}