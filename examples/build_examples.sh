#! /bin/sh

for file in *; do
    if [ -f "$file" ] && [ "${file##*.}" = "cpp" ]; then
        clang++ -o "${file%.*}" "$file"
        echo "built file '$file' as '${file%.*}'"
    fi
done