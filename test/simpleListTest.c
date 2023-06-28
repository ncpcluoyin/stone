#include "../clib/list/simpleList.h"
#include <stdio.h>
int32_t main(){
    simpleList* list = simpleList_init_int32(14);
    int32_t* a;
    for(int32_t i = 0;i != 200;i++){
        a = (int32_t*)malloc(sizeof(int32_t));
        simpleList_append_int32_object(list,a);
    }
    simpleList_delete_bool_int32(list,4);
    simpleList_delete_bool_int32(list,5);
    printf("%d values\n",list->valueCounter+1);
    printf("%d values\n",list->positionCounter);
    simpleList_close(list);
    return 0;
}