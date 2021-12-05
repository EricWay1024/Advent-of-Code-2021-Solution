# A simple script to get the number of numbers drawn (N)
# and the number of boards (M) from input
# Then we use the two constants in our cpp script :)

nums = input()
N = len(nums.split(','))
cnt = 0
while 1:
    try:
        l = input()
    except EOFError:
        break
    cnt += 1

M = cnt // 6
print(N, M)