#this file read configs for other modules
import json
from pathlib import Path
from os import path

def read(name:str):
    return json.loads(Path(path.dirname(__file__) + "/" + name + ".json").read_text())

#preReads

configs_json = read("configs")
configures = dict()

for x in configs_json:
    configures[x] = read(x)