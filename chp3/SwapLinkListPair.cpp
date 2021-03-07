#include "LinkList.h"
#include <iostream>
LinkListNode* SwapPairs(LinkListNode *iHead)
{
    if (iHead == nullptr || iHead->next == nullptr)
        return iHead;

    LinkListNode lDummpy(-1);
    lDummpy.next = iHead;
    LinkListNode *lpPre = &lDummpy;
    LinkListNode *lpCurrent = iHead, *lpNext = iHead->next;
    while (lpCurrent && lpCurrent->next)
    {
        lpNext = lpCurrent->next;
        lpPre->next = lpNext;
        lpCurrent->next = lpNext->next;
        lpNext->next = lpCurrent;

        //Move forward
        lpPre = lpCurrent;
        lpCurrent = lpCurrent->next;
        
    }
    return lDummpy.next;
}

void case_acceptance()
{
    vector<int> lVec = {10, 20, 30, 40, 50, 60};
    LinkListNode *lHead = Utils::CreateLinkList(lVec);
    Utils::PrintLinkList(lHead);
    LinkListNode* lpResult = SwapPairs(lHead);
    Utils::PrintLinkList(lpResult);
   
    Utils::deleteLinkList(lpResult);
}

int main()
{
    case_acceptance();
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