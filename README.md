# 🤞 Condition Variable

This repository contains a simple and effective example of using `std::condition_variable` in C++. It demonstrates how to manage thread synchronization and communication between threads using mutexes and condition variables to prevent busy-waiting.

---

## 🚀 Purpose

The goal of this project is to show:
* **Efficiency:** How to put threads to sleep while waiting for a condition to save CPU cycles.
* **Synchronization:** Using `std::mutex` and `std::unique_lock` to protect shared data.
* **Signaling:** How to use `notify_one()` or `notify_all()` to wake up waiting threads.

---

## 🛠️ Components Used

| Component | Description |
| :--- | :--- |
| **std::condition_variable** | The core object used to block a thread until a notification is received. |
| **std::mutex** | Provides exclusive access to shared resources. |
| **std::unique_lock** | A flexible lock wrapper required by condition variables to manage the mutex state. |
| **Predicate** | A condition check used within `wait()` to prevent spurious wakeups. |

---

## 💻 How It Works

The logic follows a standard **Producer-Consumer** or **Signaling** pattern:

1. **Wait State:** A thread calls `wait()` on the condition variable, which automatically releases the mutex and suspends the thread.
2. **Notification:** Another thread performs a task, modifies a shared variable, and calls `notify_one()`.
3. **Resume:** The waiting thread re-acquires the mutex and continues execution once the condition is met.

---

## 🛠️ Installation & Compilation

To compile and run this project, you need a C++11 (or higher) compatible compiler.

```bash
# Clone the repository
git clone [https://github.com/xRangeroQ/Condition_Variable_Cpp.git](https://github.com/xRangeroQ/Condition_Variable_Cpp.git)

# Navigate to the directory
cd Condition_Variable_Cpp

# Compile with G++ (Ensure pthread is linked)
g++ main.cpp -o ConditionVarApp -lpthread

# Run the executable
./ConditionVarApp
