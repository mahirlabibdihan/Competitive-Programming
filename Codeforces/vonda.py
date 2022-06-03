def input_list():
    return list(map(int, input().split()))


def is_sorted(arr: list, n):
    for i in range(0, n-1):
        if arr[i] > arr[i+1]:
            return False
    return True


def main():
    n = int(input())
    arr = input_list()
    if(is_sorted(arr, n)):
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()
