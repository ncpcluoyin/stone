/*this file defines the basic list class "linkedList"*/
#include <stdint-gcc.h>
#include "../includes/alloc.h"
#include "../includes/typeDefine.h"
#ifndef __STONE_LINKED_LIST__
#define __STONE_LINKED_LIST__ 1919810

typedef struct{
    object value;
    void* next;//remember to force-convert to linkedListNode*
} linkedListNode;

typedef struct{
    int32_t valueCounter;
    int32_t unusedFirstCounter;
    linkedListNode* firstNode;
    linkedListNode* middleNode;
    linkedListNode* unusedFirstNode;
} linkedList;

//init functions
linkedList * linkedList_init_void();
//impl for linkedList
int32_t linkedList_append_int32_object(linkedList* self,object value);
bool linkedList_have_bool_object(linkedList* self,object value);
int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t position,object value);
object linkedList_get_object_void(linkedList* self);
object linkedList_get_object_int32(linkedList* self,int32_t position);
bool linkedList_delete_bool_int32(linkedList* self,int32_t position);
void linkedList_close(linkedList* self);
object linkedList_pop_object_void(linkedList* self);
object linkedList_pop_object_int32(linkedList* self,int32_t position);
//still have some impl

//impl for linkedList end
#endif
