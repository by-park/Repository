"""
17889 Mars Window

정수론

26개월 주기
2018년 4월
2020년 6월
2022년 8월
2024년 10월
2026년 12월
2029년 2월
"""

year = int(input())
if ((year-2018-1)*12+9)//26 < ((year-2018)*12+8)//26:
    print("yes")
else:
    print("no")