#include "LinkList.h"
#include <iostream>
#include <vector>
#include <queue>
LinkListNode *MergeKSortedLists(vector<LinkListNode *> &irLists)
{
    auto cmp = [](LinkListNode *left, LinkListNode *right) { return left->mData > right->mData; };
    std::priority_queue<LinkListNode *, std::vector<LinkListNode *>, decltype(cmp)> lHeap(cmp);

    for (auto it : irLists)
    {
        lHeap.push(it);
    }
    LinkListNode lDummy(-1);
    LinkListNode *lpNode = &lDummy;
    while (!lHeap.empty())
    {
        lpNode->next = lHeap.top();
        lpNode = lpNode->next;
        lHeap.pop();
        if (lpNode->next)
        {
            lHeap.push(lpNode->next);
        }
    }
    lpNode->next = nullptr;
    
    return lDummy.next;
}

void case_acceptance()
{
    vector<LinkListNode *> lListVec;
    vector<int> lVec = {1, 2, 6, 8, 15};

    lListVec.push_back(Utils::CreateLinkList(lVec));
    lVec.clear();
    lVec = {3, 4, 5, 12, 14};
    lListVec.push_back(Utils::CreateLinkList(lVec));
    lVec.clear();
    lVec = {7, 9, 10, 11, 13};
    lListVec.push_back(Utils::CreateLinkList(lVec));

    LinkListNode *lpResult = MergeKSortedLists(lListVec);
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