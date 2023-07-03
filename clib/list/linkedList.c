/*this file defines the basic list class "linkedList"*/
#include "linkedList.h"
//init
linkedList * linkedList_init_void(){
    linkedList* self = (linkedList*)malloc(sizeof(linkedList));
    self->firstNode = (linkedListNode*)malloc(sizeof(linkedListNode));
    self->firstNode->next = self->firstNode;
    self->middleNode = self->firstNode;
    self->unusedFirstNode = self->firstNode;
    self->nodeBeforeUnusedFirstNode = NULL;
    return self;
}
//private methods
void appendNewNode(linkedList* self){
	self->unusedFirstNode->next = malloc(sizeof(linkedListNode));
	((linkedListNode*)self->unusedFirstNode->next)->next = self->firstNode;
    self->valueCounter++;
    if((self->valueCounter-1)%2 == 1){
        self->middleNode = (linkedListNode*)self->middleNode->next;
    }
    else if((self->valueCounter-1)%2 == 0){
        //do nothing
    }
	return;
}

int32_t getMiddle(linkedList* self){
    if((self->valueCounter)%2 == 0){
        return ((self->valueCounter)/2) - 1;
    }
    else{
        return ((self->valueCounter-1)/2);
    }
}

linkedListNode* find(linkedList* self,int32_t position){
    linkedListNode* tmpPtr = NULL;
    int32_t const middle = getMiddle(self);
    if(position < middle){
        //use firstNode
        tmpPtr = self->firstNode;
        for(int32_t i = 0;i != position;i++){
            tmpPtr = (linkedListNode*)tmpPtr->next;
        }
        return tmpPtr;
    }
    else if(position > middle){
        tmpPtr = self->middleNode;
        for(int32_t i = 0;i != position - middle;i++){
            tmpPtr = (linkedListNode*)tmpPtr->next;
        }
        return tmpPtr;
    }
}

//impl
int32_t linkedList_append_int32_object(linkedList* self,object value){
    self->nodeBeforeUnusedFirstNode = self->unusedFirstNode;
    self->unusedFirstNode->value = value;
    int32_t returnValue = self->unusedFirstCounter;
    if(self->unusedFirstCounter == self->valueCounter){
        appendNewNode(self);
    }
    self->unusedFirstNode = (linkedListNode*)self->unusedFirstNode->next;
    self->unusedFirstCounter++;
    return returnValue;
}

bool linkedList_have_bool_object(linkedList* self,bool equals(object,object),object value){
    bool have = false;
    //TODO something
}

int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > (self->unusedFirstCounter - 1)){
        return -(position);
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
    }
    linkedListNode* tmp = find(self,position);
    free(tmp->value);
    tmp->value = value;
    return position;
}

object linkedList_get_object_void(linkedList* self){
    if(self->valueCounter == 0){
        return NULL;
    }
    return self->nodeBeforeUnusedFirstNode->value;
}

object linkedList_get_object_int32(linkedList* self,int32_t position){}
bool linkedList_delete_bool_int32(linkedList* self,int32_t position){}
bool linkedList_deleteFromTo_bool_int32(linkedList* self,int32_t from,int32_t to){}
void linkedList_clear_void_void(linkedList* self){}
void linkedList_close(linkedList* self){}
object linkedList_pop_object_void(linkedList* self){}
object linkedList_pop_object_int32(linkedList* self,int32_t position){}
object linkedList_exchange_object_int32_object(linkedList* self,int32_t position,object value){}
bool linkedList_exchange_bool_int32_int32(linkedList* self,int32_t position1,int32_t position2){}
int32_t linkedList_insert_int32_int32_object(linkedList* self,int32_t position,object value){}
void linkedList_delete_bool_void(linkedList *self){}