# Linked List Interview Problems

## Table of Contents
1. [Read-Only Problems](#ro_problems)
   1. [Find the length of a list](#find_length)
   1. [Find an element in a list](#find_element)
   1. [Find the `k`-th node in the list](#find_kth)
   1. [Find the middle node of a list](#find_middle)
   1. [Find the `k`-th last node from the list](#find_kth_last)
   1. [Determine if a list has a cycle](#is_cycle)
   1. [Determine if two lists intersect](#is_intersecting)
   1. [Find the first mismatching nodes between two lists](#mismatch)
   1. [Compare two lists](#compare)
   1. [Determine if a list is a sublist of another](#sublist)
1. [Write/Modify Problems](#wr_problems)
   1. [Fundamental Modify Operations](#fundamental_ops)
   1. [Important Tips](#important_tips)
   1. [Insert an element into a list](#insert)
   1. [Delete list element(s)](#delete)
   1. [Reverse a list](#reverse)
   1. [Determine if a list is palindromic](#palindrome)
   1. [Uniquify the successively repeating elements in a list](#uniquify)
   1. [Remove duplicate items from a list](#remove_dups)
   1. [Rotate a list](#rotate)
   1. [Splice a list in another list](#splice)
   1. [Merge two sorted lists](#merge)
   1. [Interleave two lists](#interleave)
   1. [Split a list into two lists](#split)
   1. [Partition a list](#partition)
   1. [Sort a list](#sort)
1. [Copy Problems](#cp_problems)
   1. [Deep clone a list](#clone)
   1. [Increment arbitrary length number](#increment)
   1. [Add two arbitrary length numbers](#add)

## Read-Only Problems <a name="ro_problems"></a>
In this class of problems, the input list is not modified.

### Find the length of a list <a name="find_length"></a>
Iterate through the entire list and count the number of nodes:
```python
int find(node_type head):
1   node = head
2   count = 0
3   while (node != NULL):
4       count = count + 1
5       node = node.next
6   return count
```

### Find an element in a list <a name="find_element"></a>
Just iterate through the list looking for the element:
```python
node_type find(node_type head, key_type key):
1   node = head
2   while (node != NULL):
3       if node.key == key:
4           return node
5       node = node.next
6   return NULL
```

### Find the `k`-th node in the list <a name="find_kth"></a>
Advance `k` nodes in the list:
```python
node_type find_kth(node_type head, int k):
1   node = head
2   count = 0
3   while (node != NULL and count < k):
4       count = count + 1
5       node = node.next
6   return node
```

### Find the middle node of a list <a name="find_middle"></a>
Use `slow` and `fast` iterators such that the `fast` iterator moves at twice the speed of the `slow` iterator:
```python
node_type find_mid(node_type head):
1   slow = fast = head
2   while (fast != NULL and fast.next != NULL):
3       slow = node.next
4       fast = fast.next.next
5   return slow
```

### Find the `k`-th last node from the list <a name="find_kth_last"></a>
Use `leader` and `follower` iterators such that 'leader' iterator is `k` nodes ahead of `follower` iterator:
```python
node_type find_kth_last(node_type head, int k):
 1  leader = head
 2  count = 0
 3  while (leader != NULL and count < k):
 4      count = count + 1
 5      leader = leader.next
 6  follower = head
 7  while (leader != NULL):
 8      leader = leader.next
 9      follower = follower.next
10  return follower
```

### Determine if a list has a cycle <a name="is_cycle"></a>

#### Variant: Find the intersecting node

### Determine if two lists intersect/overlap <a name="is_intersecting"></a>
Steps:
1. Count the number of nodes in each list
1. Advance a pointer from the head of the longer list so that it is at the same distance from the end as the number of nodes in the shorter list
1. Start a pointer at the head of the shorter list and advance both of them in tandem
1. If they become equal before becoming NULL, the lists intersect; otherwise, not

#### Variant: What if there is a cycle?

### Find the first mismatching nodes between two lists <a name="mismatch"></a>
```python
(node_type, node_type) mismatch(node_type head1, node_type head2):
 1  while (head1 != NULL and head2 != NULL and head1.key == head2.key):
 2      head1 = head1.next
 3      head2 = head2.next
 4  return (head1, head2)
```

### Compare two lists <a name="compare"></a>
```python
bool compare(node_type head1, node_type head2):
 1  (end1, end2) = mismatch(head1, head2)
 2  return end1 == NULL and end2 == NULL
```

### Determine if a list is a sublist of another <a name="sublist"></a>
```python
bool includes(node_type head1, node_type head2):
...
```

## Write/Modify Problems <a name="wr_problems"></a>
In this class of problems, the input list is modified.

### Fundamental Modify Operations <a name="fundamental_ops"></a>
The following are fundamental singly-linked list operations, which serve as building blocks for almost all the problems.

#### Insert a new node after a target node
```python
void insert_after(node_type target, node_type new_node):
 1  next_target = target.next
 2  target.next = new_node
 3  new_node.next = next_target
```
**Note:** The function above assumes that both `target` and `new_node` are not `NULL`.

The above function can be used to insert a new node with a specified key after a target node:
```python
void insert_after(node_type target, key_type key):
 1  new_node = new node_type
 2  new_node.key = key
 3  insert_after(target, new_node)
```

#### Extract a node after a target node
This operation extracts the node after the target node leaving the resulting list to have one fewer node than the original list and returns the extracted node:
```python
node_type extract_after(node_type target):
 1  next_target = target.next
 2  target.next = target.next.next
 3  return next_target
```
**Notes:**
* Similar to `insert_after()`, this method also assumes that `target` is not `NULL`. Further, the extracted node's `next` pointer, if applicable, should be overwritten by the caller
* This method does not allow extracting the list head out of the box. To be able to do that, simply create a dummy node, `pre_head`, set it up to point to the list head (refer to **Tip 1** below), and pass that as `target` as the method argument

#### Delete a node after a target node
Explicit deletion of a node is only applicable (and very important) in unmanaged languages, such as C/C++. Managed languages such as Java, C#, Python, etc., perform garbage collection to reclaim allocated but unreferenced memory. 
```python
void delete_after(node_type target):
 1  delete extract_after(target)
```

### Important Tips <a name="important_tips"></a>
**Tip 1:** Use a terminal/sentinel node for all the problems **_where the original list head may not be the new list head_**. This really simplifies the control flow.

For example, when inserting a new node before a target node in a list, two cases need to be dealt separately:
1. If the target node is NOT the list head, the new node's `next` pointer needs to point to the target node while the `next` pointer of the target node's previous node needs to point to the new node
1. Otherwise, there is no node before the target node and, therefore, only the first of the two `next` pointer settings needs to be done

Here is the pseudocode for it:
```python
node_ptr insert_before(node_type head, node_type target, node_type node):
 1  if target == head:
 2      node.next = head
 3      return node
 4  before_target = head
 5  while (before_target != NULL and before_target.next != target):
 6      before_target = before_target.next
 7  insert_after(before_target, node)
 8  return head
```

Compare the above (lines 1-4) with the following code (lines 1-3) with a dummy node that is set up as the node previous to the list head: 
```python
node_ptr insert_before(node_type head, node_type target, node_type node):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  before_target = pre_head
 4  while (before_target != NULL and before_target.next != target):
 5      before_target = before_target.next
 6  insert_after(before_target, node)
 7  return pre_head.next
```

**Tip 2:** In most of the problems, the key is to have a reference/pointer to the node before the node of interest. A clean way to achieve this is to look ahead by one node. So, prefer this
```python
node = pre_head // node.next = head
while (node != NULL and node.next != target_node)
    node = node.next
```
over
```python
prev_node = pre_head
node = head
while (node != NULL and node != target_node)
    node = node.next
    prev_node = prev_node.next
```

### Insert an element into a list <a name="insert"></a>

#### Variant 1: Insert a key/node before a node
Find the **_node before the target node_**.
```python
node_ptr insert_before(node_type head, node_type target, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node != NULL and node.next != target):
 5      node = node.next
 6  insert_after(node, key)
 7  return pre_head.next
```

#### Variant 2: Insert a key in a sorted list
Find the node before the first node whose key is **_not less than_** `key`. This is same as `insert_before()` above except for the second part of the **while**-loop condition on line 4 where the node key is compared instead of the node itself
```python
node_ptr insert_key(node_type head, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node != NULL and node.next.key > key):
 5      node = node.next
 6  insert_after(node, key)
 7  return pre_head.next
```

### Delete list element(s) <a name="delete"></a>
#### Variants
1. Delete a node
1. Delete a node with a key
1. Delete a node with a key in a sorted list
1. Remove the `k`-th node from the list
1. Remove the middle node from a list
1. Remove the `k`-th last node from the list

#### Variant: Remove multiple elements from a list
Remove all the nodes from a list whose keys match a specified key.
```python
node_ptr delete_all_keys(node_type head, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node != NULL):
 5      if (node != NULL and node.next != NULL and node.next.key == key):
 6          delete_after(node)
 7      node = node.next
 8  return pre_head.next
```

The alternative way to structure the **while**-loop in lines 4-7 is a nested **while**-loop, where the inner loop skips all the nodes whose keys do not match the specified `key`:
```python
 4  while (node != NULL):
 5      while (node != NULL and node.next != NULL and node.next.key != key):
 6          node = node.next
 7      delete_after(node)
 8      node = node.next
```

### Reverse a list <a name="reverse"></a>
For this problem, think of reversing a sequence using a stack. Push each element in the sequence into a stack. The first element in the sequence is at the bottom of the stack while the last element in the sequence is at the top of the stack.
```python
node_type reverse(node_type head):
 1  pre_head = new node_type
 2  pre_head.next = NULL
 3  while (head != NULL):
 4      next_head = head.next
 5      insert_after(node, head)
 6      head = next_head
 7  return dummy_head.next
```
Reversal can also be done recursively, using the following recursive relation:
```
reverse([0, n)) = reverse([1, n)).append({0})
```
Following is the pseudocode for it. Note that the recursive function returns the list tail along with the list head.
```python
node_type reverse(node_type head):
 1  head, tail = reverse_recursive(head)
 2. tail.next = NULL
 3. return head
 
(node_type, node_type) reverse_recursive(node_type head):
 1  if (head.next == NULL):
 2      return head, head
 3  (rhead, rtail) = reverse_recursive(head.next)
 4  insert_after(rtail, head)
 5  return rhead
```

#### Variant: Reverse a sublist
Reverse the sublist specified by the range `[first, last)` in a list. This is a more general case of the problem above in that the pushing of elements into the stack needs to be deferred till the `first` node is found (**while**-loop on lines 4-5 below) in the list and should stop (**while**-loop condition on line 6 below) at the node before the `last` node.

```python
node_type reverse(node_type head, node_type first, node_type last):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  head = pre_head
 4  while (head != NULL and head.next != first):
 5      head = head.next
 6  tail = head
 7  while (head != NULL and head != last):
 8      next_head = head.next
 9      insert_after(tail, head)
10      head = next_head
11  if (first != NULL):
12      first.next = head
13  return pre_head.next
```
It can be verified that the above algorithm takes care of all the following edge cases:
1. Empty range, `[node, node)`, including `[NULL, NULL)`
1. Any node to the end of the list, `[node, NULL)`
1. Entire list, `[head, NULL)`
1. Empty list, i.e., `head` is `NULL`

If the range is expressed as `[first, last]` instead, replace the **while**-loop condition on line 6 above with:
```python
 6  while (head != NULL and head != last.next):
```
**Note:** An empty range may not be specified using inclusive bounds

### Deduplicate (uniquify successively repeating elements in) a list <a name="uniquify"></a>
**Notes:**
* If the list is sorted, it uniquifies the entire list.
* In this problem and its variant below, it is important to actually delete the duplicate nodes in unmanaged code. Otherwise, it may lead to memory leaks. In managed code, there may be simpler algorithms that may work just as well as the algorithms below.

In this problem, the old head is guaranteed to be the new head (because the first element is always in the final list). Following is the pseudocode for it, assuming that `head` is the start of a non-empty list:
```python
node_type dedup(node_type head):
 1  node = head
 2  while (node.next != NULL):
 3      if (node.next.key == node.key):
 4          delete_after(node)
 5      else:
 6          node = node.next
 7  return head;
```

#### Variant: Remove duplicate items from a list <a name="remove_dups"></a>
This problem is a harder variant of the uniquify/dedup problem above. In this problem, a the original head is not guaranteed to be the new head.

Define the following invariants:
* `tail` be the last node in the (new) list with only unique elements
* `tail.next` is the next node whose uniqueness determination is pending
   * If `tail.next.key != tail.next.next.key`, then `tail.next` is unique and it should be added to the new list (line 6 below)
   * Otherwise, delete all the consecutive nodes whose keys are the same as `tail.next.key` (lines 8-10 below)

Following is the pseudocode based on these invariants:
```python
node_type delete_non_unique(node_type head):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  tail = pre_head
 4  while (tail != NULL and tail.next != NULL):
 5      if (tail.next.next == NULL or tail.next.next.key != tail.next.key):
 6          tail = tail.next
 7      else:
 8          key = tail.next.key
 9          while (tail.next and tail.next.key == key):
10              delete_after(tail)
11  tail.next = NULL
11  return pre_head.next
```

### Rotate a list <a name="rotate"></a>
Rotate a list left by `k` nodes, `0 < k < n`, `n` is the length of the list.

Steps:
1. Find the node before the `k`-th node, say `prev_k`, and the list tail, `tail`, in a single pass (`prev_k != tail` because `k < n`)
2. Set the `next` field of the `tail` to the list head
3. Set the `next` field of the `prev_kth` to NULL
4. Return the `k`-th node as the new head

```python
node_type rotate_left(node_type head, int k):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  prev_kth = pre_head
 4  count = 0
 5  while (count < k):
 6      count = count + 1
 7      prev_kth = prev_kth.next
 8  tail = prev_kth
 9  while (tail.next != NULL)
10      tail = tail.next
11  tail.next = head
12  pre_head.next = prev_kth.next
13  prev_kth.next = NULL
14  return pre_head.next
```

#### Variant: `0 < k`
Steps:
1. Find the length of the list, `n`
1. Compute `k` modulo `n`
1. Rotate the list by `k` nodes

### Splice a list in another list <a name="splice"></a>

#### Variant: Splice part of a list in another list

### Merge two sorted lists <a name="merge"></a>
```python
node_type merge(node_type head1, node_type head2):
 1  pre_new_head = new node_type
 2  pre_new_head.key = key
 3  tail = pre_new_head
 4  while (head1 != NULL and head2 != NULL):
 5      if (head1.key <= head2.key)
 6          tail.next = head1
 7          head1 = head1.next
 8      else
 9          tail.next = head2
10          head2 = head2.next
11      tail = tail.next
12  if (head1 == NULL)
13      tail.next = head2
14  else
15      tail.next = head1
16  return pre_new_head.next
```
Recursive approach:
```python
node_type merge(node_type head1, node_type head2):
 1  if (head1 == NULL)
 2      return head2
 3  if (head2 == NULL)
 4      return head1
 5  if (head1.key <= head2.key)
 6      head1.next = merge(head1.next, head2)
 7      return head1
 8  head2.next = merge(head1, head2.next)
 9  return head2
```

### Interleave two lists <a name="interleave"></a>

### Split a list into two lists <a name="split"></a>
One with odd numbered nodes and the other with the rest of the nodes

### Determine if a list is palindromic <a name="palindrome"></a>
Steps:
1. Find the mid-point of the list
1. Reverse the second-half of the list
1. Compare the two halves of the list
1. Reverse the second-half of the list again to restore the original list

### Partition a list <a name="partition"></a>

### Sort a list <a name="sort"></a>

## Copy Problems <a name="cp_problems"></a>

### Deep clone a list <a name="clone"></a>

### Increment arbitrary length number <a name="increment"></a>

### Add two arbitrary length numbers <a name="add"></a>



