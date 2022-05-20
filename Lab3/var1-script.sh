#!/usr/bin/env bash

read -p "Enter source file name: " file

text=$(<$file)
echo text | od -x

reNumber='^[0-9]'
reMarks='^[\.\?\!]'
re='^[
]'
result=""
start=0
addCounter=1
buf=""

for i in $(seq 1 ${#text})
do
  if [[ ${text:i-1:1} =~ $reMarks ]] && ! [[ ${text:i:1} =~ $reNumber ]]; then
    if [[ ${text:i:1} =~ $re ]]; then
      let i+=1
    fi;
    buf=${text:start:addCounter}
    result="${result}${buf^}"
    start=$i
    addCounter=0
  fi;
  let addCounter+=1
done

echo $result
