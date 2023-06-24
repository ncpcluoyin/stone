/*this file defines the basic list class "simpleList"
*this file's naming rule use stone2c name
*example:
*if we have a class named "a"
*the class "a" has a field named "b"
*then there will be a c structure named a(maybe be mangled)
*and the structure has a value called a_b
*whether you understand or not
*it doesn't matter
*/

/*because we are going to use intXX_t,but we want it to be "freestanding"
*so we use stdint-gcc.h instead of stdint.h
*it will work better while using a gcc with compile option "--with-headers"
*clang CLANG Clang do not support this header!!!!!!!!!!!!!!!!!!
*/
#include <stdint-gcc.h>
#include "../includes/alloc.h"
#include "../includes/typeDefine.h"

#define defaultInitSize 4

//define structure(object only)
typedef struct{
    int32_t valueCounter;
    int32_t positionCounter;
    object * objectArray;
} simpleList;

//init for simpleList structure
simpleList * simpleList_init_void();
simpleList * simpleList_init_int32(int32_t initSize);

//impl for simpleList structure
int32_t simpleList_append_int32_object(simpleList* self,object value);
bool simpleList_have_bool_object(simpleList* self,object value);
int32_t simpleList_set_int32_int32_object(simpleList* self,int32_t position,object value);
object simpleList_get_object_void(simpleList* self);
object simpleList_get_object_int32(simpleList* self,int32_t position);
bool simpleList_delete_bool_int32(simpleList* self,int32_t position);
bool simpleList_deleteFromTo_bool_int32(simpleList* self,int32_t from,int32_t to);
void simpleList_clear_void_void(simpleList* self);
void simpleList_close(simpleList* self);
object simpleList_pop_object_void(simpleList* self);//TODO
object simpleList_pop_object_int32(simpleList* self,int32_t position);//TODO