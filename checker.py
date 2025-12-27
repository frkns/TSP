import subprocess
import sys
import math
import os


def compile_cpp(src, out):
    proc = subprocess.run(
        ['g++', '-O2', src, '-o', out],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    if proc.returncode != 0:
        print('compilation failed:')
        print(proc.stderr)
        sys.exit(1)


def run_solution(executable, input_data):
    proc = subprocess.run(
        [executable],
        input=input_data,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=60
    )
    if proc.stderr:
        print('program stderr:', proc.stderr, file=sys.stderr)
    return proc.stdout.strip().split()


def checker():
    if len(sys.argv) != 2:
        print(f'usage: {sys.argv[0]} <solution.cc> < in', file=sys.stderr)
        sys.exit(1)

    src = sys.argv[1]
    if not os.path.exists(src):
        print(f'file not found: {src}', file=sys.stderr)
        sys.exit(1)

    input_data = open(0).read()
    if not input_data.strip():
        print('no input')
        return

    points = {}
    input_ids = []
    for line in input_data.splitlines():
        i, x, y = line.split()
        i = int(i)
        points[i] = (float(x), float(y))
        input_ids.append(i)

    exe = './a.out'
    try:
        compile_cpp(src, exe)

        output = run_solution(exe, input_data)

    finally:
        if os.path.exists(exe):
            os.remove(exe)

    tour = list(map(int, output))
    if set(tour) != set(input_ids):
        print('invalid permutation of IDs')
        return

    total = 0.0
    n = len(tour)
    for i in range(n):
        a = points[tour[i]]
        b = points[tour[(i + 1) % n]]
        total += math.hypot(a[0] - b[0], a[1] - b[1])

    print(f'Total distance: {total:.4f}')


if __name__ == '__main__':
    checker()
