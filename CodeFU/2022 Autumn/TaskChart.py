class TaskChart:
  def findMostHardworking(self, hoursSpent):
    ls = []
    for entry in hoursSpent:
      en = list(map(int, entry.split(';')))
      ls.append((en[1], en[0]))
    ls.sort()
    last = 0
    best = 0
    ans = 0
    acc = [0 for i in range(20)]
    for en in ls:
      diff = en[0] - last
      acc[en[1]] += diff
      last = en[0]
    for i in range(20):
        if acc[i] > best:
            best = acc[i]
            ans = i
    return ans
