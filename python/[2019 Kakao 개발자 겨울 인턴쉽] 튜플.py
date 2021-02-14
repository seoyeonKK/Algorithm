def solution(s):
    answer = []
    seen = set()
    
    l = s.replace("{{","").replace("}}","").split("},{")
    l.sort(key=len)
    
    for i in range(0,len(l)):
        k = l[i].split(',')
        
        for j in range(0, len(k)):
            if k[j] not in seen:
                answer.append(int(k[j]))
                seen.add(k[j])
        
    return answer
