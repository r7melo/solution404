import time


def fib (n):
    if n == 0 or n == 1:
        return n
    
    return fib(n-1) + fib(n-2)


def fib2(n):

    memo = [None for _ in range(n+1)]
    return fib_dinamico(n, memo)

def fib_dinamico(n, memo):

    if n == 0 or n == 1:
        return n
    
    if memo[n] is None:
        memo[n] = fib_dinamico(n-1, memo) + fib_dinamico(n-2, memo)
    
    return memo[n]



if __name__=="__main__":
    # inicio = time.time()
    # print(fib(37))
    # fim = time.time()
    # print('time fib',fim-inicio)

    inicio = time.time()
    print(fib2(998))
    fim = time.time()
    print('time fib_dinamico',fim-inicio)