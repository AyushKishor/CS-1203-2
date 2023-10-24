def fib(k):
    if k <= 0:
        return 0
    elif k == 1:
        return 1
    else:
        return fib(k - 1) + fib(k - 2)

n = 6
print(f"Fib({n}) = {fib(n)}")
