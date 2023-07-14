import sys,os
sys.path.append(os.path.dirname(__file__)+"/..")
import marcos
import config

class fProject(object):
    def __init__(self):
        self.files = list()
        #TODO

class fFile(object):
    def __init__(self,path:str,options:list):
        self.path = path
        self.options = options
        self.blocks = list()
    def append(self,v:fBlock):
        if v.usable == True:
            self.blocks.append(v)
            return True
        else:
            return False

class fBlock(object):
    def __init__(self):
        self.usable = False

class fClass(fBlock):
    def __init__(self):
        self.usable = True

class fFun(fBlock):
    def __init__(self):
        self.usable = True

class fField(fBlock):
    def __init__(self):
        self.usable = True

class step(object):
    pass

class arg():
    def __init__(self,_type,value):
        if not _type in config.configures["typeDefine"].keys():
            raise TypeError("unknown type "+_type)


class fCall(step):
    def __init__(self,callee:fFun,args:list):
        self.callee = callee
        self.args = config.configures