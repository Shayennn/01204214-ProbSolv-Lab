import random

n = 100000

lon = [_ for _ in range(1, 1000001)]
random.shuffle(lon)

f = open('test_trains.txt', 'w')
f.write(str(n))
f.write('\n')
for i in range(n):
    if random.random() > 0:
        f.write('N ' + str(lon[i]) + ' '+str(random.randint(1, 100000))+'\n')
    else:
        f.write('M ' + str(random.randint(0, 100000)) +
                ' '+str(random.randint(0, 100000))+'\n')
f.close()
