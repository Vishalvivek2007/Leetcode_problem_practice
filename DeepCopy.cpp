class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* DeepCopy(Node* node){
        if(node == NULL){
            return NULL;
        }
        if(mp.count(node)){
            return mp[node];
        }
        Node* ans = new Node(node->val);
        mp[node] = ans;
        for(int i = 0; i < node->neighbors.size(); i++){
            ans->neighbors.push_back(DeepCopy(node->neighbors[i]));
        }
        return ans;
    }

    Node* cloneGraph(Node* node) {
        return DeepCopy(node);
    }
};