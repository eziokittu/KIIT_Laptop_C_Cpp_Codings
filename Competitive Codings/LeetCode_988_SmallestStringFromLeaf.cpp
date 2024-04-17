// LeetCode Problem 988 - Smallest string starting from leaf
// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(){
    val=0;
    left = nullptr;
    right=nullptr;
  }
  TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
  };
  TreeNode(int x, TreeNode *_left, TreeNode *_right){
    val = x;
    left = _left;
    right = _right;
  };
};

vector<int> getLexo(vector<int> v1, vector<int> v2){
    if (v1.size()==0){
        return v2;
    }
    if (v2.size()==0){
        return v1;
    }
    // if (v1.size()<v2.size()){
    //     return v1;
    // }
    // else if (v2.size()<v1.size()){
    //     return v2;
    // }

    // iterating all the numbers
    int n = v1.size()>v2.size() ? v2.size() : v1.size();
    for (int i=0; i<n; i++){
        if (v1[i] < v2[i]){
            return v1;
        }
        else if (v1[i] > v2[i]){
            return v2;
        }
        if (i==n-1){
            if (n==v1.size()){
                return v1;
            }
            else{
                return v2;
            }
        }
    }

    // if both v1 and v2 are lexographically same return any
    return v1;
}

void getMinPath(TreeNode *root, vector<int> &ans, vector<int> temp){
  if (root->left==nullptr && root->right==nullptr){
    // cout << " DEBUG 2";
    ans = getLexo(ans, temp);
    return;
  }
  if (root->left != nullptr){
    vector<int> t = temp;
    t.insert(t.begin(), root->left->val);
    getMinPath(root->left, ans, t);
  }
  if (root->right != nullptr){
    vector<int> t = temp;
    t.insert(t.begin(), root->right->val);
    getMinPath(root->right, ans, t);
  }
}

string smallestFromLeaf(TreeNode* root) {
    vector<int> ans = {};
    getMinPath(root, ans, {root->val});

    string s = "";
    // reverse(ans.begin(), ans.end());
    for (auto i : ans){
        s+= static_cast<char>(i+'a');
    }
    return s;
}

int main()
{
  // root = [25,1,3,1,3,0,2]
  // root = [3,9,20,null,null,15,7]
    TreeNode *a = new TreeNode (7, nullptr, nullptr);
    TreeNode *b = new TreeNode (15, nullptr, nullptr);
    TreeNode *c = new TreeNode (20, b, a);
    
    // TreeNode *f = new TreeNode (1, nullptr, nullptr);
    // TreeNode *g = new TreeNode (3, nullptr, nullptr);
    // TreeNode *e = new TreeNode (9, f, g);
    TreeNode *e = new TreeNode (9, nullptr, nullptr);
    
    TreeNode *d = new TreeNode (3, e, c);
    
    cout << smallestFromLeaf(d);

    return 0;
}
 
    //     d
    // j       u
    //   d   h   n
    //        c