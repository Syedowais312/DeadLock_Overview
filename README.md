# Deadlock Simulation, Prevention, and Avoidance in C++

This project demonstrates three multithreading concepts using **C++ mutexes**:

* **Deadlock Simulation**
* **Deadlock Prevention**
* **Deadlock Avoidance**

Each example uses practical scenarios (printers) to show how threads interact with shared resources.

---

## How to Run the Code

### **1. Install a C++ Compiler**

You can use:

* GCC (Linux / MinGW on Windows)
* Clang
* MSVC (Visual Studio)

### **2. Save Each Program in Separate Files**

Example:

```
simulation.cpp
prevention.cpp
avoidance.cpp
```

### **3. Compile the Code**

#### On Linux / Mac/ Windows:

```
g++ simulation.cpp -o simulation -pthread
g++ prevention.cpp -o prevention -pthread
g++ avoidance.cpp -o avoidance -pthread
```

### **4. Run the Programs**

#### Linux / Mac:

```
./simulation
./prevention
./avoidance
```

#### Windows:

```
simulation.exe
prevention.exe
avoidance.exe
```

---

## 1. Deadlock Simulation

This program intentionally causes a **deadlock** by locking shared resources in opposite order.

**What happens?**

* Thread 1 locks Printer A → waits for Printer B
* Thread 2 locks Printer B → waits for Printer A
* Both wait forever → DEADLOCK

Expected behavior:

```
Doc1: Using Printer A
Doc2: Using Printer B
<program freezes>
```

---

## 2. Deadlock Prevention

This version ensures **no deadlock** by locking mutexes in the **same global order**.

**What happens?**

* Both threads lock Printer A → Printer B
* No circular wait possible

Expected output (order may vary):

```
Doc1 printed using A and B
Doc2 printed using A and B
```

---

##  3. Deadlock Avoidance

This version uses `try_lock()`.
If a thread cannot lock both printers, it **releases the first lock** and retries.

**What happens?**

* No blocking
* Threads retry until they safely acquire both printers

Expected output:

```
Document1 printed successfully using A and B
Document2 printed successfully using A and B
```


## 📚 Requirements

* C++17 or above
* `#include <thread>`
* `#include <mutex>`
* `#include <chrono>`
* Compiler that supports `-pthread`

---

## Recommended Setup

### **VS Code + MinGW (Windows):**

* Install MinGW
* Add to PATH
* Install C/C++ extension
* Use VS Code Terminal to compile and run

### **Linux:**

Pre-installed build tools:

```
sudo apt install build-essential
```

---
