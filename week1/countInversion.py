def file_to_array(filename):
    f = open(filename)
    strs = f.readlines()
    arr = [int(elem) for elem in strs]
    return arr


def count_split(l1, l2):
    l = len(l1) + len(l2)
    ol = []
    oc = 0
    i = 0
    j = 0
    for k in range(0, l):
        if j > len(l2) - 1 or (i < len(l1) and l1[i] < l2[j]):
            ol.append(l1[i])
            i += 1
        else:
            ol.append(l2[j])
            j += 1
            if len(l1) - i > 0:
                oc = oc + len(l1) - i
    return ol, oc

def count_inversion(array):
    length = len(array)
    if length < 2:
        return array,0
    else:
        la,ca = count_inversion(array[:length/2])
        lb,cb = count_inversion(array[length/2:])
        ls,cs = count_split(la,lb)
        return (ls, ca+cb+cs)

print count_inversion(file_to_array('IntegerArray.txt'))[1]