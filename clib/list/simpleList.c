#include "simpleList.h"
#include <stdint.h>
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

bool simpleList_have_bool_object(simpleList* self,bool equals(object,object),object value){
    bool have = false;
    for(int32_t i;i != self->positionCounter;i++){
        if(equals(self->objectArray[i],value)){have = true;}
    }
    return have;
}

int32_t simpleList_set_int32_int32_object(simpleList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return -(position);
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + postion + 1;
    }
    free(self->objectArray[position]);
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

void simpleList_close(simpleList* self){
    for(int32_t i = 0;i < self->positionCounter;i++){
        free(self->objectArray[i]);
    }
    free(self->objectArray);
    free(self);
}

extern object deleteButNotFree(simpleList*,int32_t);

object simpleList_pop_object_void(simpleList* self){
    object tmp = deleteButNotFree(self,self->positionCounter-1);
    return tmp;
}

object simpleList_pop_object_int32(simpleList* self,int32_t position){
    object tmp = deleteButNotFree(self,position);
    return tmp;
}

object deleteButNotFree(simpleList* self,int32_t position){
	object* tmpPtr = malloc((self->valueCounter+1)*sizeof(object));
	int32_t offSet = 0;
	object resualt = NULL;
	for(int32_t i = 0;i != self->positionCounter;i++){
		if(i == position){
			offSet++;
			//free(self->objectArray[i])
			resualt = self->objectArray[i];
			continue;
		}
		tmpPtr[i-offSet] = self->objectArray[i];
	}
	free(self->objectArray);
	self->objectArray = tmpPtr;
	self->positionCounter--;
	return resualt;
}

//end impl
