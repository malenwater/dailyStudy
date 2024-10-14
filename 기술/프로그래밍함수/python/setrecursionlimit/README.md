## 함수 형태
    - 예시)
        import sys
        input = sys.stdin.readline
        sys.setrecursionlimit(10**5)
## 함수 역할
    - sys.setrecursionlimit() : 재귀 호출의 최대 깊이를 변경하여 더 깊은 재귀 호출이 가능하도록 한다.
    - sys.stdin.readline : 표준 입력에서 한줄을 읽어오는 함수로, 더 빠르게 읽어올 수 있다.
## 사용 이유
    - 더 깊은 재귀 함수나, 또는 빠른 입력을 위해 사용한다.
## 참고문헌
    - chatGPT