def swap(xp, yp):
    temp = xp
    xp = yp
    yp = temp

def printArray(arr):
    for num in arr:
        print(num, end=" ")
    print()

def bubbleSort(arr):
    n = len(arr)
    comparisonCnt = 0
    swapCnt = 0

    for i in range(n - 1):
        flag = False
        for j in range(0, n - i - 1):
            comparisonCnt += 1
            if arr[j] > arr[j + 1]:
                swap(arr[j], arr[j + 1])
                flag = True
                swapCnt += 1
        if not flag:
            break

    print("No. of comparisons:", comparisonCnt)
    print("No. of swaps:", swapCnt)

def main():
    arr = [64, 34, 25, 12, 22, 11, 90]
    # arr = [34, 64, 25, 12, 22, 11, 90]

    print("Initial array:")
    printArray(arr)

    bubbleSort(arr)

    print("Sorted array:")
    printArray(arr)

if __name__ == "__main__":
    main()
