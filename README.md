# 2048 Variant

A small, Raylib-based 2048 game on a 4×4 grid, with movement rules that add a twist to the classic game.

## How it plays

Move tiles with the arrow keys. Matching tiles can merge, and a merge can trigger further merges in the same move: for example, `2 2 4 8` can become `_ _ _ 16`.

Other tiles can block movement and merging. For example, `2 4 2 _` can become `2 4 _ 2`, while `4 8 _ _` can become `4 _ _ 8`. The blocking tile stays put; only tiles that can move do so.

New tiles appear after successful moves. The game ends when no moves remain.

## Requirements

- C/C++ toolchain
- [Raylib](https://www.raylib.com/)
