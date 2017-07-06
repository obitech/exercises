#!/usr/bin/python3
# cyclic_codes.py - Error detection of cyclic codes

def encode(matrix, code):
    # first digit of code * first row of generator matrix
    out = int(code[0]) * int(matrix[0], 2)

    # next digits of code * next rows of generator matrix
    for row in range(1, len(code)):
        tmp = int(code[row]) * int("{0:d}".format(int(matrix[row], 2)))
        out = out ^ tmp
        print(code[row], tmp, out)

    # Use 0 as fill char, first 3 bits are message, rest is for error detection
    return "{0:0>6b}".format(out)

def code_is_correct(matrix, code):
    out = []
    tmp = 0

    # Multiply code vector with matrix rows (multiply digits, add(XOR) result)
    for row in range(len(matrix)):
        for x in range(len(code)):
            tmp = tmp ^ (int(matrix[row][x]) * int(code[x]))
        out.append(tmp)

    if out[len(out) - 1] == 0:
        return True
    else:
        return False

def get_bin(digits, choice):
    while True:
        inp = input(f"Please enter a {digits} digit binary you want to {choice}: ")

        if (len(inp) != digits):
            continue

        for x in inp:
            if int(x) < 0 or int(x) > 1:
                continue

        return inp

if __name__ == "__main__":
    # Generator matrix
    gen = ["100011",
            "010101",
            "001110"]

    # "Mirrored" generator matrix for error detection
    inv_gen = ["011100",
                "101010",
                "110001"]

    while True:
        print("1 - Encode\n2 - Check for errors\n3 - Exit")
        inp = input("> ")

        if inp == '1':
            binary = get_bin(3, "encode")
            result = encode(gen, binary)
            print(f"{binary} -> {result}\n")
        elif inp == '2':
            binary = get_bin(6, "decode")
            result = code_is_correct(inv_gen, binary)
            if result:
                print(f"The code {binary} is correct.\n")
            else:
                print(f"The code {binary} is not correct.\n")
        elif inp == '3':
            break
        else:
            print("Invalid choice.\n")


