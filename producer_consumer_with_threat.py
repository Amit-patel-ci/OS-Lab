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
    for j in range(10):
        global stack
        while(stack >= 5):
            pass
        waitc()
        stack = stack + 1
        print(" producer produce 1 and stack is : ", stack)
        time.sleep(.1)
        goc()



def consumer():
    for i in range(10):
        global stack
        while (stack == 0):
            pass
        waitc()
        stack = stack - 1
        print(' consumer consume 1 and stack is : ', stack)
        goc()
        time.sleep(.1)


Thread_obj1 = Thread(target=producer)
Thread_obj2 = Thread(target=consumer)
Thread_obj1.start()
Thread_obj2.start()