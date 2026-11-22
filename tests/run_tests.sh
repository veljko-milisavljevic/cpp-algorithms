#!/usr/bin/env bash
# Compiles every program in algorithms/ and checks it against tests/<name>/*.in / *.out.
set -u
root="$(cd "$(dirname "$0")/.." && pwd)"
build="$(mktemp -d)"
trap 'rm -rf "$build"' EXIT
fail=0
for src in "$root"/algorithms/*/*.cpp; do
    name="$(basename "$src" .cpp)"
    g++ -std=c++17 -O2 -Wall -Wextra -o "$build/$name" "$src" || { echo "BUILD FAIL $name"; fail=1; continue; }
    for input in "$root"/tests/"$name"/*.in; do
        [ -e "$input" ] || continue
        expected="${input%.in}.out"
        if diff -q <("$build/$name" < "$input") "$expected" > /dev/null; then
            echo "ok   $name/$(basename "$input")"
        else
            echo "FAIL $name/$(basename "$input")"; fail=1
        fi
    done
done
exit $fail
