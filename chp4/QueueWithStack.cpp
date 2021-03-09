#include<stack>
using namespace std;
class QueueWithStack
{
public:
    void push(int iData)
    {
        mInputStack.push(iData);
    }
    void pop()
    {
        if(mOutStack.empty())
        {
            while (!mInputStack.empty())
            {
                mOutStack.push(mInputStack.top());
                mInputStack.pop();
            }
        }
        if(!mOutStack.empty())
            mOutStack.pop();
    }
    int top()
    {
        if(mOutStack.empty())
        {
            while (!mInputStack.empty())
            {
                mOutStack.push(mInputStack.top());
                mInputStack.pop();
            }
        }
        if(!mOutStack.empty())
          return mOutStack.top();
    }
private:
    stack<int> mInputStack;
    stack<int> mOutStack;
};
void testAcceptance()
{
    QueueWithStack lQueue; 
    lQueue.push(1);
    lQueue.push(2);
    assert(lQueue.top() == 1);

    lQueue.pop();
    assert(lQueue.top() == 2);
}
int main()
{
    testAcceptance();
    return 0;
}