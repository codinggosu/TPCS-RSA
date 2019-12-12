import subprocess
import random

# python function to interact with exe and get private, public keys
def generate_keys():
    keys = str(subprocess.check_output(["KeyGen.exe"]))
    keys_lst = keys.split("\\n")
    n = int(keys_lst[0][2:-2])
    e = int(keys_lst[1][:-2])
    d = int(keys_lst[2][:-2])
    return n,e,d

def generate_big_keys():
    keys = str(subprocess.check_output(["BigKeyGen.exe"]))
    keys_lst = keys.split("\\n")
    n = int(keys_lst[0][2:-2])
    e = int(keys_lst[1][:-2])
    d = int(keys_lst[2][:-2])
    return n,e,d

# testing generate_keys()
# print("n, e, d" ,n,e,d)
# message = pow(12342341234, e, n)
# print(message)
# print(pow(message, d, n))


def encrypt(message, n, e):
    # print("encrypt", n, e, d)
    cyphertext = str(subprocess.check_output([
        "Encrypt.exe", 
        str(n), 
        str(message), 
        str(e)]))
    return cyphertext.split(":")[1][:-1]

# testing encrypt()
# encrypted_message = encrypt(8812348890, n, e)
# print(encrypted_message , 'is the e message')


def decrypt(cyphertext, n, d):
    # print("decrypt", n, e, d)
    plaintext = str(subprocess.check_output([
        "Decrypt.exe",
        str(n),
        str(cyphertext),
        str(d)]))
    return plaintext.split(":")[1][:-1]
# decrypted_message = decrypt(encrypted_message, n, d)
# print(decrypted_message, 'is the d message')


def primegen():
    prime = str(subprocess.check_output(["PrimeGen.exe"]))
    return prime[2:-1]
    

sample_messages = [
    1234,
    5678,
    23579,
    23571113,
    11111111,
    22222222,
    33333333,
]

print("\n\n\n\n\n")
pt = print(
"""Hello! Welcome to the RSA demo, this demo will show you key generation,
encryption/decyption, and generate large primes for you!
First let me generate some keys \n \n \n
""")




n, e, d = generate_big_keys()
print(f"Keys have been generated for you! \n They are N:{n} \n e:{e} \n and your private key: {d} !")
print(f"You can now do a few things 1. receive sample messages, 2. Send messages 3. decypt messages 4. Just see a large prime, 5. Exit")

choice = int(input("Choose an option!"))
while(choice != 5):
    if choice == 1:
        print("you have chosen 1, receive sample message")
        print("you will receive an encrypted text and a decrypted version")
        pt = random.choice(sample_messages)
        print("The message in plaintext")
        print(pt)
        print("The message in cyphertext")
        print(encrypt(int(pt),n,e))
    elif choice == 2:
        print("you have chosen 2, send message")
        m = input("Enter your message! Only ints please! ")
        print("The encrypted message")
        print(encrypt(int(m), n, e))
    elif choice == 3:
        print("you have chosen 3, decrypt message")
        ct = input("input the message you have received")
        decrypted = decrypt(ct, n, d)
        print(f"the decrypted message is : {decrypted} !! ")
    elif choice == 4:
        print("you have chosen 4, generate large prime")
        print("A large prime!")
        generated_prime = primegen()
        print(generated_prime)

    print(
        """Your Options are : 
        1. receive sample messages
        2. Send messages
        3. decypt messages
        4. Just see a large prime
        5. Exit:""")
    choice = int(input())

        
        
print(f"\n \n \n Thanks! Bye Bye!")

# https://www.numberempire.com/primenumbers.php