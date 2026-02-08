/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *order(struct ListNode *head, struct ListNode *end) {
    if (head == end) {
        return NULL;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->val = slow->val;

    root->left = order(head, slow);
    root->right = order(slow->next, end);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    return order(head, NULL);
}