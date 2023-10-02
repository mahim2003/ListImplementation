#include "list.h"
#include <stdio.h>

    typedef void (*FREE_FN)(void* pItem);

    void freeFunction(void* pItem){
        pItem = NULL;
    }

    typedef bool (*COMPARATOR_FN)(void* pItem, void* pComparisonArg);

    bool compareFunction(void* pItem, void* pComparisonArg){
        if (pItem==pComparisonArg){
            return true;
        }
        else{
            return false;
        }
    }

    void Test1(){
        printf("TEST CASE 1\n");
        List* list1 = List_create();
        int num1 = 1;
        int add1 = List_insert_after(list1, &num1);
        int* current1 = List_curr(list1);
        printf("current item is %d\n", *current1);
        int num2 = 2;
        int add2 =List_insert_after(list1, &num2);
        current1 = List_curr(list1);
        printf("current item is %d\n", *current1);
        int num3 = 3;
        int add3 = List_insert_before(list1, &num3);
        current1 = List_curr(list1);
        printf("current item is %d\n", *current1);
        current1 = List_first(list1);
        printf("first item is %d\n", *current1);
        current1 = List_last(list1);
        printf("last item is %d\n", *current1);
        printf("The entire list is as follows:\n");
        int* current2 = List_first(list1);
        for (int i=0;i<3;i++){
            printf(" %d ",*current2);
            current2 = List_next(list1);
        }

        printf("\n");

    }
    
    void Test2(){
    printf("TEST CASE 2\n");
    List* list1 = List_create();
    int y= 4;
    int b = List_insert_after(list1, &y);
    int* current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    

    int y1= 5;
    void* abc1= &y1;
    int b1 = List_insert_after(list1, abc1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);

    int y2= 6;
    void* abc2= &y2;
    int b2 = List_insert_after(list1, abc2);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);

    List_last(list1);
    current1 = List_curr(list1);
    printf("last item is %d\n", *current1);

    List* list2 = List_create();
    int y3= 1;
    void* abc3= &y3;
    int b3 = List_insert_after(list2, abc3);
    current1 = List_curr(list2);
    printf("current item is %d\n", *current1);

    int y4= 2;
    void* abc4= &y4;
    int b4 = List_insert_after(list2, abc4);
    current1 = List_curr(list2);
    printf("current item is %d\n", *current1);

    List_concat(list1, list2);
    List_last(list1);
    current1 = List_curr(list1);
    printf("last item is %d\n", *current1);
    List_free(list2, freeFunction);
    int a=List_count(list1);
    printf(" size is  %d\n", a);

    List* list3 = List_create();
    }

    void Test3(){
    printf("TEST CASE 3\n");
    List*  list1 = List_create();
    int a = List_count(list1);
    printf("size of list is %d\n", a);

    List_curr(list1);
    int y= 4;
    void* abc= &y;
    int b = List_insert_after(list1, abc);
    int* current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
   
    int x=20;
    void* abd=&x;
    int c= List_insert_after(list1,abd);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    int z=30;
    void* abe=&z;
    int d=List_insert_after(list1, abe);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_prev(list1);
    int z1=305;
    void* abe2=&z1;
    int d12=List_insert_before(list1, abe2);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    
    a=List_count(list1);
    printf(" we go %d\n", a);
    List_prev(list1);
   
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    int x1= 100;
    void* abe1=&x1;
    int d1= List_append(list1,abe1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_last(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_prev(list1);
   
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_prev(list1);
   
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_prev(list1);
   
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_prev(list1);
   
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1); 
    int x2= 823;
    void* abe3=&x2;
    int d2=List_prepend(list1,abe3);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_remove(list1);
    current1 = List_next(list1);
    printf("current item is %d\n", *current1);
    List_remove(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_next(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_first(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_trim(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    List_last(list1);
    current1 = List_curr(list1);
    printf("current item is %d\n", *current1);
    

    }





int main(){

    Test1();
    Test2();
    Test3();
        //int* itemValue = (int*)(pList->current->item);
        //printf("the item is %d\n", *itemValue);

    
    /*List*  list1 = List_create();
    int a = List_count(list1);
    printf("here we go %d\n", a);

    List_curr(list1);
    int y= 4;
    void* abc= &y;
    int b = List_insert_after(list1, abc);
    printf("here we go again %d\n", b);
    List_curr(list1);
   
    int x=20;
    void* abd=&x;
    int c= List_insert_after(list1,abd);
    List_curr(list1);
    int z=30;
    void* abe=&z;
    int d=List_insert_after(list1, abe);
    List_curr(list1);
    List_prev(list1);
    int z1=305;
    void* abe2=&z1;
    int d12=List_insert_before(list1, abe2);
    List_curr(list1);
    
    a=List_count(list1);
    printf(" we go %d\n", a);
    List_prev(list1);
   
    List_curr(list1);
    int x1= 100;
    void* abe1=&x1;
    int d1= List_append(list1,abe1);
    List_curr(list1);
    List_last(list1);
    List_curr(list1);
    List_prev(list1);
   
    List_curr(list1);
    List_prev(list1);
   
    List_curr(list1);
    List_prev(list1);
   
    List_curr(list1);
    List_prev(list1);
   
    List_curr(list1); 
    int x2= 823;
    void* abe3=&x2;
    int d2=List_prepend(list1,abe3);
    List_curr(list1);
    List_next(list1);
    List_curr(list1);
    List_first(list1);
    List_curr(list1);
    List_remove(list1);
    List_curr(list1);
    List_remove(list1);
    List_curr(list1);
    List_next(list1);
    List_curr(list1);
    List_first(list1);
    List_curr(list1);
    List_trim(list1);
    List_curr(list1);
    List_last(list1);
    List_curr(list1);
    int z5=278;
    void* abe5=&z5;
    int d5=List_insert_after(list1, abe5);
    List_curr(list1);
    List_prev(list1);
    List_curr(list1);*/

    

    return 0;
}