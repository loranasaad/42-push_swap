# Push_swap

A sorting algorithm in C using two stacks and a limited set of operations.

## Overview

**Push_swap** is a 42 project that challenges you to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, with the goal of using as few moves as possible.

This repository contains the **mandatory part only**. No bonus checker is included.

## Available Operations

| Operation | Description |
|---|---|
| `sa` / `sb` / `ss` | Swap top two elements of stack a / b / both |
| `pa` / `pb` | Push top of b onto a / top of a onto b |
| `ra` / `rb` / `rr` | Rotate stack a / b / both (top becomes bottom) |
| `rra` / `rrb` / `rrr` | Reverse rotate stack a / b / both (bottom becomes top) |

## Algorithm

- **2 elements:** single swap if needed
- **3 elements:** hardcoded 6-case logic
- **4–5 elements:** push minimum to b, sort remaining, push back
- **6+ elements:** chunk-based sorting — numbers are assigned normalized indexes, pushed to b in chunks, then returned to a using a greedy cost algorithm that minimizes total rotations (with `rr`/`rrr` overlap optimization)

## Benchmark

| Input size | Target (100%) | Minimum (80%) |
|---|---|---|
| 100 numbers | < 700 operations | < 1100 operations |
| 500 numbers | ≤ 5500 operations | < 8500 operations |

## Build
```bash
make
```
```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # fclean + compile
```

## Usage
```bash
./push_swap 4 2 7 1 5
```

The program outputs the sequence of operations to stdout, one per line.
```bash
# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

Pass numbers as separate arguments or as a single quoted string:
```bash
./push_swap "3 1 4 1 5"     # quoted string
./push_swap 3 1 4 5         # separate args
```

## Project Structure
```
push_swap/
├── push_swap.h             # structs, typedefs, prototypes
├── push_swap.c             # main entry point, sort dispatch
├── parse_input.c           # argument parsing, ft_split integration
├── atoi_safe.c             # overflow-safe integer parsing
├── ft_split.c              # string splitting for quoted input
├── stack_utilities.c       # is_sorted, is_duplicate, free, add_back
├── ops_push.c              # pa, pb
├── ops_swap.c              # sa, sb, ss
├── ops_rotate.c            # ra, rb, rr
├── ops_reverse_rot.c       # rra, rrb, rrr
├── sort_small.c            # sort_2, sort_3, sort_4, sort_5
├── sort_big.c              # chunk push, greedy return, normalize
├── sort_utilities.c        # move_to_top, assign_indexes, bubble_sort
├── sort_utilities_2.c      # get_index_at_pos, find_pos_min/max, find_in_chunk
├── sort_utilities_3.c      # calculate_dist, pos_insert_a, overlap_rotate, best_candidate
└── Makefile
```

## Testing
```bash
./push_swap 2 1                        # 1 operation
./push_swap 3 2 1                      # ≤ 3 operations
./push_swap 1 2 3 4 5                  # already sorted — no output
./push_swap 0 one 2 3                  # Error
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ')   # random 100
```

## Author
```
loasaad
```