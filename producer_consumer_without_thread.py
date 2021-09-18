import time
from threading import *

stack = 0
s = 1
def waitc():
    global s
    while (s == 0):
        pass
    s = 0

def goc():
    global s
    s = 1

def producer():
        global stack
        while(stack >= 5):
            pass
        waitc()
        stack = stack + 1
        print(" producer produce 1 and stack is : ", stack)
        time.sleep(.1)
        goc()


def consumer():
        global stack
        while (stack == 0):
            pass
        waitc()
        stack = stack - 1
        print(' consumer consume 1 and stack is : ', stack)
        goc()
        time.sleep(.1)
for i in range (10):
    if(i<5):
        producer()
    else:
        consumer()