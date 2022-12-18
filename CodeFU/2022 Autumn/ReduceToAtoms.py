class ReduceToAtoms:
    def countMoves(self, number, repetitions):
        S = ""
        for i in range(repetitions):
            S += number

        N = 0
        for i in range(len(S)):
            N *= 16
            if S[i] >= '0' and S[i] <= '9':
                N += ord(S[i]) - ord('0')
            else:
                N += 10 + ord(S[i]) - ord('a')

        ans = 0
        while (N > 0):
            if N & 1 == 0:
                N //= 2
            else:
                N -= 1
            ans += 1
        return ans
