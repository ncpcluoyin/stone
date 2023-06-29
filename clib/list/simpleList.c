#include "simpleList.h"
//init functions
simpleList * simpleList_init_void(){
    simpleList* self = (simpleList*) malloc(sizeof(simpleList));
    self->valueCounter = simpleListDefaultInitSize - 1;
    self->positionCounter = 0;
    self->objectArray = malloc(sizeof(object) * simpleListDefaultInitSize);
    return self;
}
simpleList * simpleList_init_int32(int32_t _initSize){
    int32_t initSize = _initSize;
    if(initSize < simpleListDefaultInitSize){
        initSize = simpleListDefaultInitSize;
    }
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
	    position = self->valueCounter + position + 1;
    }
    free(self->objectArray[position]);
    self->objectArray[position] = value;
    return position;
}

object simpleList_get_object_void(simpleList* self){
    return self->objectArray[self->positionCounter-1];
}

object simpleList_get_object_int32(simpleList* self,int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
    return self->objectArray[position];
}

bool simpleList_delete_bool_int32(simpleList* self,int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return false;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
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

object simpleList_pop_object_void(simpleList* self){
    if(self->positionCounter == 0){
        return NULL;
    }
	object result = self->objectArray[self->positionCounter-1];
	self->positionCounter--;
	return result;
}

object simpleList_pop_object_int32(simpleList* self,int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
	object* tmpPtr = malloc((self->valueCounter+1)*sizeof(object));
	int32_t offSet = 0;
	object result = NULL;
	for(int32_t i = 0;i != self->positionCounter;i++){
		if(i == position){
			offSet++;
			//free(self->objectArray[i])
			result = self->objectArray[i];
			continue;
		}
		tmpPtr[i-offSet] = self->objectArray[i];
	}
	free(self->objectArray);
	self->objectArray = tmpPtr;
	self->positionCounter--;
	return result;
}

void simpleList_delete_bool_void(simpleList *self){
    if(self->positionCounter == 0){
        return;
    }
	free(self->objectArray[self->positionCounter-1]);
	self->positionCounter--;
	return;
}

object simpleList_exchange_object_int32_object(simpleList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
    object tmp = self->objectArray[position];
    self->objectArray[position] = value;
    return tmp;
}

bool simpleList_exchange_bool_int32_int32(simpleList* self,int32_t _position1,int32_t _position2){
    int32_t position1 = _position1;
    int32_t position2 = _position2;
    if(position1 > self->positionCounter-1){
        return false;
    }
    if(position2 > self->positionCounter-1){
        return false;
    }
    if(position1 < 0){
	    if(-(position1) > self->valueCounter+1){
		    return false;
	    }
	    position1 = self->valueCounter + position1 + 1;
    }
    if(position2 < 0){
	    if(-(position2) > self->valueCounter+1){
		    return false;
	    }
	    position2 = self->valueCounter + position2 + 1;
    }
    object tmp = self->objectArray[position1];
    self->objectArray[position1] = self->objectArray[position2];
    self->objectArray[position2] = tmp;
    return true;
}

int32_t simpleList_insert_int32_int32_object(simpleList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return -(position);
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
    }
    int32_t tmp_positionCounter = self->positionCounter;
    simpleList* array = simpleList_init_int32(tmp_positionCounter - position);
    for(int32_t i = 0;i < tmp_positionCounter - position;i++){
	    simpleList_append_int32_object(array,simpleList_pop_object_void(self));
    }
    simpleList_append_int32_object(self, value);
    for(int32_t i = 0;i < tmp_positionCounter - position;i++){
	    simpleList_append_int32_object(self, simpleList_pop_object_void(array));
    }
    simpleList_close(array);
    return position;
}

//end impl
