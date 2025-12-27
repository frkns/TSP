import subprocess
import sys
import re
import math

if len(sys.argv) < 3:
    print(f'usage: python {sys.argv[0]} <solution_file> <input_file>')
    sys.exit(1)

solution_file = sys.argv[1]
input_file = sys.argv[2]

n = 0
mean = 0.0
m2 = 0.0  # for welford

print('running indefinitely...\n')

try:
    while True:
        result = subprocess.run(
            ['python', 'checker.py', solution_file],
            input=open(input_file, 'rb').read(),
            capture_output=True
        )
        output = result.stdout.decode()

        match = re.search(r'Total distance:\s*([0-9.]+)', output)
        if match:
            distance = float(match.group(1))
            n += 1
            delta = distance - mean
            mean += delta / n
            delta2 = distance - mean
            m2 += delta * delta2
            stddev = math.sqrt(m2 / n) if n > 1 else 0.0
            stderr = stddev / math.sqrt(n) if n > 0 else 0.0
            print(f'n = {n},  mean = {mean:.2f},  stddev = {
                  stddev:.2f},  stderr = {stderr:.2f}')
        else:
            print('could not parse total distance from output.')
except KeyboardInterrupt:
    print('\nstopped.')
