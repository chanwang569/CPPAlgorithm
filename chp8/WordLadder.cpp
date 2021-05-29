#include <string>
#include <queue>
#include<algorithm>
#include<map>
// https://leetcode-cn.com/problems/word-ladder/
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string> lWordQueue;
        int count = 1 ; 
        lWordQueue.push(beginWord);
        lWordQueue.push("");
        map<string, bool> lVisited; 
        for(auto& it: wordList)
        {
            lVisited[it]  = false;
        }
        string tmpStr;
        while(!lWordQueue.empty())
        {
            string word = lWordQueue.front();
            lWordQueue.pop();
            if(word == endWord)
            {
                return count;
            }else if( !lWordQueue.empty() && word == "")
            {
                // next level 
                count++;
                lWordQueue.push("");
            }else
            {
                for(int i = 0 ; i < word.length(); i++)
                {
                    tmpStr = word; 
                    for(char ch = 'a'; ch <='z'; ch++)
                    {
                        tmpStr[i] = ch;
                        if(find(wordList.begin(), wordList.end(), tmpStr) != wordList.end() && !lVisited[tmpStr])
                        {
                            lWordQueue.push(tmpStr);
                            lVisited[tmpStr] = true;
                        }
                    }
                }
            }
        }
        return 0; 

    }
};

int main()
{
    vector<string> wordList{"hot","dot","dog","lot","log","cog"}; 
    Solution S1;
    auto lLength = S1.ladderLength("hit", "cog", wordList);
    assert(lLength == 5);
    return 0 ; 
}