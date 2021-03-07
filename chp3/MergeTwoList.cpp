#include "LinkList.h"
#include <iostream>
LinkListNode *MergeKSortedLists(LinkListNode *ipFirst, LinkListNode *ipSecond)
{
    LinkListNode *p1 = ipFirst, *p2 = ipSecond;
    LinkListNode lDummy(-1);
    LinkListNode *lpCurent = &lDummy;
    while (p1 != nullptr && p2 != nullptr)
    {
       if(p1->mData < p2->mData)
       {
           lpCurent->next = p1;
           p1 = p1->next;
       }else
       {
           lpCurent->next = p2;
           p2 = p2->next;
       }
       lpCurent = lpCurent->next;
    }
    lpCurent->next = p1 != nullptr? p1 :p2;
   
    return lDummy.next;
}

void case_acceptance()
{
    vector<int> lVec = {1, 2, 3 , 6, 7, 8,  11 };
    LinkListNode *lpList1 = Utils::CreateLinkList(lVec);
    lVec.clear();
    lVec = {4,5, 9};
    LinkListNode *lpList2 = Utils::CreateLinkList(lVec);
    LinkListNode* lpResult = MergeKSortedLists(lpList1, lpList2);

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