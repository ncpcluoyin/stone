/*this file defines the basic list class "linkedList"*/
#include "linkedList.h"
//init
linkedList * linkedList_init_void(){
    linkedList* self = (linkedList*)malloc(sizeof(linkedList));
    self->next = self;
    return self;
}
//impl
int32_t linkedList_append_int32_object(linkedList* self,object value){}
bool linkedList_have_bool_object(linkedList* self,object value){}
int32_t linkedList_set_int32_int32_object(linkedList* self,int32_t position,object value){}
object linkedList_get_object_void(linkedList* self){}
object linkedList_get_object_int32(linkedList* self,int32_t position){}
bool linkedList_delete_bool_int32(linkedList* self,int32_t position){}
bool linkedList_deleteFromTo_bool_int32(linkedList* self,int32_t from,int32_t to){}
void linkedList_clear_void_void(linkedList* self){}
void linkedList_close(linkedList* self){}
object linkedList_pop_object_void(linkedList* self){}
object linkedList_pop_object_int32(linkedList* self,int32_t position){}
