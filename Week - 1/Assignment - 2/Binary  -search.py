def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid

        elif arr[mid] < target:
            left = mid + 1

        else:
            right = mid - 1

    return -1


# Input
n = int(input("Enter the number of elements: "))

arr = []

print("Enter the elements in sorted order:")

for i in range(n):
    element = int(input(f"Element {i + 1}: "))
    arr.append(element)

target = int(input("Enter the element to search: "))

# Search
result = binary_search(arr, target)

# Output
if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")