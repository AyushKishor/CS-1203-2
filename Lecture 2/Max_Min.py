def main():
    n = 8
    arr = [64, 34, 25, 12, 22, 11, 90, 3]

    for i in range(n // 2):
        if arr[2 * i] > arr[2 * i + 1]:
            arr[2 * i], arr[2 * i + 1] = arr[2 * i + 1], arr[2 * i]

    min_val, max_val = arr[0], arr[1]
    for i in range(1, n // 2):
        if min_val > arr[2 * i]:
            min_val = arr[2 * i]
        if max_val < arr[2 * i + 1]:
            max_val = arr[2 * i + 1]

    print(f"min {min_val}, max {max_val}")

if __name__ == "__main__":
    main()
