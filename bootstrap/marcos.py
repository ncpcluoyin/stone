#define marcos
import typeDefine

preDefineMarcos = (
    "if",
    "loop",
    "while",
    "for",
    "in",
    "else",
    "elif"#TODO
)

#check functions
def marcoNameIsOK(name:str):
    if name in preDefineMarcos:
        return False
    nameTurnIntoList = list(name)
    for x in range(10):
        if nameTurnIntoList[0] == str(x):
            return False
    if "!" in name:
        return False
    if "@" in name:
        return False
    if "#" in name:
        return False
    if "$" in name:
        return False
    if "%" in name:
        return False
    if "^" in name:
        return False
    if "&" in name:
        return False
    if "*" in name:
        return False
    if "(" in name:
        return False
    if ")" in name:
        return False
    if "[" in name:
        return False
    if "]" in name:
        return False
    if "{" in name:
        return False
    if "}" in name:
        return False
    if "\\" in name:
        return False
    if "|" in name:
        return False
    if "\"" in name:
        return False
    if "\'" in name:
        return False
    if ";" in name:
        return False
    if ":" in name:
        return False
    if "<" in name:
        return False
    if ">" in name:
        return False
    if "," in name:
        return False
    if "." in name:
        return False
    if "?" in name:
        return False
    if "~" in name:
        return False
    if "`" in name:
        return False
    if "-" in name:
        return False
    if "+" in name:
        return False
    if "=" in name:
        return False
    if "/" in name:
        return False
    return True
#end check functions

def isNumber(s):
    try:  # 如果能运行float(s)语句，返回True（字符串s是浮点数）
        float(s)
        return True
    except ValueError:  # ValueError为Python的一种标准异常，表示"传入无效的参数"
        pass  # 如果引发了ValueError这种异常，不做任何事情（pass：不做任何事情，一般用做占位语句）
    try:
        import unicodedata  # 处理ASCii码的包
        unicodedata.numeric(s)  # 把一个表示数字的字符串转换为浮点数返回的函数
        return True
    except (TypeError, ValueError):
        pass
    return False#摘自https://blog.csdn.net/m0_37622530/article/details/81289520

def typeOf(v:str):
    if list(v)[0] == "\"" and list(v)[-1] == "\"":
        return typeDefine.typeString
    if isNumber(v):
        pass