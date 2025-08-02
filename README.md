# 🕹️ so_long

**so_long** is a simple but fun 2D tile-based game built with **MiniLibX** as part of the 42 curriculum.  
Your mission? Collect all the goodies (`C`), avoid walls (`1`), and reach the exit (`E`) — but only once you've grabbed everything! 🚪✨

---

## 🎮 Features

- ✅ Wall collision detection  
- ✨ Collectibles with live counter  
- 🔓 Exit unlocks once all items are collected  
- 🧠 Custom map parser with error handling  
- 🧩 Flood fill algorithm to validate map accessibility  
- 🎨 Rendered using MiniLibX graphics

---

## 🛠️ Build

```bash
make
make clean      # remove object files  
make fclean     # remove object files and binary  
make re         # rebuild everything
```
```bash
./so_long map.ber
```
| Key     | Action     |
| ------- | ---------- |
| `W` / ↑ | Move Up    |
| `A` / ← | Move Left  |
| `S` / ↓ | Move Down  |
| `D` / → | Move Right |
| `ESC`   | Quit Game  |

## 📦 Map Rules
- The map must be rectangular

- Must be surrounded by walls (1)

- Must contain:

- 1 Player (P)

- 1 Exit (E)

- ≥1 Collectible (C)

- No empty lines inside the map

## 🧠 Notes
- Built using only authorized functions (no fancy extras!)

- Runs on Linux using MiniLibX

- No memory leaks (thanks, Valgrind!) 🧼
