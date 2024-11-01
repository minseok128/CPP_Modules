#!/bin/bash

# 포드 존슨 알고리즘 비교 횟수 수열 (A001768)
declare -a A001768=(0 1 3 5 7 10 13 16 19 22 26 30 34 38 42 46 50 54 58 62 66 71 76 81 86 91 96 101 106 111 116 121 126 131 136 141 146 151 156 161 166 171 177 183 189 195 201 207 213 219 225 231 237 243 249 255)

# 테스트할 최대 n값 (50 미만으로 설정해야 A001768 배열 범위 내)
max_n=50
# 각 n 값에 대해 반복할 테스트 횟수
iterations=50

# 테스트 시작
for (( n=1; n<=max_n; n++ )); do
    # 비교 횟수의 합산 및 평균 계산을 위한 변수 초기화
    total_comparisons=0

    for (( i=0; i<iterations; i++ )); do
        # 임의의 n개 숫자를 생성하여 알고리즘 실행 및 비교 횟수 추출
        comparisons=$(./PmergeMe $(jot -r "$n" 1 1000 | tr '\n' ' '))
        
        # 비교 횟수를 총 합산에 추가
        total_comparisons=$((total_comparisons + comparisons))
    done

    # 평균 비교 횟수 계산
    avg_comparisons=$((total_comparisons / iterations))

    # 실제 수열 값과 비교
    expected_comparisons=${A001768[$n]}
    if [ "$avg_comparisons" -eq "$expected_comparisons" ]; then
        echo "n=$n: PASSED (Average comparisons: $avg_comparisons, Expected: $expected_comparisons)"
    else
        echo "n=$n: FAILED (Average comparisons: $avg_comparisons, Expected: $expected_comparisons)"
    fi
done
