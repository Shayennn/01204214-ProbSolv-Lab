import random

n = 10

f = open('test_trains.txt', 'w')
f.write(str(n))
f.write('\n')
for i in range(n):
    if random.random() > 0.2:
        f.write('N ' + str(i+1) + ' '+str(random.randint(1, 10))+'\n')
    else:
        f.write('M ' + str(random.randint(1, 10)) +
                ' '+str(random.randint(1, 10))+'\n')
f.close()
