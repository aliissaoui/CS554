import os 
import argparse

parser = argparse.ArgumentParser(description='Sort file.')
parser.add_argument('file', type=str, help="file nem")
args = parser.parse_args()

filename = args.file

with open(filename) as f:
    content = f.readlines()
    
content = [x.strip() for x in content] 

content.sort(key=lambda x: int(x.split()[0]))

# Delete file if exists
if os.path.exists("sort_p_file.txt"):
    os.remove("sort_p_file.txt")

f = open("sort_p_file.txt", "a")

for line in content:
    f.write(line+'\n')

f.close()
