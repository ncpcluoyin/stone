import options
from typeDefine import *
import sys
def compileFormatted(v:str):
    buffer = list()
    lines = v.splitlines()
    def variableBasicTypeDefine(name:str,Type:int,level:int):
        tmp = str()
        for x in range(level):
            tmp = tmp + "\t"
        tmp = tmp + basicTypeConvertToCType(Type) + "\t" + name + ";"
        buffer.append(tmp)
    def structDefine(values:dict,level:int):
        tmp = str()
        for x in range(level):
            tmp = tmp + "\t"
        tmp = tmp + "typedef\tstruct{\n"
        for key in list(values.keys()):
            for x in range(level+1):
                tmp = tmp + "\t"
            tmp = tmp + basicTypeConvertToCType(values[key]) + "\t" + key + ";\n"