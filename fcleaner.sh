#!/bin/bash

# 현재 디렉토리부터 시작하여 모든 하위 디렉토리를 순회
find . -type f -name 'Makefile' | while read -r makefile; do
  # Makefile이 있는 디렉토리로 이동
  dir=$(dirname "$makefile")
  echo "Cleaning in $dir"
  (cd "$dir" && make fclean)
done
