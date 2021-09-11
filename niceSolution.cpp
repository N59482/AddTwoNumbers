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

    void MTN(ListNode * l)// more then nine
    {
       if (l->val > 9)// если текущий элемент переполнен перекидываем десятки в следующий элемент.
        {
            l->next->val++; 
            l->val = l->val % 10;
        }
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode * tempList = new ListNode(l1->val + l2->val); // создаём лист с которым будет работать алгоритм и записываем в него сумму первых элементов листа(листы по условию не пустые)

        ListNode * resList = tempList; // результат должен указывать не голову листа, запоминаем голову в финальный лист
        
        while(l1->next != nullptr && l2->next != nullptr) // Этот цикл суммирует пока в списках один и тот же размер
        {
            tempList->next = new ListNode(l1->next->val + l2->next->val); // складываем их значение и передаём в конструктор следующего элемента

            MTN(tempList);
            
            // шаг
            tempList = tempList->next;
            l1 = l1->next;
            l2 = l2->next;
        };

        // если листы разгого размера

        while(l1->next != nullptr) // если первый лист больше
        {
            tempList->next = new ListNode(l1->next->val); // записываем след элемент 
            MTN(tempList); // переносим десятки с текущего в следующий если требуется
            // шаг
            tempList = tempList->next;
            l1 = l1->next;
        };
        while(l2->next != nullptr) // если второй лист больше
        {
            tempList->next = new ListNode(l2->next->val);  // записываем след элемент 
            MTN(tempList); // переносим десятки с текущего в следующий если требуется
            // шаг
            tempList = tempList->next;
            l2 = l2->next;
        };
        
        if ((l2->next == nullptr)&&(l1->next == nullptr)) // если оба листа пусты
        {
            if (tempList->val > 9)// если текущий элемент больше 9 перекидываем десятки в новый дополнительный элемент.
            {
                tempList->next = new ListNode(1); 
                tempList->val = tempList->val % 10;
            }
        };
        return resList;
    }
};