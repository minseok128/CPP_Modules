#!/bin/bash

# A001768.txt 파일에서 비교 횟수 수열을 읽어와서 수열 값만 배열에 저장합니다.
declare -a A001768
while IFS=' ' read -r index value; do
    A001768[index]=$value
done < A001768.txt

# 테스트할 최대 n값
max_n=50
# 각 n 값에 대해 반복할 테스트 횟수
iterations=50

# 테스트 시작
for (( n=1; n<=max_n; n++ )); do
    # 비교 횟수 초과 여부를 확인하기 위한 플래그 초기화
    failed=0
    expected_comparisons=${A001768[$n]}

    for (( i=0; i<iterations; i++ )); do
        # 임의의 n개 숫자를 생성하여 알고리즘 실행 및 비교 횟수 추출
        comparisons=$(./PmergeMe $(jot -r "$n" 1 1000 | tr '\n' ' '))
        
        # 만약 비교 횟수가 기대 값을 초과하면 실패로 설정하고 해당 값을 저장 후 루프 종료
        if [ "$comparisons" -gt "$expected_comparisons" ]; then
            failed=1
            exceeded_value=$comparisons
            break
        fi
    done

    # 테스트 결과 출력
    if [ "$failed" -eq 1 ]; then
        echo "n=$n: FAILED (Exceeded Expected: $expected_comparisons, Actual: $exceeded_value)"
    else
        echo "n=$n: PASSED (Within Expected: $expected_comparisons)"
    fi
done
