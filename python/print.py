#! /usr/bin/python

# reversed index 
l1 = [1,2,3,4,5,6,7,8,9]
# format controled 
print l1[0], 'yes' # 9_yes
# format outof controll
for x in range(1, 11):
    print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))
