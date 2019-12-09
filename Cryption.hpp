#ifndef CRYPTION_HPP_INCLUDED
#define CRYPTION_HPP_INCLUDED
#endif // CRYPTION_HPP_INCLUDED
#include "PrimeGen.hpp"
#include "ModuloInv.hpp"

/// class for encrypting and decrypting
template <class Number>
class Cryption{
public:
    /// public key n found by multiplying two large primes p and q
    Number public_n;
    /// public key e s.t e is coprime to totient and between range [1, totient],
    /// coprimality is guaranteed since 65537 is a prime that is 2 ^ 16 + 1 chosen for its
    /// ease of computation when used as an exponent
    Number public_e = 65537;


    /// function to generate n(publicN), totient, and d(private_key).
    /// for encrypting and decrypting internally, without printing keys to screen
    void generateKeys(){
        PrimeGen<Number> pg = PrimeGen<Number>();
        Number p = pg.generatePrime();
        Number q = pg.generatePrime();
        this->public_n = p * q;
        this->totient = (p-1) * (q-1);
        this->generatePrivateKey();
        std::cout << "n is " << public_n << " d is " << private_key << " e is " << public_e << "\n";
        // after n,d,e have been generated clear/overwrite p,q, and totient
        this->totient = 0;
        q = 0;
        p = 0;
    }


    /// function to generate n(publicN), t, and private key d
    /// prints n, e, and d to screen
    void generatePrintKeys(Number e = 65537){
        PrimeGen<Number> pg = PrimeGen<Number>();
        Number p = pg.generatePrime();
        Number q = pg.generatePrime();
        Number n = p * q;
        std::cout << n << "\n";
        std::cout << e << "\n";
        Number t = (p-1) * (q-1);
        this->generatePrintPrivateKey(t, e);
        // after n,d,e have been generated clear/overwrite p,q, and totient
        t = 0;
        q = 0;
        p = 0;
    }

    /// function to encrypt when e and n need to be generated
    /// @param[in] Number plaintext
    /// @param[out] Number cyphertext
    Number encrypt(Number plaintext){
        if (public_n)
            return customExpoMod(plaintext, this->public_e, this->public_n);
        else
            std::cout << "Keys not generated yet\n";
        return 0;
    }

    /// function to encrypt when e and n is provided by input
    /// @param[in] Number plaintext
    /// @param[out] Number cyphertext
    Number encrypt(Number n, Number plaintext, Number e=65537){
        return customExpoMod(plaintext, e, n);
    }


    /// function to decrypt when d and n need to be generated
    /// @param[in] Number cyphertext
    /// @param[out] Number plaintext
    Number decrypt(Number cyphertext){
        if (this->public_n)
            return customExpoMod(cyphertext, this->private_key, this->public_n);
        else
            std::cout << "Keys not generated yet\n";
        return 0;
    }

    /// function to decrypt when d and n is provided by input
    /// @param[in] Number cyphertext
    /// @param[out] Number plaintext
    Number decrypt(Number n, Number cyphertext, Number d){
        return customExpoMod(cyphertext, d, n);
    }

private:
    /// private key d
    Number private_key;
    /// product of q-1 and p-1
    Number totient;


    /// function to generate private key d when e is given as 65537
    /// calculated by some integer (k * totient + 1)/e, since ed = 1 (mod totient)
    void generatePrivateKey(Number e = 65537){
        //generate public key if it hasn't been done already
        if (! (this->public_n)) this->generateKeys();
        Number d = customModInverse(totient, e);
        this->private_key = d;
    }

    /// function to generate private key d when e is given as 65537
    /// calculated by some integer (k * totient + 1)/e, since ed = 1 (mod totient)
    /// prints the result to screen for outputting to subprocess
    /// @param[in] t: totient given by generatePrintKeys(),
    /// @param[in] e: defaulted to 65537
    void generatePrintPrivateKey(Number t, Number e = 65537){
        Number d = customModInverse(t, e);
        std::cout << d << "\n";
    }
};
