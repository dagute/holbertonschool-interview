#!/usr/bin/python3
import sys
"""N queens puzzle"""


class Queens:
    """class Queens"""
    def validate(self, x, y, cols):
        """column validity"""
        for j in range(x):
            if cols[j] == y:
                return False
            if abs(cols[j] - y) == (x - j):
                return False
        return True

    def placing(self, row, N, cols):
        """finding all posible solutions """
        if row == N:
            print("[", end="")
            for i in range(N):
                print("[{}, {}]".format(i, cols[i]), end="")
                if i < N - 1:
                    print(", ", end="")
            print("]")
            return
        for i in range(N):
            if self.validate(row, i, cols):
                cols[row] = i
                self.placing(row+1, N, cols)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    backtrack = Queens()
    backtrack.placing(0, N, [None for i in range(N)])
