#include "simpleList.h"
#include "../includes/typeDefine.h"
//init functions
simpleList * simpleList_init_nil(){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = defaultInitSize - 1;
    self->positionCounter = 0;
    self->objectArray = malloc(sizeof(object) * defaultInitSize);
    return self;
}
simpleList * simpleList_init_int32(int32_t initSize){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = initSize - 1;
    self->positionCounter = 0;
    self->objectArray = malloc(sizeof(object) * initSize);
    return self;
}
//end init functions

//impl for simpleList structure
//the first argument's name must be "self" with a type "simpleList*"

int32_t simpleList_append_int32_object(simpleList * self,object value){
    if(self->positionCounter == self->valueCounter){
        object * tmpPtr = malloc(self->valueCounter * 2);
        for(int32_t i=0;i == self->valueCounter;i++){
            tmpPtr[i] = self->objectArray[i];
        }
        free(self->objectArray);
        self->objectArray = tmpPtr;
        self->valueCounter = self->valueCounter * 2;
    }
    self->objectArray[self->positionCounter] = value;
    self->positionCounter++;
    return self->positionCounter - 1;
}

//end impl