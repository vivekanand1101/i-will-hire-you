# http://codeforces.com/problemset/problem/208/A
remix = raw_input()
wub = 'WUB'
length = len(remix)
output = ''

while wub in remix:
    i = remix.find(wub)
    if output != '':
        output = output + ' ' + remix[:i]
    else:
        output = remix[:i]
    remix = remix[i+3:]

print output + ' ' + remix
