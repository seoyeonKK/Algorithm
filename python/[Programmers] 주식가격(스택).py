def solution(prices):
    n = len(prices)
    answer = [0] * n
    stack = []
    
    for i in range(n):
        # 스택이 비어있지 않고, 주식 가격이 떨어졌다면
        while stack and prices[stack[-1]] > prices[i]:
            top = stack.pop()
            answer[top] = i - top # 인덱스의 차이로 기간 구하기
        stack.append(i) # 현재 시간 저장 
    
    while stack:
        # 스택에 남아있는 인덱스 정리해주기 
        # prices가 끝날때까지 주식 가격이 떨어지지 않은 값들이다
        top = stack.pop()
        answer[top] = n - 1 - top
        
    return answer
