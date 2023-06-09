/*this file defines the basic list class "linkedList"*/
#include <stdint-gcc.h>
#include "../includes/alloc.h"
#include "../includes/typeDefine.h"
#ifndef __STONE_LINKED_LIST__
#define __STONE_LINKED_LIST__ 1919810

typedef struct{
    object value;
    object next;//remember to force-convert to linkedListNode*
    object previous;//remember to force-convert to linkedListNode*
} linkedListNode;

typedef struct{
    int32_t valueCounter;
    int32_t positionCounter;
    linkedListNode* positionPointer;
} linkedList;

//init functions
linkedList * linkedList_init_void();
//impl for linkedList
int32_t linkedList_append_int32_object(linkedList* self,object value);
bool linkedList_have_bool_object(linkedList* self,bool equals(object,object),object value);
int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t position,object value);
object linkedList_get_object_void(linkedList* self);
object linkedList_get_object_int32(linkedList* self,int32_t position);
bool linkedList_delete_bool_int32(linkedList* self,int32_t position);
void linkedList_close(linkedList* self);
object linkedList_pop_object_void(linkedList* self);
object linkedList_pop_object_int32(linkedList* self,int32_t position);
object linkedList_exchange_object_int32_object(linkedList* self,int32_t position,object value);
bool linkedList_exchange_bool_int32_int32(linkedList* self,int32_t position1,int32_t position2);
int32_t linkedList_insert_int32_int32_object(linkedList* self,int32_t position,object value);
void linkedList_delete_bool_void(linkedList *self);

//impl for linkedList end
#endif
