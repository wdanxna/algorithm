
def second_largest(list):
  largest = 0# 1
  second = 0# 1
  for i in list:# *n
    if i > largest: # 1
      largest = i# 1

  for i in list: # *n
    if not i==largest and i > second: # 4
      second = i # 1

  #1 + 1 + (1+1)*n + (1+4)*n = 7n+2
  return second



def second_largest_2(list):
  length = len(list)
  if length == 1:
    return 0, list[0]
  else:
    lsec,lmax = second_largest_2(list[:length/2])
    rsec,rmax = second_largest_2(list[length/2:])
    mix = min(lmax,rmax)
    return max(lsec, rsec, mix), max(lmax,rmax)


def second_largest3(list):
  global count
  length = len(list)
  if length == 1:
    return 0, list[0]
  elif length == 2:
    count = count + 1
    if list[0] < list[1]:
        return list[0], list[1]
    else:
        return list[1], list[0]
  else:
    lsec,lmax = second_largest3(list[:length/2])
    rsec,rmax = second_largest3(list[length/2:])
    count = count + 2
    if (lmax < rmax):
        if (lmax < rsec):
            return rsec, rmax
        else:
            return lmax, rmax
    else:
        if (rmax < lsec):
            return lsec, lmax
        else:
            return rmax, lmax

count = 0;
a = [i for i in range(8)]
print second_largest3(a)
print count
print 3*len(a)/2-2
