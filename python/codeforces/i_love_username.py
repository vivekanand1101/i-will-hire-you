n = int(raw_input())
x = raw_input()
x = x.split(' ')
#x = map(int, x)
x = [int(i) for i in x]

awesomeness_count = 0
for i in range(len(x)):
    if i == 0:
        min_value = x[i]
        max_value = x[i]
    else:
        #print type(x[i])
        if x[i] < min_value:
            #print 'min ', x[i]
            awesomeness_count += 1
            min_value = x[i]
        elif x[i] > max_value:
            #print 'max ', x[i]
            awesomeness_count += 1
            max_value = x[i]

print awesomeness_count
