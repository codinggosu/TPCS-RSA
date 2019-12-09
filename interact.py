import subprocess


# python function to interact with exe and get private, public keys
def generate_keys():
    keys = str(subprocess.check_output(["KeyGen.exe"]))
    keys_lst = keys.split("\\n")
    n = int(keys_lst[0][2:-2])
    e = int(keys_lst[1][:-2])
    d = int(keys_lst[2][:-2])
    return n,e,d


# testing generate_keys()
n, e, d = generate_keys()
print("n, e, d" ,n,e,d)
# message = pow(12342341234, e, n)
# print(message)
# print(pow(message, d, n))


def encrypt(message, n, e):
    print("encrypt", n, e, d)
    cyphertext = str(subprocess.check_output([
        "Encrypt.exe", 
        str(n), 
        str(message), 
        str(e)]))
    return cyphertext.split(":")[1][:-1]

# testing encrypt()
encrypted_message = encrypt(8812348890, n, e)
print(encrypted_message , 'is the e message')


def decrypt(cyphertext, n, d):
    print("decrypt", n, e, d)
    plaintext = str(subprocess.check_output([
        "Decrypt.exe",
        str(n),
        str(cyphertext),
        str(d)]))
    return plaintext.split(":")[1][:-1]

decrypted_message = decrypt(encrypted_message, n, d)
print(decrypted_message, 'is the d message')


