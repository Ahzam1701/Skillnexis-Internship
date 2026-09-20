def reverse_array(arr):
    left = 0
    right = len(arr) - 1

    while left < right:
        arr[left], arr[right] = arr[right], arr[left]

        left += 1
        right -= 1


# Input
n = int(input("Enter the number of elements: "))

arr = []

print("Enter the elements:")

for i in range(n):
    element = int(input(f"Element {i + 1}: "))
    arr.append(element)

# Reverse the array
reverse_array(arr)

# Output
print("Reversed array:", arr)