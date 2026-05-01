#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Binary Tree के नोड की परिभाषा
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right) {
        // Base Case: अगर इंडेक्स रेंज से बाहर है
        if (left > right) return nullptr;

        // 1. दी गई रेंज में मैक्सिमम वैल्यू का इंडेक्स ढूंढें
        int max_idx = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        // 2. मैक्सिमम वैल्यू के साथ रूट नोड बनाएं
        TreeNode* root = new TreeNode(nums[max_idx]);

        // 3. रिकर्शन का उपयोग करके लेफ्ट और राइट सब-ट्री बनाएं
        root->left = build(nums, left, max_idx - 1);
        root->right = build(nums, max_idx + 1, right);

        return root;
    }
};

// --- VS Code में आउटपुट देखने के लिए हेल्पर फंक्शन्स ---

// ट्री को Pre-order (Root, Left, Right) में प्रिंट करने के लिए
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution sol;
    
    // इनपुट एरे
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    cout << "Input Array: [3, 2, 1, 6, 0, 5]" << endl;

    // ट्री का निर्माण
    TreeNode* root = sol.constructMaximumBinaryTree(nums);

    // आउटपुट प्रिंट करें
    cout << "Pre-order Traversal of constructed tree: ";
    printTree(root); 
    // आउटपुट: 6 3 2 1 5 0 
    cout << endl;

    return 0;
}