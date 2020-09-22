#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    n_bytes = 0
    for b in data:
        b = bin(b).replace('0b', '').rjust(8, '0')
        if n_bytes != 0:
            n_bytes -= 1
            if not n_bytes:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        elif b[0] == '1':
                n_bytes = len(b.split('0')[0]) - 1
    return True
