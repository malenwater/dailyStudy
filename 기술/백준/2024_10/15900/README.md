## 문제 이름
    - 나무 탈출
## 핵심 문제 알고리즘
    - dfs,bfs
## 문제 해결 방안
    - 해당 문제는 시작점으로 부터 dfs,bfs 중 하나를 사용하여 leaf node 까지의 거리들의 합을 구하고, 홀수, 짝수에 따라 답을 내놓으면 된다.
## 시간복잡도
    - log(N)이다 node의 N개 만큼 들어가서 체크하기 때문이다.
## 틀렸던 이유
    - 파이썬이 무겁다는 것을 까먹고 했기 때문에, 그와 관련된 문제가 발생하였다. 이를 해결하는 건 따로 pypy와 python3의 차이, 그리고 그와 관련된 함수를 정의하여 풀겠다.
## 티어
    - 실버
## 참고문헌
    - chatgpt
    - https://wookcode.tistory.com/152