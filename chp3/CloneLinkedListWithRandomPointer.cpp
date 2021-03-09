#include<vector>
#include<map>
using namespace std;

struct  LinkListNode
{
    LinkListNode* next; 
    LinkListNode* pRandom; 
    int mData;
    LinkListNode(int iData):mData(iData),next(nullptr),pRandom(nullptr){}
};
class  Solution
{
public:
    LinkListNode* DeepCopyLinkList(LinkListNode* ipLinkList)
    {
        map<LinkListNode*, LinkListNode*> lMap;
        LinkListNode* lpNode = ipLinkList;
        LinkListNode lDummy(-1);
        LinkListNode * lNewNode = &lDummy;
        while(lpNode)
        {
            LinkListNode* lTmp = new LinkListNode(lpNode->mData);
            lNewNode->next = lTmp;
            lNewNode = lNewNode->next;
            lMap[lpNode] = lTmp;
            lpNode = lpNode->next;
        }
        for(auto& it : lMap)
        {
            it.second->pRandom = lMap[it.first->pRandom]; 
        }
        return lDummy.next;
    }
private:
    
};
LinkListNode* CreateLinkList(std::map<int, int> & irData)
{
    LinkListNode lDummpy(-1);
    LinkListNode* lpCurrent = &lDummpy;
    map<int, LinkListNode*> lMap; 
    for(auto& it: irData)
    {
        LinkListNode* lTmp = new LinkListNode(it.first);
        lpCurrent->next = lTmp;
        lpCurrent = lpCurrent->next;
        lMap[it.first] = lTmp;
    }
    for(auto& it: irData)
    {
        lMap[it.first]->pRandom = lMap[it.second];
    }
  return lDummpy.next;
    
}
void case_acceptance()
{
 map<int, int> lDataVec;
 lDataVec[1] = 3;
 lDataVec[2] = 1;
 lDataVec[3] = 5;
 lDataVec[4] = 3;
 lDataVec[5] = 2;
 LinkListNode * lList = CreateLinkList(lDataVec);
 Solution S1; 
 LinkListNode* lpResult = S1.DeepCopyLinkList(lList);
}
int main()
{
    case_acceptance();
    return 0;
}