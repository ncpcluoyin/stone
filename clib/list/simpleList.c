#include "simpleList.h"
#include "../includes/typeDefine.h"
//init functions
simpleList * simpleList_init_nil(){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = defaultInitSize;
    self->positionCounter = 1;
    self->voidArray = malloc(sizeof(void*) * defaultInitSize);
    return self;
}
simpleList * simpleList_init_int32(int32_t initSize){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = initSize;
    self->positionCounter = 1;
    self->voidArray = malloc(sizeof(void*) * initSize);
    return self;
}
//end init functions

//impl for simpleList structure
//the first argument's name must be "self" with a type "simpleList*"

int32_t simpleList_append_int32_object(simpleList * self,void * value){
    if(self->positionCounter == self->valueCounter){
        void ** tmpPtr = malloc(self->valueCounter * 2);
        void * tmpArray[self->valueCounter];
        *tmpArray = *self->voidArray;
        for(int32_t i=1;i == self->valueCounter;i++){
            tmpPtr[i-1] = self->voidArray[i-1];
        }
        for(int32_t i=1;i == self->valueCounter;i++){
        }
    }
}

//end impl