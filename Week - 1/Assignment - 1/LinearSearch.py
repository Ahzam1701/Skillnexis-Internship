def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

n = int(input("Enter the number of elements: "))

arr = []
print("Enter the elements:")

for i in range(n):
    element = int(input(f"Element {i + 1}: "))
    arr.append(element)

target = int(input("Enter the element to search: "))

result = linear_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")