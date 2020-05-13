import sys

with open(sys.argv[1]) as f:
    text = f.read()

tree = text.split('2:\t\n')[1]
stack_count = 0
max_stack = 0

for i in tree:
    if i == '{':
        stack_count += 1
    elif i == '}':
        stack_count -= 1
    max_stack = max(max_stack, stack_count)

print(max_stack)
