# 2048 Variant

A small, Raylib-based 2048 game on a 4×4 grid, with movement rules that add a twist to the classic game.

## How it plays

Move tiles with the arrow keys. Matching tiles can merge, and a merge can trigger further merges in the same move: for example, `2 2 4 8` becomes `_ _ _ 16` directly in a single right click rather than `_ 4 4 8`.

Other tiles can block movement and merging. For example, `2 4 2 _` becomes `2 4 _ 2` instead of `_ 2 4 2` as the end 2 blocks preceding 2 4 from sliding to the right, while `4 8 _ _` becomes `4 _ _ 8` instead of `_ _ 4 8` as 8 blocks 4 from sliding to the right. 

A new 2 tile appears after every successful move. The game ends when no moves remain.

## Requirements

- C/C++ toolchain
- [Raylib](https://www.raylib.com/)
