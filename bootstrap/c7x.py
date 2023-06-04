import options
from messages import *
from typeDefine import *
import sys
if __name__ == "__main__":
    if "quiet" in sys.argv:
        messages.out = False
    output("relix c7x")

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