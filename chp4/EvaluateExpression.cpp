#include<stack>
#include<string>
using namespace std;

int EvaluateExpression(string input)
{
    stack<int> lStack; 
    for(int i = 0; i < input.length(); i++)
    {
       if(std::isdigit(input[i]))
        {
            lStack.push(input[i] - '0');
        }else
        {
            int lOp1 = lStack.top();
            lStack.pop();
            int lOp2 = lStack.top();
            lStack.pop();
            switch (input[i])
            {
            case  '+':
                lStack.push(lOp1 + lOp2);
                break;
            case '-':
                lStack.push(lOp2 - lOp1);
                break;
            case '*' :
                lStack.push(lOp2 * lOp1);
            default:
                break;
            }
        }
    }
    return lStack.top();
}
void testAcceptance()
{
    string lStr = "45+72-*";
    assert(EvaluateExpression(lStr) ==45);
}
int main()
{
    testAcceptance();
    return 0;
}