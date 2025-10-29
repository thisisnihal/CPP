Great! Let’s **understand how LRU Cache works** with a clear **step-by-step explanation and table**.

---

### ✅ LRU Cache: What It Does

LRU (Least Recently Used) cache:

* Stores a fixed number of key-value pairs.
* On **every access**, it marks the key as "most recently used".
* When the cache is **full**, it removes the **least recently used** item to make space.

---

### 🔁 Operations:

* `get(key)` → Return value if present and mark as most recently used.
* `put(key, value)` → Insert/update value; evict LRU if full.

---

### 🧪 Example:

Let’s take:

* **Capacity = 3**
* Operations:

```
put(1, 100)
put(2, 200)
put(3, 300)
get(2)
put(4, 400)
get(1)
get(3)
```

---

### 📊 Step-by-Step Table

| Step | Operation   | Action                                 | Cache (Most → Least Recent) |
| ---- | ----------- | -------------------------------------- | --------------------------- |
| 1    | put(1, 100) | Insert 1                               | \[1]                        |
| 2    | put(2, 200) | Insert 2                               | \[2, 1]                     |
| 3    | put(3, 300) | Insert 3                               | \[3, 2, 1]                  |
| 4    | get(2)      | Access 2 → Move to front               | \[2, 3, 1]                  |
| 5    | put(4, 400) | Cache full → Evict LRU (1), Insert 4   | \[4, 2, 3]                  |
| 6    | get(1)      | Not in cache (was evicted) → Return -1 | \[4, 2, 3]                  |
| 7    | get(3)      | Access 3 → Move to front               | \[3, 4, 2]                  |

---

### 🔍 Visual Representation

After each step:

```
Step 1: [1]
Step 2: [2, 1]
Step 3: [3, 2, 1]
Step 4: [2, 3, 1]     (accessed 2)
Step 5: [4, 2, 3]     (evicted 1, inserted 4)
Step 6: [4, 2, 3]     (1 not found)
Step 7: [3, 4, 2]     (accessed 3)
```

---

### 🧠 Key Concepts

| Concept                 | Description          |
| ----------------------- | -------------------- |
| **Most Recently Used**  | Moved to front       |
| **Least Recently Used** | Removed when full    |
| **Doubly Linked List**  | Tracks order         |
| **Hash Map**            | O(1) access to nodes |

---

### ✅ Conclusion

* LRU = Evict **least used** when full
* Always move accessed/added keys to the **front**
* Combination of **Hash Map** + **Doubly Linked List** gives **O(1)** for both `get` and `put`

Would you like a **real-world analogy** (e.g., browser tabs or RAM pages) or want to try a small **interactive question** to test your understanding?
