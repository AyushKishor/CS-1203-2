def binary_search(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        if arr[mid] > x:
            return binary_search(arr, l, mid - 1, x)
        return binary_search(arr, mid + 1, r, x)
    return -1

def main():
    n = 5
    x = 11
    arr = [2, 3, 4, 10, 40]
    result = binary_search(arr, 0, n - 1, x)
    if result == -1:
        print("Element not present")
    else:
        print("Element present at index", result)

if __name__ == "__main__":
    main()
