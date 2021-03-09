#include<stack>
using namespace std;
void sort(stack<int>& irInput)
{
    stack<int> output;
    while (!irInput.empty())
    {
        int value  =irInput.top();
        irInput.pop();
        while (!output.empty() && output.top() > value )
        {
            irInput.push(output.top());
            output.pop();
        }
        output.push(value);
    }
    irInput.swap(output);
}
void testAcceptance()
{
    stack<int> lStack;
    lStack.push(2);
    lStack.push(1);
    lStack.push(3);
    sort(lStack);
    assert(lStack.top() == 3 );
    lStack.pop();
     assert(lStack.top() == 2 );
    lStack.pop();
    assert(lStack.top() == 1 );
    lStack.pop();
    assert(lStack.empty());
}
int main()
{
    testAcceptance();
    return 0;
}