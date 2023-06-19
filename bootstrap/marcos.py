

preDefineMarcos = (
    "define",
    "marco"
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