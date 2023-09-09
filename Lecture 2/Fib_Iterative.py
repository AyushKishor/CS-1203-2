n = 6
f0 = 0
f1 = 1
twoback = f0
oneback = f1

if n == 0:
    present = f0
elif n == 1:
    present = f1
else:
    for i in range(2, n + 1):
        present = oneback + twoback
        twoback = oneback
        oneback = present

print(f"Fib({n}) = {present}")
