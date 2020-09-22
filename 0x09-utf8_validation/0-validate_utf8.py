#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    n_bytes = 0
    for c in data:
        m = 1 << 7
        if n_bytes == 0:
            while (m & c):
                n_bytes += 1
                m >>= 1
            if n_bytes == 0:
                continue
                if (c >> 5) == 0b110:
                    n_bytes = 1
                elif (c >> 4) == 0b1110:
                    n_bytes = 2
                elif (c >> 3) == 0b11110:
                    n_bytes = 3
                elif (c >> 7):
                    return False
        else:
            if (c >> 6) != 0b10:
                return False
            n_bytes -= 1
    return n_bytes == 0
