#include<stack>
using namespace std;

class StackWithMax 
{
public:
    void Push(int value);
    void Pop();
    int Top();
    int Max();
private:
    stack<int> mValueStack; 
    stack<int> mMaxStack; 
};
void StackWithMax::Push(int value)
{
    if( mMaxStack.empty()||value >= mMaxStack.top())
    {
        mMaxStack.push(value);
    }
    mValueStack.push(value);
}
void StackWithMax::Pop()
{
    if(mValueStack.empty())
        return; 
    if(mValueStack.top() == mMaxStack.top())
    {
        mMaxStack.pop();
    }
    mValueStack.pop();
}
int StackWithMax::Top()
{
    return mValueStack.top();
}
int StackWithMax::Max()
{
    return mMaxStack.top(); 
}
void testAcceptance()
{
    StackWithMax lStack;
    lStack.Push(1);
    lStack.Push(3);
    lStack.Push(2);
    assert(lStack.Max() ==3);
    lStack.Pop();
    assert(lStack.Max() ==3);
    lStack.Pop();
    assert(lStack.Max() ==1);
}
int main()
{
    testAcceptance();
    return 0;
}