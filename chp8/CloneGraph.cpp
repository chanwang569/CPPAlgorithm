#include<unordered_map>
#include<queue>
#include<vector>
// https://leetcode-cn.com/problems/clone-graph/
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> lVisited;
        queue<Node*> lQueue; // Will only add "Old" node
        lQueue.push(node);
        
        if(node)
        {
             lVisited[node] = new Node(node->val);
        }
        while (!lQueue.empty())
        {
            Node* lNode = lQueue.front();
            lQueue.pop();
            if(!lNode)
                continue;

            for(auto& neighbor : lNode->neighbors)
            {
                if(lVisited.find(neighbor) == lVisited.end())
                {
                    lVisited[neighbor] =  new Node(neighbor->val);
                    lQueue.push(neighbor);
                }
                lVisited[lNode]->neighbors.emplace_back(lVisited[neighbor]);
            }
        }
        
        return lVisited[node];
    }
};
int main()
{
    Solution S1;
    return 0; 
}