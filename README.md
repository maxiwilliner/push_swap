# Push_swap - The Art of Algorithmic Complexity | 42 Madrid

This project has been developed as part of the 42 curriculum by **mwilline**.

## 📖 Overview

**Push_swap** is a challenging algorithmic project designed to test the understanding of **Sorting Algorithms**, **Data Structures**, and **Computational Complexity (Big O)**.

The challenge consists of sorting a stack of integers using a highly restricted set of instructions (push, swap, rotate) and an auxiliary stack. The catch? The goal isn't just to sort, but to do so with the **minimum number of operations possible**. It is an exercise in optimization where brute force is not an option.

## 🛠️ Technical Implementation: C & Data Structures

In this implementation, I focused on efficiency and strict memory management using **C**:

* **Stack Implementation:** Utilized **Doubly Linked Lists** (structs) to represent stacks A and B. This allows for dynamic memory allocation and efficient pointer manipulation ($O(1)$) for push/swap operations, avoiding the overhead of array shifting.
* **Instruction Set Optimization:** The core engine calculates the "cost" of every possible move. Before moving a number, the algorithm simulates the operations needed to place it in the correct position, executing only the cheapest sequence.
* **Input Parsing & Validation:** Robust error handling for non-integer inputs, duplicates, and integer overflows (MAX_INT / MIN_INT validation).

## 🧬 Data Engineering Relevance

Why a Data Engineer needs to master this:

* **Algorithmic Efficiency (Big O):** in Data Engineering, the difference between $O(n^2)$ and $O(n \log n)$ can mean the difference between a pipeline running in minutes versus hours. This project enforces thinking in terms of computational cost.
* **Data Structures:** Understanding how Stacks and Linked Lists work under the hood is fundamental when optimizing data storage or understanding how tools like **Apache Spark** manage partitions in memory.
* **ETL Optimization:** Sorting is a primitive operation in almost every ETL process (Join, Group By, Window Functions). Writing an optimized sort engine provides deep insight into how Query Planners optimize execution plans.

## 🏗️ Algorithm & Logic

To solve the sorting problem with minimal moves, I implemented a custom **Greedy Algorithm with Cost Calculation** (often referred to as the Turk Algorithm):

1.  **Presorting / Chunking:** The algorithm pushes numbers from Stack A to B, keeping the rough order to minimize future operations.
2.  **Cost Analysis:** For the remaining elements, the program calculates the mechanical cost (number of rotations + pushes) to move each element to its correct target in Stack A.
3.  **Targeting Strategy:** It identifies the "cheapest" node to move and executes a synchronized rotation (using `rr` or `rrr` to move both stacks at once) to maximize efficiency.

## 🚀 Usage & Instructions

### Arguments

The program accepts a list of integers as arguments:
`./push_swap [list_of_numbers]`

### Compilation

```bash
cd push_swap
make
