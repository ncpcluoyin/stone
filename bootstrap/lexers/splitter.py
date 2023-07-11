#split string into token stream

import json

returnDict = 0
returnJson = 1

def split(s:str,returnType:int = 0):
    result = dict()

    

    if returnType == returnDict:
        return result
    if returnType == returnJson:
        return json.dumps(result,indent=4)
    else:
        return result