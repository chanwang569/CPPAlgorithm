#include<stack>
#include <string>
#include <stack>
using namespace std;

bool isCharMarching(char iSource, char iTarget)
{
    bool lResult = (iSource == '[' && iTarget == ']') || (iSource == '{' && iTarget == '}')
            || (iSource == '(' && iTarget == ')');
    return lResult;  
}
bool isValidateParenthesis(string irStr)
{
    stack<char> lStack;
    for(size_t i = 0; i < irStr.length();i++)
    {
        if(irStr[i]  == '(' || irStr[i] =='{' || irStr[i] == '[')
        {
            lStack.push(irStr[i]);
        }else
        { 
            if(!lStack.empty() && isCharMarching(lStack.top(), irStr[i]))
             {
                lStack.pop();
             }
             else{
                 return false;
             }   
        }
    }
    return lStack.empty();
}
void testAcceptance()
{
    assert(isValidateParenthesis("{[()]}") == true);
    assert(isValidateParenthesis("{[") == false);
}
int main()
{
    testAcceptance();
    return 0;
}