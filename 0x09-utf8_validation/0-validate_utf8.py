#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    n_bytes = 0
    for c in data:
        m = 1 << 7
        if not n_bytes:
            while (m & c):
                n_bytes += 1
                m >>= 1
            if not n_bytes:
                continue
            if (c >> 5) == 6:
                n_bytes = 1
            elif (c >> 4) == 14:
                n_bytes = 2
            elif (c >> 3) == 30:
                n_bytes = 3
            elif (c >> 7):
                return False
        else:
            if (c >> 6) != 2:
                return False
        n_bytes -= 1
    return n_bytes == 0
