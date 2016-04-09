//原图每个节点，与新图中每个节点 建立一个对应关系(节点对)
//同时对原图中每个节点，通过hash判断是否访问过
//未访问的要复制一遍，已访问过的通过节点对找到已复制过的点

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node)
    {
        if(!node)
            return NULL;
        visit[node] = true;
        UndirectedGraphNode* cpNode = new UndirectedGraphNode(node->label);
        nodePair[node] = cpNode;
        cpNode->neighbors.resize(node->neighbors.size());
        for(int i=0; i<node->neighbors.size(); ++i)
        {
            if(visit.find(node->neighbors[i])==visit.end()){
                cpNode->neighbors[i] = dfs( node->neighbors[i] );
            }
            else{
                cpNode->neighbors[i] = nodePair[node->neighbors[i]];
            }
        }
       
        return cpNode;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        visit.clear();
        nodePair.clear();
        return dfs(node);
    }
    unordered_map<UndirectedGraphNode*, bool> visit;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodePair;
};