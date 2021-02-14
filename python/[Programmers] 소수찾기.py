from itertools import permutations
import math

def check(n):
    k = math.sqrt(n) # 제곱근
    if n < 2: 
        return False

    for i in range(2, int(k)+1): # 제곱근까지만 확인
        if n % i == 0:
            return False
    return True

def solution(numbers):
    answer = []
    for k in range(1, len(numbers)+1):
        perlist = list(map(''.join, permutations(list(numbers), k))) # k개의 원소로 수열만들기
        for i in list(set(perlist)): # list ->  set으로 중복 제거 -> 다시 list
            if check(int(i)):
                answer.append(int(i))

    answer = len(set(answer))

    return answer
