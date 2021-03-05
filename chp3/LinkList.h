#include<vector>
using namespace std;
struct  LinkListNode
{
    LinkListNode* next; 
    int mData;
    LinkListNode(int iData):mData(iData),next(nullptr){}
};
namespace Utils
{
    LinkListNode* CreateLinkList(vector<int>& irDataVecint, int iCiclePos = -1);
    void deleteLinkList(LinkListNode* iHead);
    void deleteLinkHasCircle(LinkListNode* iHead);
    void PrintLinkList(LinkListNode* iHead); 
}
