#this file is the backEnd of stone compiler

import typeDefine
import marcos

class backEnd(object):
    def __init__(self):
        self.cText = "//created by relix stone;"
        self.functions = dict()
    def add(self,value):
        self.cText = self.cText + "\n" +value + ";"
    def addGlobalVariable(self,Type,name):
        self.add(typeDefine.basicTypeConvertToCType(Type) + " " + name)
    def externGlobalVariable(self,Type,name):
        self.add("extern "+typeDefine.basicTypeConvertToCType(Type) + " " + name)
    def nothing(self,v):
        self.add("//"+v)
    def addFunction(self,function):
        if function.name in self.functions.keys():
            pass
        def a(b):
            self.cText = self.cText + "\n" + b
        args = str()
        isFirst = True
        for arg in function.args.keys():
            if isFirst:
                args = typeDefine.basicTypeConvertToCType(functions.args[arg]) + " "+ arg
                isFirst = False
                continue
            args = args + "," + typeDefine.basicTypeConvertToCType(function.args[arg]) + " " + arg
        a(typeDefine.basicTypeConvertToCType(function.type)+" "+function.name + "("+ args +")" + " {")
        a(function.cText)
        a("}")
    def addStructure(self,name,valueDict):
        def a(b):
            self.cText = self.cText + "\n" + b
        a("typedef struct {")
        for key in valueDict.keys():
            self.add("\t"+typeDefine.basicTypeConvertToCType(key)+" "+valueDict[key])
        a("} "+ name+";")
    def addEnum(self,eList):
        counter = int()
        for v in eList:
            self.add("#define "+v+" "+str(counter))
            counter = counter + 1


class block(object):
    def __init__(self,level):
        self.cText = str()
        self.level = level
    def add(self,v):
        a = str()
        for x in range(self.level):
            a = a + "\t"
        self.cText = self.cText + "\n" +a+ v + ";"
    def addBlock(self,v):
        self.cText = self.cText + "\n" +v
    def subBlock(self):
        return block(self.level + 1)

class function(block):
    def __init__(self,name,returnType,args):
        super(self,1)
        self.name = name
        self.type = returnType
        self.args = args