<h2><a href="https://www.geeksforgeeks.org/problems/replace-the-bit3212/0">Replace the Bit</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;">Given two&nbsp;numbers N&nbsp;and K, change the Kth (1-based indexing)&nbsp;bit from the left of the binary representation of the number N&nbsp;to&nbsp;'0' if it is &nbsp;'1', else return the number N&nbsp;itself.</span></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 13, K = 2
<strong>Output:</strong> 9
<strong>Explanation</strong>: Binary representation of 13 is
1<strong>1</strong>01. The 2nd bit from left is 1, we make
it 0 and result is 1001 = 9 (decimal).</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
N = 13, K = 6
<strong>Output:</strong> 13
<strong>Explanation</strong>: Binary representation of 13 is
1101. There's no 6th bit from left,
hence we return the number itself.</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>replaceBit()&nbsp;</strong>which takes the integers N and K as inputs and returns the resultant number after the stated modifications.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(LogN).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;=N&lt;=10<sup>6</sup></span></p>
<p>&nbsp;</p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Bit Magic</code>&nbsp;<code>Data Structures</code>&nbsp;