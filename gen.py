import json

with open("opcodes.json", "r") as j:
    data = json.load(j)["unprefixed"]

with open("generated.c", "w") as f:
    _ = f.write("char *instructions[256] = {\n")

    for op in range(255):
        o = hex(op)
        if len(o) == 3:
            o = "0x0" + o[2]
            print(o)
        n = ""
        if o in data:
            n = data[o]["mnemonic"]
            if "operand1" in data[o]:
                n += " " + data[o]["operand1"]
            if "operand2" in data[o]:
                n += " " + data[o]["operand2"]
        else:
            n = "UNKNOWN"

        _ = f.write(f'  "{n}",\n')
        
    _ = f.write("};")
