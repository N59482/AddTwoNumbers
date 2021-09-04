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
    
    void ListtoVector(ListNode* l,vector<int> & v) // если остался один лист и отсутствует overnine 
    //почему не работает с указателем на вектор а только с ссылкой?
    {
        while(l != nullptr)
        {
            v.push_back(l->val);
            l = l->next;
        }
    };
    
    int DoSum(ListNode* l1, ListNode* l2, int &overnine)// функция суммирующа два числа и возвращающая единицы а десятки сохраняются в overnine
    {
        int sum = l1->val + l2->val + overnine; // ?? + overnine;
            cout<<l1->val<<" + "<<l2->val<<" + "<<overnine<<" = "<<sum<<endl;
        if((sum)>9)
        {
            cout<<sum<<" > 9"<<endl<<sum<<" = ";
            sum = sum%10;
            overnine = 1;
            cout<<sum<<" and "<<overnine<<endl;
        }
        else
        {
            cout<<sum<<" !> 9"<<endl;
            overnine = 0;
        }
        return sum;
    };
    
    int DoSum (ListNode* l, int &overnine)// переопределение для работы с одним списком.
    {
        int sum = l->val + overnine;
        cout<<l->val<<" + "<<overnine<<" = "<<sum<<endl;
        if((sum)>9)
        {
            cout<<sum<<" > 9"<<endl<<sum<<" = ";
            sum = sum%10;
            overnine = 1;
            cout<<sum<<" and "<<overnine<<endl;
        }
        else
        {
            cout<<sum<<" !> 9"<<endl;
            overnine = 0;
        }
        return sum;
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        cout<<"START"<<endl;
        int overnine = 0;
        vector<int> tempV;
        
        while(l1 != nullptr && l2 != nullptr)// считаеи сумму эдементов пока не упрёмся в конец одного из списков
        {
            cout<<"в обоих списках есть элементы"<<endl;
            tempV.push_back(DoSum(l1,l2,overnine));
            l1 = l1->next;
            l2 = l2->next;
        };
        
        if (l1 == nullptr && l2 != nullptr) // остался только первый список
        {
            cout<<"остался только второй список"<<endl;
            if(!overnine) ListtoVector(l2, tempV)
            else
            
        } else if (l1 != nullptr && l2 == nullptr) // остался только второй список
        {
            cout<<"остался только первый список"<<endl;
            if(!overnine) ListtoVector(l1, tempV)
            else
            
        } else if (l1 == nullptr && l2 == nullptr && overnine) // списки пусты но остался overnine
        {
            cout<<"списки пусты но остался overnine"<<endl;
            tempV.push_back(overnine);
        };
        
        
        ListNode * resList = new ListNode(tempV.at(tempV.size()-1)); // создаём лист с результатом и записываем туда порвое число из временного вектора
        // идём с конца временного вектора (со второго эл-та с конца потому что самый последний эл-т забит в лист результата при инициализации
        for (int i = tempV.size()-2; i >= 0; i--)
        {
            ListNode * tempList = new ListNode(tempV.at(i),resList);
            resList = tempList;
        }
        
        return resList;
    }
};