declare -a arr;

readarray arr;

arr=("${arr[@]}" "${arr[@]}" "${arr[@]}");

echo "${arr[@]}";
