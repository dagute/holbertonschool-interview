#!/usr/bin/python3
"""Log parsing """

if __name__ == '__main__':

    import sys

    total_size = 0
    counter = 0
    entry_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    s = {k: 0 for k in entry_codes}

    def printing(s: dict, total_size: int) -> None:
        """reads stdin line by line and computes metrics"""
        print("File size: {:d}".format(total_size))
        for k, v in sorted(s.items()):
            if v:
                print("{}: {}".format(k, v))

    try:
        for line in sys.stdin:
            counter += 1
            data = line.split()
            try:
                code = data[-2]
                if code in s:
                    s[code] += 1
            except BaseException:
                pass
            try:
                total_size += int(data[-1])
            except BaseException:
                pass
            if counter % 10 == 0:
                printing(s, total_size)
        printing(s, total_size)
    except KeyboardInterrupt:
        printing(s, total_size)
        raise
