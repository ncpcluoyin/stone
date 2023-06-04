import options
from messages import *
from marcos import *
import sys
if __name__ == "__main__":
    if "quiet" in sys.argv:
        messages.out = False
    output("relix lawyer")

#def namespace_gen(obj:namespace__):
#TODO