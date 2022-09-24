import pathlib
import argparse

parser = argparse.ArgumentParser(prog="update_text", description="Update Text")

parser.add_argument("file",
                    type=argparse.FileType("r"),
                    help="The text file to update",
                    )

path = pathlib.Path("./src/text.cpp")

if not path.exists() or not path.is_file():
    print("Please run this file from its own folder")
    exit(1)

args = parser.parse_args()

source_text = None

try:
    source_text = args.file.readlines()
except Exception as e:
    print("Error:", e)
    exit(1)

out_text = """
// DO NOT MODIFY BY HAND

const char* text[100] = {
"""

print(source_text)

if len(source_text) > 100:
    print("ERROR: Too much lines")
    exit(1)

for i in source_text:
    ir = i
    if i.endswith("\n"):
        ir = i[:-1]
    if len(ir) > 46:
        print("ERROR: Lines are two long")
        exit(1)

    out_text += f"        \"{ir}\",\n"

out_text += "};"

# print(out_text)
path.write_text(out_text)
