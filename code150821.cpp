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
class Solution 
{
    public:
    
    int ListToInt(ListNode* list)//переводим значения списков в число
    {
        int res = 0;
        int k = 1; //коэфициент (десятки, сотни и т.д.)
        
        while (list != nullptr)
        {
            res = res + (list->val * k);
            list = list->next;
            k = k * 10;
        };
        return res;
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum =  ListToInt(l1) + ListToInt(l2);//считаем сумму
        vector< int> tempVec{sum%10}; //временный вектор для хранения реверснутой суммы(сразу добавлем туда последнюю цифру sum и корректируем плказатель sum). 
        sum = sum / 10;
        while(sum) // переводим реверснутый результат сложения во временный вектор
        {
            tempVec.push_back(sum%10);
            sum = sum / 10;
        }
        ListNode * resList = new ListNode(tempVec.at(tempVec.size()-1)); // создаём лист с результатом и записываем туда порвое число из временного вектора
        // идём с конца временного вектора (со второго эл-та с конца потому что самый последний эл-т забит в лист результата при инициализации
        for (int i = tempVec.size()-2; i >= 0; i--)
        {
            ListNode * tempList = new ListNode(tempVec.at(i),resList);
            resList = tempList;
        }
        return resList;
    }
};

oh...