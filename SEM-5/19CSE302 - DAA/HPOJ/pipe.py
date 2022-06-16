totalhouse = 0
totalpipes = 0
pipesendvertex = [0]*1100

pipemeasure = [0]*1100

pipefirstvertex = [0]*1100

fo1 = []
fo2 = []
fo3 = []

lassume = 0


def approach(qa):
    global lassume
    if (pipefirstvertex[qa] == 0):
        return qa
    if (pipemeasure[qa] < lassume):
        lassume = pipemeasure[qa]
    return approach(pipefirstvertex[qa])


def operationperform(decay):
    global lassume
    gh = 0
    while (gh < totalpipes):
        z = decay[gh][0]
        x = decay[gh][1]
        c = decay[gh][2]

        pipefirstvertex[z] = x
        pipemeasure[z] = c
        pipesendvertex[x] = z
        gh = gh + 1
    fo1 = []
    fo2 = []
    fo3 = []

    for v in range(1, totalhouse + 1):
        if (pipesendvertex[v] == 0 and pipefirstvertex[v]):

            lassume = 1000
            qa = approach(v)

            fo1.append(v)
            fo2.append(qa)
            fo3.append(lassume)
    print(len(fo1))
    for v in range(len(fo1)):
        print(fo1[v], fo2[v], fo3[v])


totalhouse = int(input())
totalpipes = int(input())
decay = []
for k in range(0, totalpipes):
    decay.append([int(v) for v in input().split(',')])

operationperform(decay)
