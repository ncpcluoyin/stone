#split string into token stream
import sys
import json
import os

sys.path.append(os.path.abspath(os.path.dirname(__file__) + "/.."))

from config import *

returnDict = 0
returnJson = 1

def split(s:str,returnType:int = 0):
    result = dict()

    buffer = s.replace("\n","")
    #TODO

    if returnType == returnDict:
        return result
    if returnType == returnJson:
        return json.dumps(result,indent=4)
    else:
        return result