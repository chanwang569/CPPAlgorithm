#include<vector>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lDPLeftLowest(height.size());
        int lH = 0;
        for(int i = 0 ; i < height.size(); i++)
        {
            lDPLeftLowest[i] = lH;
            if(height[i] > lH)
                lH = height[i];
        }
        int rH = 0;
        int total = 0 ;
        for(int j = height.size() -1; j >=0; j--)
        {
            int top = min(rH, lDPLeftLowest[j]);
            if(top > height[j])
                total += top - height[j];
            if( height[j] > rH)
                rH = height[j];
        }
        return total;
    }
};
void case0()
{
    vector<int> lHeights = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution S1;
    auto result = S1.trap(lHeights);
    assert(result ==6);
}
int main()
{
    case0();
    return 0;
}