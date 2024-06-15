import json

 
OPCODE_LIST = "opcodes.json"
OUTPUT = "./fn.c"

with open(OPCODE_LIST, "r") as f:
    data = json.load(f)

with open(OUTPUT, "w") as o:
    unprefixed = data["unprefixed"]
   
    for op in unprefixed:
        r = unprefixed[op]
        operands = r["operands"] 
        size = r["bytes"] - 1
        
        ops = []
        for operand in operands:
            if "name" in operand:
                ops.append(operand["name"])
        if r["mnemonic"] == "LD" and len(ops) == 2 and ops[0] == "HL" and ops[1][0] == "n": 
            mnemonic = r["mnemonic"] 
            name = f"{mnemonic.lower()}_{ops[0].lower()}_{ops[1].lower()}"
            a = "a8" if size == 1 else "a16"
            header = f"void " + name + "() {\n" 
            body = f"   write8(registers.{ops[0].lower()}, {a});\n" 
            end = "}\n"
            _ = o.write(header)
            _ = o.write(body)
            _ = o.write(end)
