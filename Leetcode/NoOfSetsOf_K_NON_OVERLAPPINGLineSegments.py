'''
1621. Number of Sets of K Non-Overlapping Line Segments

Medium

Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

 

Example 1:


Input: n = 4, k = 2
Output: 5
Explanation: The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
Example 2:

Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
Example 3:

Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

'''


# combinatorics 
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        import math
        MOD = 10**9 +7
        return math.comb(n+ k-1, 2*k ) % MOD


'''
In an interview, problems counting valid arrangements rarely admit a greedy approach because choices cannot be made locally without affecting global combinations. The natural progression moves from **recursive / brute force search** to **dynamic programming**, and finally to the **combinatorial shortcut**.

---

**1. Brute Force / Naive DP: $O(n^2 \cdot k)$**

Define $dp[i][j]$ as the number of ways to draw $j$ segments using points from index $0$ to $i$.

* For point $i$, either:
* You don't end a segment at $i$: take $dp[i - 1][j]$.
* You end the $j$-th segment at $i$ starting from some earlier point $p$ ($0 \le p < i$): add $dp[p][j - 1]$.


* **Recurrence:**

$$dp[i][j] = dp[i - 1][j] + \sum_{p=0}^{i-1} dp[p][j - 1]$$


* **Complexity:**
* **Time:** $O(n^2 \cdot k)$ — computing the summation requires an inner loop of length up to $n$.
* **Verdict:** TLE on $n = 1000$.



---

**2. Optimized DP with Prefix Sums / State Tracking: $O(n \cdot k)$**

Notice that the summation term $\sum_{p=0}^{i-1} dp[p][j - 1]$ is just a running prefix sum. Maintain two states: whether a segment is actively open or closed.

* Let:
* $dp[i][j][0]$: Number of ways with $j$ completed segments using points up to $i$ (no active segment ending at $i$).
* $dp[i][j][1]$: Number of ways with $j$ completed segments where the $j$-th segment is actively extended or ending at $i$.


* **Transitions:**
* $dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]$ (carry forward or finish the active segment)
* $dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][0] + dp[i-1][j-1][1]$ (continue existing segment, or start a new segment from point $i-1$)


* **Complexity:**
* **Time:** $O(n \cdot k)$ — no inner loop needed.
* **Space:** $O(n \cdot k)$, reducible to $O(k)$ by rolling array (keeping only the previous row).
* **Verdict:** Optimal DP solution expected by most standard DP interviewers.



---

**3. The Mathematical / Combinatorial Leap: $O(k)$ or $O(1)$**

If asked for further optimization or mathematical insight:

* **Observation:** To place $k$ segments, you need $2k$ endpoints: $s_1 < e_1 \le s_2 < e_2 \le \dots \le s_k < e_k$.
* **Stars and Bars / Index Shift:** The constraint $e_i \le s_{i+1}$ allows consecutive segments to share a point. By adding $k - 1$ duplicate points, every shared endpoint can be split into two strictly distinct points.
* **Selection:** Choosing $2k$ strictly distinct points out of $n + k - 1$ total points directly forms a valid configuration.
* **Formula:**

$$\binom{n + k - 1}{2k} \pmod{10^9 + 7}$$


* **Complexity:**
* **Time:** $O(k)$ arithmetic steps (or $O(1)$ using Python's `math.comb`).
* **Space:** $O(1)$.


'''