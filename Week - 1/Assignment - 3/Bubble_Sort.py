def bubble_sort(arr):
    swaps = 0
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1

    return swaps


# Input
n = int(input("Enter the number of elements: "))

arr = []

print("Enter the elements:")

for i in range(n):
    element = int(input(f"Element {i + 1}: "))
    arr.append(element)

# Sort the array
swap_count = bubble_sort(arr)

# Output
print("Sorted array:", arr)
print("Number of swaps:", swap_count)