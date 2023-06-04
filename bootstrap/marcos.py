from messages import *

#define processing class

#enum
marco_block_undefine = 1145141919810
marco_namespace = 0
marco_class = 1
marco_function =2

#define processing father class
#class block(object):
#    def __init__(self):
#        #create a list to storage objects
#        self.objList = list()
#        self.blockType = marco_block_undefine
#        self.blockName = str()
#    def append(self,obj:block):
#        self.objList.append(obj)
#    def toList(self):
#        return self.objList

#define processing son class
#class namespace__(block):
#    def __init__(self):
#        super(namespace__, self).__init__()
#        self.blockType = marco_namespace
#        self.classes = list()
#        self.namespaces = list()
#        self.functions = list()
#        self.__split()
#    def __split(self):
#        for obj in self.objList.toList():
#            if obj.blockType == marco_class:
#                self.classes.append(obj)
#            if obj.blockType == marco_namespace:
#                self.namespaces.append(obj)
#            if obj.blockType == marco_function:
#                self.functions.append(obj)
#            if obj.blockType == marco_block_undefine:
#                output()#
#
#class class__(block):
#    def __init__(self):
#        super(class__, self).__init__()
#        self.blockType = marco_class
#        self.classes = list()
#        self.functions = list()
#class function__(block):
#    def __init__(self):
#        super(function__, self).__init__()
#        self.blockType = marco_function
#        self.classes = list()
#        self.functions = list()