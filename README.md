# Mini_dota2

This C++ project simulates a battle between heroes in a **Dota2-style middle lane**. Each hero belongs to either the **Radiant** or **Dire** team and moves along a one-dimensional lane. When heroes from opposing teams collide, they fight based on their health.

---

## 🚀 Features

- Simulates real-time lane battles based on position, health, and team.
- Stack-based battle resolution algorithm.
- Outputs final healths of all heroes in original input order.
- Modular code with clean function-based architecture.

---

## 📋 Problem Description

Each hero has:
- **Position**: An integer representing their starting position.
- **Health**: Initial health points (integer).
- **Team**: Either `'R'` (Radiant) or `'D'` (Dire).

### 🔁 Battle Mechanics

- Radiant moves right →  
- Dire moves left ←  
- When a Radiant and Dire hero meet:
  - If one's health is greater, that hero survives with health reduced by 1.
  - If both have equal health, both are eliminated.
- All heroes move simultaneously.

---

## 🧑‍💻 Sample Input
Enter number of heroes: 5
Enter positions: 1 4 2 5 10
Enter health: 9 2 8 2 27
Enter team string: R R D D D

## ✅ Sample Output

Remaining Healths: 0 0 7 0 27


## 📌 Key Concepts Used
- Structs for modeling data
- Sorting by position
- Stack-based collision resolution
- Modular function decomposition

