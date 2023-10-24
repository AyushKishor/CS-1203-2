def binary_search(arr, l, r, x):
    while l <= r:
        m = l + (r - l) // 2
        if arr[m] == x:
            return m
        elif arr[m] < x:
            l = m + 1
        else:
            r = m - 1
    return -1

def main():
    n = 5
    x = 10
    arr = [2, 3, 4, 10, 40]
    result = binary_search(arr, 0, n - 1, x)
    if result == -1:
        print("Element not present")
    else:
        print("Element present at index", result)

if __name__ == "__main__":
    main()
