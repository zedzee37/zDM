import json

 
OPCODE_LIST = "opcodes.json"
OUTPUT = "./fn.c"

with open(OPCODE_LIST, "r") as f:
    data = json.load(f)

with open(OUTPUT, "w") as o:
    unprefixed = data["unprefixed"]
   
    for op in unprefixed:
        d = unprefixed[op]
        if "mnemonic" not in d:
            continue
        mnenonic = d["mnemonic"]
        op1 = None
        op2 = None
        
        if "operand1" in d:
            op1 = d["operand1"].lower()
        if "operand2" in d:
            op2 = d["operand2"].lower()

        if op2 and op1 and mnenonic == "sub" and len(op1) == 1 and len(op2) == 1:
            fn_name = f"void sub_{op1}_{op2}()"
            fn_body = f"    registers.{op1} += registers.{op2};"
            
            _ = o.write(fn_name + " {\n")
            _ = o.write(fn_body + "\n")
            _ = o.write("}\n")

