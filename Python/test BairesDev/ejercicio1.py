count = 0
for x in range(1000, 9999):
    if x% 5 == 0 and x%7 == 0 and str(x)[len(str(x)) - 1] == '0':
        count += 1
        
print(count)