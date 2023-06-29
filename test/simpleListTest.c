#include "../clib/list/simpleList.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t main(){
    simpleList* list = simpleList_init_int32(14);
    int32_t* a;
    for(int32_t i = 0;i != 20;i++){
        a = (int32_t*)malloc(sizeof(int32_t));
	*a = i;
        simpleList_append_int32_object(list,a);
    }
    simpleList_delete_bool_int32(list,4);
    simpleList_delete_bool_int32(list,5);
    printf("%d values\n",list->valueCounter+1);
    printf("%dth value\n",list->positionCounter - 1);
    for(int32_t i = 0;i != list->positionCounter;i++){
	    a = (int32_t*)simpleList_get_object_int32(list, i);
	    printf("%dth is %d\n",i,*a);
    }
    a = (int32_t*)malloc(sizeof(int32_t));
    *a = 114514;
    simpleList_insert_int32_int32_object(list,1, a);
    printf("%d values\n",list->valueCounter+1);
    printf("%dth value\n",list->positionCounter - 1);
    for(int32_t i = 0;i != list->positionCounter;i++){
	    a = (int32_t*)simpleList_get_object_int32(list, i);
	    printf("%dth is %d\n",i,*a);
    }
    simpleList_close(list);
    return 0;
}
