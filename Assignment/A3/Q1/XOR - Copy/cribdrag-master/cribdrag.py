#!/usr/bin/python

from binascii import unhexlify
 
ciphertexts = ["1d0645116b5d45450606457431071c000f54071317000a04014e540e551d06091d1b1e45050011114122041a03050508171d5300040b4500010b47531505045459010410450f0755060d160035041a091b004762161c014716483d131d000e411a4155240b570b1911524211480149100c0612061510075a493b0645540c000642084e060b4e10060915130f1b4c12410749030a58000201094d0c0643061109021c445313160f090a53121a4c4b4f0e0a170003170f1d4e1a4e1d010032011d1d0b0411110041455157580e412f44530507174d044c03465413131407070445020b4e4500330c170d4d0b110100524a5d52472a4f261b45570e03450f0e1c02450b46491a48504c1859454e0755004f540504490249020c4e064f1d000800110416441a4e460d07070a051a"]
 
 
def strxor(a, b):     # xor two strings of different lengths
    if len(a) > len(b):
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])
 
 
def main(idx):
    x = unhexlify(ciphertexts[idx])
    # crib = raw_input("Enter Crib:>")
    crib = "The Severn Tunnel had been authorised by Parliament in the same year as the Severn Bridge Railway. However the construction took a considerable time, and it opened fully to goods trains in September 1886 and for all traffic on 1 December 1886.^ The opening of that line to main line standards finally"
    print "Crib\n~%s~" % crib
 
    # Crib Drag
    for i in range(len(x)):
        z = x[i:]
        print "\n[%d]" % i
        print "%s" % strxor(z, crib)
 
 
if __name__ == "__main__":
    # stream_cipher_attack()
    for idx, cipher in enumerate(ciphertexts):
        main(idx)
 
    # main(9)
