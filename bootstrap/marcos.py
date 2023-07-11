#define marcos

preDefineMarcos = (
    "if",
    "loop",
    "while",
    "for",
    "in",
    "else",
    "elif"#TODO
)

def isPreDefineMarco(s:str):
    if s in preDefineMarcos:
        return True
    else:
        return False

#check functions
def isNameOK(name:str):
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
