n = int(input("Enter the number of students: "))

marks = []

# Input marks
print("Enter the marks of each student:")

for i in range(n):
    mark = float(input(f"Student {i + 1}: "))
    marks.append(mark)

# Sort marks in descending order
marks.sort(reverse=True)

# Calculate average
average = sum(marks) / n

# Display results
print("\nSorted marks:", marks)

print("Top 3 marks:")
for i in range(min(3, n)):
    print(f"{i + 1}. {marks[i]}")

print(f"Average score: {average:.2f}")