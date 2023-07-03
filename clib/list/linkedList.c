#include "linkedList.h"

//private methods

void getToLast(linkedList* self){
}

void append(linkedList* self){
    
}

//private methods

//init functions
linkedList * linkedList_init_void(){
    linkedList* self = (linkedList*)malloc(sizeof(linkedList));
    self->positionPointer = (linkedListNode*)malloc(sizeof(linkedListNode));
    return self;
}
//impl for linkedList
int32_t linkedList_append_int32_object(linkedList* self,object value){}
bool linkedList_have_bool_object(linkedList* self,bool equals(object,object),object value){}
int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t position,object value){}
object linkedList_get_object_void(linkedList* self){}
object linkedList_get_object_int32(linkedList* self,int32_t position){}
bool linkedList_delete_bool_int32(linkedList* self,int32_t position){}
void linkedList_close(linkedList* self){}
object linkedList_pop_object_void(linkedList* self){}
object linkedList_pop_object_int32(linkedList* self,int32_t position){}
object linkedList_exchange_object_int32_object(linkedList* self,int32_t position,object value){}
bool linkedList_exchange_bool_int32_int32(linkedList* self,int32_t position1,int32_t position2){}
int32_t linkedList_insert_int32_int32_object(linkedList* self,int32_t position,object value){}
void linkedList_delete_bool_void(linkedList *self){}
