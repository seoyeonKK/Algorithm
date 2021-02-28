n = int(input())
numbers = map(int, input().split())
prime = 0

for num in numbers:
    check = False
    if num > 1:
        for i in range(2, num):
            if num % i == 0:
                check = True
                break
        if check == False:
            prime += 1  # 소수 
print(prime)
