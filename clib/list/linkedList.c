/*this file defines the basic list class "linkedList"*/
#include "linkedList.h"
//init
linkedList * linkedList_init_void(){
    linkedList* self = (linkedList*)malloc(sizeof(linkedList));
    self->firstNode = (linkedListNode*)malloc(sizeof(linkedListNode));
    self->firstNode->next = self->firstNode;
    self->middlePtr = self->firstNode;
    self->unusedFirstNode = self->firstNode;
    return self;
}
//private methods
void appendNewNode(linkedList* self){
<<<<<<< HEAD
    linkedListNode* tmpPtr = self->positionPtr;
    for(int32_t i = 0;i != self->valueCounter - self->positionCounter;i++){
        tmpPtr = tmpPtr->next;
    }
    tmpPtr->next = (linkedListNode*)malloc(sizeof(linkedListNode));
    tmpPtr->next->next = self->firstNode;
    return;
=======
	self->unusedFirstNode->next = malloc(sizeof(linkedListNode));
	((linkedListNode*)self->unusedFirstNode->next)->next = self->firstNode;
	return;
>>>>>>> e510a67964aa023f6f16a13ca204672f04c81530
}
//impl
int32_t linkedList_append_int32_object(linkedList* self,object value){
    self->unusedFirstNode->value = value;
    int32_t returnValue = self->unusedFirstCounter;
    if(self->unusedFirstCounter == self->valueCounter){
        appendNewNode(self);
	self->valueCounter++;
	if((self->valueCounter+1)%2 == 1){
		self->middlePtr = (linkedListNode*)self->middlePtr->next;
	}
	else if((self->valueCounter+1)%2 == 0){
		//Do nothing
	}
    self->unusedFirstNode = (linkedListNode*)self->unusedFirstNode->next;
    self->unusedFirstCounter++;
    return returnValue;
}
bool linkedList_have_bool_object(linkedList* self,object value){
    //TODO
}
int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t position,object value){
    if(!(position <= self->valueCounter)){
        return -(position);
    }
    linkedListNode* tmpPtr = NULL;
    if(position < ((self->valueCounter+1)/2)-1){
	    for(int32_t i;i != position - 1;i++){
			
	    }

    }
}
object linkedList_get_object_void(linkedList* self){}
object linkedList_get_object_int32(linkedList* self,int32_t position){}
bool linkedList_delete_bool_int32(linkedList* self,int32_t position){}
bool linkedList_deleteFromTo_bool_int32(linkedList* self,int32_t from,int32_t to){}
void linkedList_clear_void_void(linkedList* self){}
void linkedList_close(linkedList* self){}
object linkedList_pop_object_void(linkedList* self){}
object linkedList_pop_object_int32(linkedList* self,int32_t position){}
