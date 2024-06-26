/*
1834 나머지와 몫이 같은 수 

나머지와 몫이 같은 수
N 이 3일 때, 
4 = N*1 + 1 = 1 * (N+1)
8 = N*2 + 2 = 2 * (N+1) 
이 수들의 합은 (N+1) 로 묶으면
(1+2+...+N-1) * (N+1) 이 될 것
(N 을 넘어가면 더 이상 나머지가 나올 수 없기 때문이다) 
합은 (N-1)*N / 2 여기에 *(N+1) 한 것이 정답 

N 의 최대 범위는 10^6 이므로,
N^3 의 최대 범위는 10^18 이다.
long long 으로 잡아야한다. 
*/

#include <stdio.h>

int main(void)
{
	unsigned long long N;
	scanf("%llu", &N);
	printf("%llu\n", (N-1)*(N)*(N+1)/2);
	return 0;
}



