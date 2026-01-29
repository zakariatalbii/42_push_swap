# 🧮 push_swap

## 📌 Overview

This project implements a custom sorting algorithm for the **push_swap** problem (42 cursus), written in **C**.  
The program sorts a stack of integers using a second auxiliary stack and a **restricted set of operations**, while minimizing the number of moves.

The solution is based on:
- Linked-list stack structures
- Dynamic target selection
- Precise move cost calculation
- Optimized rotations (combined & individual)

---

## 🏗️ Data Structures

### 🔹 Stack Node

```c
typedef struct s_stack
{
	int				index;		// current position in stack
	int				value;		// actual integer value
	int				c_mvs;		// total cost (moves)
	int				d_mvs;		// move direction strategy
	struct s_stack	*next;
	struct s_stack	*target;	// destination position in the other stack
}	t_stack;
```

Each node stores both its value and metadata used for optimization:
- `target`: destination node in the opposite stack
- `c_mvs`: minimal number of required moves
- `d_mvs`: rotation strategy used to reach the target

---

### 🔹 Stack Handler

```c
typedef struct s_h_stack
{
	int		size;
	t_stack	*stack;
}	t_h_stack;
```

This structure stores the stack size and its head pointer, allowing efficient cost and rotation calculations.

---

## ⚙️ Algorithm Strategy

### 1️⃣ Initial Reduction (A → B)

```c
while (!ft_circo(a) && a->size > 3)
	pb(b, a);
```

Elements are pushed from stack **A** to stack **B** until:
- Stack A becomes circularly sorted, or
- Only 3 elements remain in A

This step reduces problem complexity and prepares optimal reinsertion.

---

### 2️⃣ Indexing

```c
ft_indexer(a);
ft_indexer(b);
```

Each node receives an index based on its current position.  
Indexes are used to:
- Compute distances
- Choose optimal rotation directions

---

### 3️⃣ Target Selection

```c
ft_target(a->stack, b->stack, 'a');
```

For each element, the algorithm determines the best insertion target:
- From **A to B** → closest smaller value
- From **B to A** → closest larger value

This guarantees correct ordering during reinsertion.

---

### 4️⃣ Move Cost Calculation

```c
ft_mvs(s, ssize, tsize);
```

For each element, four possible move strategies are evaluated:

|	Strategy	|		Description			|
|---------------|---------------------------|
|		UU		|	rotate both stacks up	|
|		DD		|	rotate both stacks down	|
|		UD		|	source up, target down	|
|		DU		|	source down, target up	|

The cheapest strategy is selected and stored in `c_mvs` and `d_mvs`.

---

### 5️⃣ Optimal Rotation Execution

```c
ft_rotate_its(s, t, c);
```

- The element with the lowest cost is selected
- Combined rotations (`rr`, `rrr`) are used when possible
- Individual rotations are applied otherwise

This ensures minimal total operations.

---

### 6️⃣ Final Reinsertion (B → A)

```c
while (b->size)
{
	// recompute indexes, targets and costs
	pa(a, b);
}
```

Elements are pushed back into stack A already positioned correctly.

---

### 7️⃣ Final Alignment

```c
ft_rotate_it(a, ft_get_min(a->stack), 'a');
```

The smallest element is rotated to the top, completing the sort.

---

## 🔍 Small Input Optimization

For stacks of **3 elements**, a dedicated function is used:

```c
ft_order_three(a);
```

This guarantees an optimal solution for minimal input sizes.

---

## ⭐ Bonus Part — Checker

The bonus part implements a checker program that validates whether a given sequence of operations correctly sorts the stack.

🧠 How It Works

- The checker receives the initial stack as arguments
- It reads instructions from standard input
- Each instruction is executed on the stacks
- At the end, the checker verifies if:
	- Stack A is sorted in ascending order
	- Stack B is empty

🧪 Valid Instructions

The checker supports all mandatory operations:
**pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr**

Any invalid instruction triggers an immediate error.

▶️ Usage Example

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

Output:

```
OK
```

or:

```
KO
```

---

## 🚀 Compilation & Usage

The project includes a Makefile with the following rules:

```bash
make		# push_swap
make bonus	# checker
make clean	# Remove object files
make fclean	# Remove object files and the programs
make re		# Recompile everything
```

▶️ Usage

```bash
git clone git@github.com:zakariatalbii/42_push_swap.git
cd 42_push_swap
```

Example:

```bash
make
./push_swap 4 1 3 2
```

Output:

```
pb
sa
ra
pa
ra
```

Each line represents a valid stack operation.

---

## 🧪 Error Handling

The program safely handles:
- Non-numeric arguments
- Duplicate values
- Integer overflow
- Invalid input formats

On error, the program exits immediately.

---

## 📊 Complexity Notes

- No brute-force
- No radix sort
- Dynamic cost-based decisions
- Designed to stay within 42 evaluation limits

---

## 📚 What This Project Demonstrates

- Advanced linked-list manipulation
- Cost-based decision making
- Algorithm optimization under constraints
- Clean separation of logic and operations
- Strong understanding of stack behavior

---

## 🌲 Project Structure

- **Makefile** - Build configuration
- **src/** - push_swap source files
- **include/** - push_swap header file
- **bonus/** - Bonus (checker) implementation
- **checker/** - The given checker (for linux/Mac)
- **en.subject.pdf** - Project subject

---

## 👤 Author

**Zakaria Talbi**
- GitHub: [@zakariatalbii](https://github.com/zakariatalbii)

---

## 📜 License

This project is part of the 42 School cursus.