import math as m
import sys
try: 
    while True:
        z=int(input())
        h=m.log(2*z+1,3)
        
        if(h-m.floor(h)<=0.000000000000000000000001):
            print(int(m.floor(h)))
        else:
            print(int( m.floor(h)+1))
except: 
    pass