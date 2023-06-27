#include "simpleList.h"
//init functions
simpleList * simpleList_init_void(){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = simpleListDefaultInitSize - 1;
    self->positionCounter = 0;
    self->objectArray = malloc(sizeof(object) * simpleListDefaultInitSize);
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
    if((self->positionCounter-1) == self->valueCounter){
        object * tmpPtr = malloc((self->valueCounter+1) * 2 * sizeof(object));
        for(int32_t i=0;i != self->positionCounter;i++){
            tmpPtr[i] = self->objectArray[i];
        }
        free(self->objectArray);
        self->objectArray = tmpPtr;
        self->valueCounter = ((self->valueCounter+1) * 2) - 1;
    }
    self->objectArray[self->positionCounter] = value;
    self->positionCounter++;
    return self->positionCounter - 1;
}
//TODO need rewrite "have"
bool simpleList_have_bool_object(simpleList* self,bool equals(object,object),object value){
    bool have = false;
<<<<<<< HEAD
    for(int32_t i = 0;i != self->positionCounter;i++){
        if(self->objectArray[i] == value){have = true;}
=======
    for(int32_t i;i != self->positionCounter;i++){
        if(equals(self->objectArray[i],value)){have = true;}
>>>>>>> e510a67964aa023f6f16a13ca204672f04c81530
    }
    return have;
}

int32_t simpleList_set_int32_int32_object(simpleList* self,int32_t position,object value){
    if(position > self->valueCounter || position < 0){
        return -(position);
    }
    if(position<self->positionCounter){
        free(self->objectArray[position]);
    }
    self->objectArray[position] = value;
    return position;
}

object simpleList_get_object_void(simpleList* self){
    return self->objectArray[self->positionCounter-1];
}

object simpleList_get_object_int32(simpleList* self,int32_t position){
    if(position > (self->positionCounter - 1) || position < 0){
        return NULL;
    }
    return self->objectArray[position];
}

bool simpleList_delete_bool_int32(simpleList* self,int32_t position){
    if(position > (self->positionCounter - 1) || position < 0){
        return false;
    }
    object* tmpPtr = malloc((self->valueCounter+1)*sizeof(object));
    int32_t offSet = 0;
    for(int32_t i = 0;i != self->positionCounter;i++){
        if(i == position){
            offSet++;
            free(self->objectArray[i]);
            continue;
        }
        tmpPtr[i-offSet] = self->objectArray[i];
    }
    free(self->objectArray);
    self->objectArray = tmpPtr;
    self->positionCounter--;
    return true;
}

bool simpleList_deleteFromTo_bool_int32(simpleList* self,int32_t from,int32_t to){
    if(from>=to){
        return false;
    }
    if(from<0){
        return false;
    }
    if(to > (self->positionCounter - 1)){
        return false;
    }
    object* tmpPtr = malloc((self->valueCounter+1)*sizeof(object));
    int32_t offSet = 0;
    for(int32_t i = 0;i != self->positionCounter;i++){
        if(i >= from || i <= to){
            offSet++;
            free(self->objectArray[i]);
            continue;
        }
        tmpPtr[i-offSet] = self->objectArray[i];
    }
    free(self->objectArray);
    self->objectArray = tmpPtr;
    self->positionCounter = self->positionCounter - (to-from+1);
    return true;
}

void simpleList_close(simpleList* self){
    for(int32_t i = 0;i < self->positionCounter;i++){
        free(self->objectArray[i]);
    }
    free(self->objectArray);
    free(self);
}

void simpleList_clear_void_void(simpleList* self){
    simpleList * tmpPtr = simpleList_init_int32(self->valueCounter+1);
    simpleList_close(self);
    self = tmpPtr;
}

object simpleList_pop_object_void(simpleList* self){
    object tmp = simpleList_get_object_void(self);
    simpleList_delete_bool_int32(self,self->positionCounter-1);
    return tmp;
}

object simpleList_pop_object_int32(simpleList* self,int32_t position){
    object tmp = simpleList_get_object_int32(self,position);
    simpleList_delete_bool_int32(self,position);
    return tmp;
}

//end impl
