#include "list.h"
#include <stdio.h>


static int head_count = 0;
static int node_count=0;
static List arrayHeads[LIST_MAX_NUM_HEADS];
static Node arrayNode[LIST_MAX_NUM_NODES];
static Node* freeNodes = NULL;
static List* freeLists = NULL;
static enum ListOutOfBounds boundCheck;

List* List_create(){
    if (head_count >=LIST_MAX_NUM_HEADS && freeLists==NULL){
        return NULL;
    }
    else{

        List* list;
        if (freeLists ==NULL){
        list = &arrayHeads[head_count];
        list->head=NULL;
        list->tail=NULL;
        list->current=NULL;
        list->size=0;
        head_count++;
        return list;
        }
        else{
            list = freeLists;
            freeLists=freeLists->ListTracker;
            return list;
        }
    }
    

}

int List_count(List* pList){
    if (pList->head == NULL) {
        
        return 0;
    }
    return pList->size;

}

void* List_first(List* pList){
    if (pList == NULL){
        return NULL;
    }
    else if(pList->head == NULL){
        pList->current=pList->head;                                                                               
        return NULL;
    }
    else{
        pList->current=pList->head;
        return pList->current->item;
    }
   
}

void* List_last(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if(pList->tail==NULL){
        pList->current=pList->tail;
        return NULL;
    }
    else{
        pList->current=pList->tail;
        return pList->current->item;
    }
}

void* List_next(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if(pList->current==NULL){
        return NULL;
    }
    else if (pList->current->next==NULL){
        pList->current=pList->current->next;
       
        return NULL;
    }
    else{
        pList->current=pList->current->next;
        return pList->current->item;
    }
}

void* List_prev(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if(pList->current==NULL){
        return NULL;
    }
    else if (pList->current->prev==NULL){
        pList->current=pList->current->prev;
        
        return NULL;
    }
    else{
        pList->current=pList->current->prev;
        return pList->current->item;
    }
}

void* List_curr(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if(pList->current==NULL){
        return NULL;
    }
    else{
        

        return pList->current->item;
    }
    
}

int List_insert_after(List* pList, void* pItem){
    if (pList==NULL){
        return LIST_FAIL;
    }
    else if(node_count>=LIST_MAX_NUM_NODES && freeNodes==NULL){
        return LIST_FAIL;
    }
    else{
        Node* newNode;
        {
            if(freeNodes==NULL){
            newNode = &arrayNode[node_count];        
            newNode->item= pItem;
            newNode->nodeIndex= node_count;
            newNode->prev=NULL;
            newNode->next=NULL;
            node_count++;
            }
            else{
                newNode = freeNodes;
                freeNodes = freeNodes->prev;
                newNode->item= pItem;
                newNode->prev=NULL;
                newNode->next=NULL;
                node_count++;

            }
        }
        if (pList->size==0){
            pList->head=newNode;
            pList->tail=newNode;
            pList->current=newNode;
            pList->size++;
            
        }
    
        else{
            
            if (pList->head->prev==pList->current){
                newNode->next=pList->head;
                newNode->prev=pList->current;
                pList->head=newNode;
                pList->current=newNode;
                pList->size++;
            }
            
            else if (pList->tail->next==pList->current){
                newNode->prev=pList->tail;
                newNode->next=pList->current;
                pList->tail=newNode;
                pList->current=newNode;
                pList->size++;
            }
            else if(pList->current==pList->tail){
                
                newNode->next=NULL;
                newNode->prev=pList->tail;
                pList->current->next=newNode;
                pList->tail=newNode;
                pList->current=pList->tail;
                pList->size++;
                
            }
            else{
                newNode->prev=pList->current;
                newNode->next=pList->current->next;
                pList->current->next->prev=newNode;
                pList->current=newNode;
                pList->size++;
                
            }
            
        }
        
        return LIST_SUCCESS;
    }
    return LIST_FAIL;
}

int List_insert_before(List* pList, void* pItem){
    if (pList==NULL){
        return LIST_FAIL;
    }

    else if(node_count>=LIST_MAX_NUM_NODES){
        return LIST_FAIL;
    }

    else{
        Node* newNode;
        {
            if(freeNodes==NULL){
                newNode = &arrayNode[node_count];        
                newNode->item= pItem;
                newNode->nodeIndex= node_count;
                newNode->prev=NULL;
                newNode->next=NULL;
                node_count++;
            }
            else{
                newNode = freeNodes;
                freeNodes = freeNodes->prev;
                newNode->item= pItem;
                newNode->prev=NULL;
                newNode->next=NULL;
                node_count++;
            }
        }
        
        if (pList->size==0){
            pList->head=newNode;
            pList->tail=newNode;
            pList->current=newNode;
            
        }
        else{
            if (pList->head->prev==pList->current){
                newNode->next=pList->head;
                newNode->prev=NULL;
                pList->head=newNode;
                pList->current=pList->head;
            }
            else if(pList->current==pList->head){
                newNode->prev=NULL;
                newNode->next=pList->current;
                pList->head=newNode;
                pList->current=newNode;
            }
            else if(pList->tail->next==pList->current){
                newNode->prev=pList->tail;
                newNode->next=pList->current;
                pList->tail=newNode;
                pList->current=newNode;
            }
            
            else{
                newNode->prev=pList->current->prev;
                newNode->next=pList->current;
                pList->current->prev->next=newNode;
                pList->current->prev = newNode;
                pList->current=newNode;
                
            }
        }
        pList->size++;
        return LIST_SUCCESS;

    }
    return LIST_FAIL;
    
}

int List_append(List* pList, void* pItem){
    if (pList==NULL){
        return LIST_FAIL;
    }

    else if(node_count>=LIST_MAX_NUM_NODES){
        return LIST_FAIL;
    }
    else{
       Node* newNode;
       {
       if(freeNodes==NULL){
            newNode = &arrayNode[node_count];        
            newNode->item= pItem;
            newNode->nodeIndex= node_count;
            newNode->prev=NULL;
            newNode->next=NULL;
            node_count++;
            }
        else{
            newNode = freeNodes;
            freeNodes = freeNodes->prev;
            newNode->item= pItem;
            newNode->prev=NULL;
            newNode->next=NULL;
            node_count++;
        }
       }
       
       if (pList->size==0){
            pList->head=newNode;
            pList->tail=newNode;
            pList->current=newNode;
            
        }
       else{

       newNode->next=pList->tail->next;
       newNode->prev=pList->tail;
       pList->tail=newNode;
       pList->current=newNode;
       
       }
       pList->size++;
       return LIST_SUCCESS;
    }
    return LIST_FAIL;

}

int List_prepend(List* pList, void* pItem){
    if (pList==NULL){
        return LIST_FAIL;
    }

    else if(node_count>=LIST_MAX_NUM_NODES){
        return LIST_FAIL;
    }
    else{
       Node* newNode;
       {
       if(freeNodes==NULL){
            newNode = &arrayNode[node_count];        
            newNode->item= pItem;
            newNode->nodeIndex= node_count;
            newNode->prev=NULL;
            newNode->next=NULL;
            node_count++;
            }
        else{
            newNode = freeNodes;
            freeNodes = freeNodes->prev;
            newNode->item= pItem;
            newNode->prev=NULL;
            newNode->next=NULL;
            node_count++;
        }
       }
       if (pList->size==0){
            pList->head=newNode;
            pList->tail=newNode;
            pList->current=newNode;
            
        }
        else{
            newNode->next=pList->head;
            newNode->prev=pList->head->prev;
            pList->head=newNode;
            pList->current=newNode;
        }
        pList->size++;
        return LIST_SUCCESS;
    }
    return LIST_FAIL;
}

void* List_remove(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if (pList->size==0){
        return NULL;
    }
    else if (pList->current==pList->head->prev||pList->current==pList->tail->next){
        return NULL;
    }
    else{
            Node* temp = pList->current;
            {
            
                if(pList->current==pList->head->prev||pList->current==pList->tail->next){
                    pList->head=NULL;
                    pList->tail=NULL;
                    pList->current=NULL;
                }
                else if(pList->current->prev==NULL){
                    pList->head=pList->current->next;
                    pList->current=pList->current->next;
                }
                else if(pList->current->next==NULL){
                    pList->tail=pList->current->prev;
                    pList->current=pList->current->prev;
                }
                else{
                    pList->current->prev->next=pList->current->next;
                    pList->current->next->prev=pList->current->prev;
                    pList->current=pList->current->next;
                }
            }
            if(freeNodes==NULL){
                freeNodes=&arrayNode[temp->nodeIndex];
            }
            else{
                freeNodes->next=&arrayNode[temp->nodeIndex];
                freeNodes=freeNodes->next;
            }
            pList->size--;
            return temp->item;
    }
}

void* List_trim(List* pList){
    if (pList==NULL){
        return NULL;
    }
    else if (pList->size==0){
        return NULL;
    }
    else{
        Node* temp = pList->tail;
        pList->tail = pList->tail->prev;
        pList->current = pList->tail;
        pList->size--;
        if(freeNodes==NULL){
            freeNodes=&arrayNode[temp->nodeIndex];
            }
        else{
            freeNodes->next=&arrayNode[temp->nodeIndex];
            freeNodes=freeNodes->next;    
        }   
      return temp->item;  
    }
    
}

void List_concat(List* pList1, List* pList2){
    if (pList1->size == 0){
        pList1=pList2;
    }
    pList1->tail->next=pList2->head;
    pList1->tail=pList2->tail;
    pList1->size+= pList2->size;
    pList2->head=NULL;
    pList2->tail=NULL;
    pList2->size=0;
    pList2->ListTracker= freeLists;
    freeLists=pList2;
    
}

void List_free(List* pList, FREE_FN pItemFreeFn){
    pList->current=pList->head;
    Node* temp;
    while (pList->current != NULL){
        temp=pList->current;
        (*pItemFreeFn)(pList->current);
        pList->current=pList->current->next;
        if(freeNodes==NULL){
                freeNodes=&arrayNode[temp->nodeIndex];
        }
        else{
            freeNodes->next=&arrayNode[temp->nodeIndex];
            freeNodes=freeNodes->next;

        }
    }
    pList->ListTracker =freeLists;
    freeLists=pList;
}

void* List_search(List* pList, COMPARATOR_FN pComparator, void* pComparisonArg){
    if (pList->size==0){
        return NULL;
    }
    else{
        if (pList->current==pList->head->prev){
            pList->current=pList->head;
        }
        while (pList->current!=NULL ){
            int tester = (*pComparator)(pList->current->item, pComparisonArg);
            if (tester==1){
                return pList->current->item;
            }

        }
    }
    pList->current=pList->tail->next;
    
    return NULL;
}