#include "LinkList.h"
#include <iostream>
LinkListNode *MergeKSortedLists(LinkListNode *ipFirst, LinkListNode *ipSecond)
{
    int lFromLow = 0;
    LinkListNode *p1 = ipFirst, *p2 = ipSecond;
    LinkListNode lDummy(-1);
    LinkListNode *lResult = &lDummy;
    while (p1 != nullptr || p2 != nullptr)
    {
        int value = lFromLow + (p1 != nullptr ? p1->mData : 0) + (p2 != nullptr ? p2->mData : 0);
        lFromLow = value / 10;
        LinkListNode *lpNewNode = new LinkListNode(value % 10);
        lResult->next = lpNewNode;
        lResult = lResult->next;
        if (p1)
        {
            p1 = p1->next;
        }
        if (p2)
        {
            p2 = p2->next;
        }
    }
    if(lFromLow > 0 )
    {
         LinkListNode *lpNewNode = new LinkListNode(lFromLow);
        lResult->next = lpNewNode;
    }
    return lDummy.next;
}

void case_acceptance()
{
    vector<int> lVec = {6, 5, 3 };
    LinkListNode *lpList1 = Utils::CreateLinkList(lVec);
    lVec.clear();
    lVec = {4,5, 9};
    LinkListNode *lpList2 = Utils::CreateLinkList(lVec);
    LinkListNode* lpResult = MergeKSortedLists(lpList1, lpList2);

    Utils::PrintLinkList(lpResult);

    Utils::deleteLinkList(lpList1);
    Utils::deleteLinkList(lpList2);
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