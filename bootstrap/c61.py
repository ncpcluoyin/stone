#preCompiler for stone

import marcos
import messages
from messages import *
import typeDefine
import options
from os import path
from pathlib import Path
import copy

#TODO preCompile stone file

class preCompilerReader:
    def __init__(self,filePath:str):
        try:
            open(filePath,"r")
        except:
            output("error is thrown while opening file "+filePath)
            exit(1)
        self.filePathAbs = path.abspath(filePath)
        self.__spiltBlocks()
    def __spiltBlocks(self):
        linesUnSpilt = Path(self.filePathAbs).read_text()
        linesSpilt = linesUnSpilt.splitlines()
        for tmp_oneLine in linesSpilt:
            tmp_oneLineSpiltIntoBlocks = str.split(tmp_oneLine," ")
            if tmp_oneLineSpiltIntoBlocks[0] == "define":
                if tmp_oneLineSpiltIntoBlocks[1] == "marco":
                    marcoName = tmp_oneLineSpiltIntoBlocks[2]
                    if not marcos.marcoNameIsOK(marcoName):
                        output("name "+marcoName+" is not OK")
                        exit(1)
                    params = dict()
                    tmpList = copy.deepcopy(tmp_oneLineSpiltIntoBlocks)
                    del tmpList[0]
                    del tmpList[0]
                    del tmpList[0]
                    if not list(tmpList[0])[0] == "[":
                        output("before name "+marcoName+ ",you should define formal parameters in a [.....]")
                        exit(1)
                    for values in tmpList:
                        #TODO
                        output("TODO")
                else:
                    output("unrecognized define type "+tmp_oneLineSpiltIntoBlocks[1])
                    exit(1)
            else:
                output("unrecognized marco "+tmp_oneLineSpiltIntoBlocks[0])