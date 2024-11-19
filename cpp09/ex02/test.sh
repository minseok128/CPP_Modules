#!/bin/bash

# A001768.txt 파일에서 비교 횟수 수열을 읽어와서 수열 값만 배열에 저장합니다.
declare -a A001768
while IFS=' ' read -r index value; do
    A001768[index]=$value
done < A001768.txt

# 테스트할 최대 n값
max_n=10000
# 각 n 값에 대해 반복할 테스트 횟수
iterations=5

# 테스트 시작
for (( n=1; n<=max_n; n++ )); do
    # 비교 횟수 초과 여부와 정렬 오류 여부를 확인하기 위한 플래그 초기화
    failed=0
    expected_comparisons=${A001768[$n]}

    for (( i=0; i<iterations; i++ )); do
        # 임의의 n개 숫자를 생성하여 알고리즘 실행
        random_numbers=$(jot -r "$n" 1 1000 | tr '\n' ' ')
        
        # PmergeMe 실행 결과를 두 줄로 읽어옴
        output=$(./PmergeMe $random_numbers)
        comparisons=$(echo "$output" | sed -n '1p' | tr -d ' ')   # 첫 번째 줄에서 비교 횟수 (공백 제거)
        sorted_output=$(echo "$output" | sed -n '2p' | xargs)     # 두 번째 줄에서 정렬 결과 (양쪽 공백 제거)
        
        # 만약 비교 횟수가 기대 값을 초과하면 실패로 설정하고 해당 값을 저장 후 루프 종료
        if [ "$comparisons" -gt "$expected_comparisons" ]; then
            failed=1
            exceeded_value=$comparisons
            break
        fi

        # 정렬 검사: 원본 숫자를 정렬한 결과와 프로그램 출력 결과를 비교
        sorted_expected=$(echo "$random_numbers" | tr ' ' '\n' | sort -n | tr '\n' ' ' | xargs) # 양쪽 공백 제거
        if [ "$sorted_output" != "$sorted_expected" ]; then
            failed=1
            incorrect_sort="$sorted_output"
            expected_sort="$sorted_expected"
            break
        fi
    done

    # 테스트 결과 출력
    if [ "$failed" -eq 1 ]; then
        if [ -n "$exceeded_value" ]; then
            echo "n=$n: FAILED (Exceeded Expected Comparisons: $expected_comparisons, Actual: $exceeded_value)"
        elif [ -n "$incorrect_sort" ]; then
            echo "n=$n: FAILED (Incorrect Sort. Expected: $expected_sort, Got: $incorrect_sort)"
        fi
    else
        echo "n=$n: PASSED (Within Expected: $expected_comparisons)"
    fi
done
