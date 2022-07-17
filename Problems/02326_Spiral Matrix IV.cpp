/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int upRow = 0, downRow = m-1, leftCol = 0, rightCol = n-1, curX = 0, curY = -1;
        char dir = 'R'; // right -> down -> left -> up -> ...
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        while(upRow <= downRow && leftCol <= rightCol && head)
        {
            if(dir == 'R')
            {
                curY++;
                matrix[curX][curY] = head->val; head = head->next;
                if(curY == rightCol)
                {
                    upRow++;
                    dir = 'D';
                }
            }
            else if(dir == 'D')
            {
                curX++;
                matrix[curX][curY] = head->val; head = head->next;
                if(curX == downRow)
                {
                    rightCol--;
                    dir = 'L';
                }
            }
            else if(dir == 'L')
            {
                curY--;
                matrix[curX][curY] = head->val; head = head->next;
                if(curY == leftCol)
                {
                    downRow--;
                    dir = 'U';
                }
            }
            else
            {
                curX--;
                matrix[curX][curY] = head->val; head = head->next;
                if(curX == upRow)
                {
                    leftCol++;
                    dir = 'R';
                }
            }
        }

        return matrix;
    }
};
