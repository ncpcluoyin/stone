#this file is for something that will be run before preprocess

import marcos,copy

def convertToProcessObject(a:str):
    obj = marcos.file()
    splitResult = list()
    tmpList = list()
    counter = 0
    tmpCounter = 0
    isEmpty = True
    for x in list(a):
        if x == " " or x == "\n":
            if not isEmpty:
                tmpCounter = tmpCounter + 1
        elif x == ";":
            splitResult[counter] = tmpList
            tmpCounter = 0
            del tmpList
            tmpList = list()
            counter = counter + 1
        else:
            tmpList[tmpCounter] = tmpList[tmpCounter] + x
    checkResult = copy.deepcopy(splitResult)
    for x in range(len(splitResult)):
        value = splitResult[x]
        if marcos.marcoNameIsOK(value[0]):
            #so it may be a variable's name
            if value[1] == ":=" and len(value) == 3:
                #so it must be changing/creating the value of the variable
                if not value[0] in obj.variables.keys():
                    obj.variables[value[0]] = marcos.typeOf(value[2])


    return obj