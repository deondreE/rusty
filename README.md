# 🦀 Rusty — A Tiny CPU Profiler Built to Learn Rust

**Rusty** is a simple CPU profiler written in Rust — built not just to measure
performance, but to **understand** Rust’s ownership, borrowing, and concurrency
model at a deep level.

It samples running threads and records how much time different functions and
tasks spend on the CPU. The goal is to explore how to manage complex,
concurrent data safely using Rust’s borrow checker.

---

## 🚀 What Rusty Does

- 🧩 Samples threads at fixed intervals
- ⏱️ Collects stack traces to see where time is spent
- 📊 Aggregates and reports CPU time per function
- 🧠 Demonstrates safe concurrency with `Arc`, `Mutex`, and channels
- 🔍 Teaches ownership, borrowing, and lifetimes through real systems code

---

## 🧠 Why It Exists

Rusty is not just another profiler — it’s a **learning tool**.

Every piece of design in Rusty is chosen to highlight how:
- Data ownership flows between threads
- Shared mutation happens safely
- Lifetimes and borrowing prevent race conditions

If you’re learning the **Rust borrow checker**, building and extending Rusty
will teach you more effectively than any tutorial can.

---

## ⚙️ How It Works (Conceptually)

1. **Sampler**
   - A background thread wakes up every few milliseconds.
   - It samples a running thread’s call stack using the `backtrace` crate.
   - It sends those samples into a thread-safe queue (`crossbeam::channel`).

2. **Aggregator**
   - Another thread receives these samples.
   - It aggregates them into a `HashMap<FunctionName, CpuTicks>` structure.
   - Inter-thread communication is done safely with `Arc<Mutex<>>`.

3. **Reporter**
   - Periodically prints out summary data.
   - Exposes an API to export results (maybe JSON or flamegraph).

---

## 🏗️ Project Structure
