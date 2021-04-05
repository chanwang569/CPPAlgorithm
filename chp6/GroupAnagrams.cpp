#include<cstring>
#include<vector>
#include<map>
#include<iostream>

using namespace std;
class solution
{
private:
    /* data */
public:
    solution(/* args */);
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > lHashMap;
        for(size_t i = 0; i < strs.size(); i++)
        {
            string lTmp = strs[i];
            sort(lTmp.begin(), lTmp.end());
            lHashMap[lTmp].push_back(strs[i]);
        }
        vector<vector<string> > lResult; 
        for(auto it = lHashMap.begin(); it != lHashMap.end(); it++)
        {
            lResult.push_back(it->second);
        }
        return lResult;
    }
    ~solution();
};

solution::solution(/* args */)
{
}

solution::~solution()
{
}

int main()
{
   vector<string>  strs = {"eat","tea","tan","ate","nat","bat"};
   solution s1;
   vector<vector<string> > lResult = s1.groupAnagrams(strs);
   for(auto its: lResult)
   {
       for(auto it : its)
       {
           cout<< it << "\t";
       }
       cout << endl;
   }

}
