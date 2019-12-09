import subprocess

def generate_keys():
    keys = str(subprocess.check_output(["GenKey.exe"]))
    print(keys)
    keys_lst = keys.split("\\n")
    n = int(keys_lst[0][2:-2])
    e = int(keys_lst[1][:-2])
    d = int(keys_lst[2][:-2])
    return n,e,d


print(generate_keys())