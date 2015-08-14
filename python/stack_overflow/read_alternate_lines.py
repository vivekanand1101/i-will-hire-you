#http://stackoverflow.com/questions/32010116/python-read-specific-alternate-lines/

import os

d = '/home/vivek/t'
l = os.listdir(d)

for i in l:
    p = os.path.join(d, i)
    if os.path.isfile(p) and i == 'tmp.txt':

        with open(p, 'r') as f:
            for index, line in enumerate(f.readlines()):
                if index % 3 == 0:
                    with open(os.path.join(d, 'store_1.txt'), 'a') as s1:
                        s1.write(line)
                elif index % 3 == 1:
                    with open(os.path.join(d, 'store_2.txt'), 'a') as s2:
                        s2.write(line)
                elif index % 3 == 2:
                    with open(os.path.join(d, 'store_3.txt'), 'a') as s3:
                        s3.write(line)
