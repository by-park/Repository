"""
2959 거북이

수학, 사칙연산 분류이지만 기하학처럼 생각하고 풀었다
직사각형을 만들 때 무조건 더 짧은 쪽을 기준으로 줄어드므로
제일 짧은 2개로 한 변 길이를 정하고 (긴 길이를 묶어주면 길수록 손해를 보기 때문에)
나머지 긴 2개로 다른 변 길이를 정하도록 했다.
"""

numbers = list(map(int, input().split()))
numbers.sort()
print(numbers[0]*numbers[2])
