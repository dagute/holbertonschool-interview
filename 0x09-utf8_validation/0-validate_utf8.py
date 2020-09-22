#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    n_bytes = 0
    if not data or len(data) == 0:
        return True
    for b in data:
        m = 1 << 7
        if not n_bytes:
            while m & b:
                n_bytes += 1
                m >>= 1
        b = bin(b).replace('0b', '').rjust(8, '0')
        if n_bytes != 0:
            n_bytes -= 1
            if not b.startswith('10'):
                return False
            if not n_bytes:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        elif b[0] == '1':
                n_bytes = len(b.split('0')[0]) - 1
    return True
