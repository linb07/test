#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);

        if (len1 < len2)
        {
            swap(l1, l2);
            swap(len1, len2);
        }
        
        ListNode* ans = l1;
        int addition = 0;
        for (int i = 0; i < len2; ++i)
        {
            l1->val = l1->val + l2->val + addition;
            addition = l1->val / 10;
            l1->val = l1->val % 10;
            if (i < len1 - 1)
            {
                l1 = l1->next;
            }
            l2 = l2->next;
        }
        for (int i = len2; i < len1; ++i)
        {
            l1->val = l1->val + addition;
            addition = l1->val / 10;
            l1->val = l1->val % 10;
            if (i < len1 - 1)
            {
                l1 = l1->next;
            }
        }
        if (addition > 0)
        {
            ListNode* addNode = new ListNode(addition);
            l1->next = addNode;
            addNode->next = NULL;
        }
        return ans;
    }
    int getListLen(ListNode* l1)
    {
        int cnt = 0;
        while (l1 != NULL)
        {
            ++cnt;
            l1 = l1->next;
        }
        return cnt;
    }
};

int main()
{
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    string str1, str2;
    cin>> str1 >> str2;
    ListNode* addList = l1;
    for(int i = 0; i < str1.size(); ++i)
    {
        int tmp = str1[i] - '0';
        ListNode* addNode = new ListNode(tmp);
        addNode->next = NULL;
        addList->next = addNode;
        addList = addList->next;
    }
    addList = l2;
    for(int i = 0; i < str2.size(); ++i)
    {
        int tmp = str2[i] - '0';
        ListNode* addNode = new ListNode(tmp);
        addNode->next = NULL;
        addList->next = addNode;
        addList = addList->next;
    }
    Solution sol;
    ListNode* ansList = sol.addTwoNumbers(l1, l2);
    while (ansList != NULL)
    {
        cout << ansList->val;
        ansList = ansList->next;
    }
    cout << endl;
    cin >> str1;
    return 0;
}