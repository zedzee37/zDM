import json

# struct instruction {
#   
# 
# 
# };
#

OPCODE_LIST = "opcodes2.json"
OUTPUT = "./t.h"

with open(OPCODE_LIST, "r") as f:
    data = json.load(f)

with open(OUTPUT, "w") as w:
    unprefixed = data["unprefixed"]

    _ = w.write("struct instruction instructions[256] = {\n")

    for op in unprefixed:
        r = unprefixed[op]
        size = r["length"] - 1
        mnemonic = r["mnemonic"]
        if "operand1" in r:
           mnemonic += " " + r["operand1"] 
        if "operand2" in r:
            mnemonic += " " + r["operand2"]
        s = "\"{0}\", {1}, NULL".format(mnemonic, size) 
        space_count = 13 - len(mnemonic)
        spaces = " " * space_count
        opn = op[0:2] + op[2:len(op) + 1].upper()
        _ = w.write("   {" + s + "}," + spaces + "// " + opn + " \n")
    _ = w.write("}")


