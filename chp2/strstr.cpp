#include <iostream>
#include<cstring>
#include <functional>
using namespace std;

size_t strStr(string source, string target) 
{
    if(source.size() < target.size())
    {
        return -1;
    }
        
    std::size_t lTargetHash = std::hash<std::string>{}(target);
    for(size_t i = 0; i < source.size() - target.size() + 1; i++ )
    {
        string lSubStr = source.substr(i, target.size());
        if(std::hash<std::string>{}(lSubStr) == lTargetHash )
            return i;
    }
    return -1;
}
int main()
{
    string lSource{"HelloWorld"};

    string lTarget("HelloWorld");
    size_t lsubPos = strStr(lSource, lTarget);
    size_t lSubPos2 = strStr(lSource,"World");
    size_t lSubPos3 = strStr("World",lSource);
    return 0;
}