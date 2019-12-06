# python program:
def prime(n):
    print("checking ", n)
    until = int(n ** 0.5 + 3)
    for i in range(3, until, 2):
            if n % i == 0:
                    print(n, 'is div by', i)
                    return False
    return n % 2 != 0



print(prime(1451))
print(prime(428640646032571816849859006098333984814463001448911))
# print(prime(428640646032571816849859006098220984814463001448911)) #this should take a really long time

