# DSA-smart-bus-system-

# 🚌 Smart Bus Route & Fare Optimization System

## 📌 Overview

This project simulates a real-world **bus transportation system** using **Data Structures and Algorithms (DSA)** and **Object-Oriented Programming (OOP)** in C++.

It calculates the **shortest and most efficient route** between two stops while minimizing:

* distance 🚏
* fare 💰
* number of bus changes 🔁

---

## 🚀 Features

* 🔍 Find shortest path between stops
* 🔁 Detect and minimize bus changes
* 💰 Automatic fare calculation
* ⏱ Travel time in hours + minutes
* 📂 File-based system (supports 50+ stops)
* ⚡ Fast execution using priority queue

---

## 🧠 Core Concepts Used

* Graphs (Adjacency List)
* Dijkstra’s Algorithm (Modified)
* Priority Queue (Min Heap)
* OOP Design in C++

---

## 🏗 Project Structure

```
BusSystem/
├── main.cpp
├── BusSystem.cpp
├── BusSystem.h
├── busdata.txt
```

---

## ▶️ How to Run

### 🍎 macOS

```bash
clang++ -std=c++11 main.cpp BusSystem.cpp -o bus
./bus
```

### 🪟 Windows (MinGW)

```bash
g++ -std=c++11 main.cpp BusSystem.cpp -o bus
bus
```

---

## 💻 Requirements

* C++ Compiler (g++ / clang++)
* macOS: `xcode-select --install`
* Windows: MinGW installed and added to PATH

---

## 📊 Sample Output

```
Route:
Dehradun --(601)--> Haridwar --> ...

Change to Bus 501

Distance: 834 km
Fare: Rs 1693
Time: 42 hr 2 min
Bus Changes: 4
```

---
## 👨‍💻 Author

**SHAHAN AHMAD**

---

## ⭐ If you like this project

Give it a star ⭐ and share it!
