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

int getLengh(struct ListNode *head) {
    int size = 0;

    for (int i = 0; head != NULL; i++) {
        size++;
        head = head->next;
    }
    return size;
}

struct TreeNode *order(struct ListNode *head, int beg, int end) {
    if (beg > end) {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    int mid = (beg + end)/2;

    struct ListNode *aux = head;

    for (int i = 0; i < mid; i++) {
        aux = aux->next;
    }
    root->val = aux->val;

    root->left = order(head, beg, mid-1);
    root->right = order(head, mid+1, end);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    int size = getLengh(head);

    return order(head, 0, size-1);
}
