def fact(k):
    if k <= 1:
        return 1
    else:
        return k * fact(k - 1)

n = 5
print(fact(n))
