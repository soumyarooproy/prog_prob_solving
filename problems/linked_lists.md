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
1. [Write/Modify Problems](#wr_problems)
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

## Write/Modify Problems <a name="wr_problems"></a>
In this class of problems, the input list is modified.

**Important Tip 1:** Use a terminal/sentinel node for all the problems **_where the original list head may not be the new list head_**. This really simplifies the control flow.

For example, when inserting a new node before a target node in a list, two cases need to be dealt separately:
1. If the target node is NOT the list head, the new node's `next` pointer needs to point to the target node while the `next` pointer of the target node's previous node needs to point to the new node
1. Otherwise, there is no node before the target node and, therefore, only the first of the two `next` pointer settings needs to be done

Here is the pseudocode for it:
```python
node_ptr insert_before(node_type head, node_type target, node_type node):
 1  if target == head:
 2      node.next = head
 3      return node
 4  ptr = head
 5  while (ptr != NULL and ptr.next != target):
 6      ptr = ptr.next
 7  ptr.next = node
 8  node.next = target
 9  return head
```

Compare the above with the following code with a dummy node that is set up as the node previous to the list head: 
```python
node_ptr insert_before(node_type head, node_type target, node_type node):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  ptr = pre_head
 5  while (ptr != NULL and ptr.next != target):
 6      ptr = ptr.next
 7  ptr.next = node
 8  node.next = target
 9  return pre_head.next
```

**Important Tip 2:** In most of the problems, the key is to not just have a reference/pointer to the node of interest but also to its predecessor node. The clean way to achieve this is to look ahead by one node.
```python
node = pre_head // node.next = head
while (node != NULL and node.next != target_node)
    node = node.next
```
instead of doing
```python
prev_node = pre_head
node = head
while (node != NULL and node != target_node)
    node = node.next
    prev_node = prev_node.next
```

### Insert an element into a list <a name="insert"></a>
**Variants:**
1. Insert a key before a node
   * Find the **_node before the target node_** and **_use a dummy_** head because the new head may be different than the old head
1. Insert a key after a node
   * Find the target node but **_no need to use a dummy head_** because the new head will be the same as the old head
1. Insert a key in a sorted list
   * Find the node before the first node whose key is **_not less than_** `key` and use a dummy head

#### Insert a key before a node
The **while**-loop condition in line 4 compares `node.next` with `target`. Contrast this with the **while**-loop in the `insert_after()` method further below where `node` and not `node.next` is compared with `target`. Lines `1-3` set up the dummy head and initializes the `node` iterator to point to it. Lines `8-9` insert the new node created in lines 6-7 with the key `key`.
```python
node_ptr insert_before(node_type head, node_type target, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node != NULL and node.next != target):
 5      node = node.next
 6  if (node != NULL):
 7      new_node = new node_type
 8      new_node.key = key
 9      node.next = new_node
10      new_node.next = target
11  return pre_head.next
```
#### Insert a key after a node
Note the signature of `insert_after()`. It does not return anything. If it is needed to return `node_type`, just return `head`.
```python
void insert_after(node_type head, node_type target, key_type key):
 1  node = head
 2  while (node != NULL and node != target):
 3      node = node.next
 4  if (node != NULL):
 5      new_node = new node_type
 6      new_node.key = key
 7      next_node = node.next
 8      node.next = new_node
 9      new_node.next = next_node
```

#### Insert a key in a sorted list
This is same as `insert_before()` above except for the second part of the **while**-loop condition on line 4 where the key is compared instead of the node itself.
```python
node_ptr insert_key(node_type head, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node != NULL and node.next.key > key):
 5      node = node.next
 6  if (node != NULL):
 7      new_node = new node_type
 8      new_node.key = key
 9      next_node = node.next
10      node.next = new_node
11      new_node.next = next_node
12  return pre_head.next
```

### Delete list element(s) <a name="delete"></a>
#### Variants
1. Delete a node
1. Delete a node with a key
1. Delete a node with a key in a sorted list
1. Remove the `k`-th node from the list
1. Remove the middle node from a list
1. Remove the `k`-th last node from the list
1. Remove multiple elements from a list

Again, similar to `insert_after()`, `delete_after()` does not return anything. If it is needed to return `node_type`, just return `head`.
```python
void delete_after(node_type head, node_type target):
 1  node = head
 2  while (node != NULL and node != target):
 3      node = node.next
 4  if (node != NULL and node.next != NULL):
 6      target = node.next
 7      node.next = node.next.next
 8      delete target
```

### Reverse a list <a name="reverse"></a>
For this problem, think of reversing a sequence using a stack. Push each element in the sequence into a stack. The first element in the sequence is at the bottom of the stack while the last element in the sequence is at the top of the stack.
```python
node_type reverse(node_type head)
 1  pre_head = new node_type
 2  pre_head.next = NULL
 3  while (head != NULL):
 4      head_next = head.next
 5      head.next = pre_head.next
 6      pre_head.next = head
 7      head = head_next
 8  return dummy_head.next
```

#### Variant: Reverse a sublist
Reverse the sublist specified by the range `[first, last)` in a list. This is a more general case of the problem above in that the pushing of elements into the stack needs to be deferred till the `first` node is found (**while**-loop on lines 4-5 below) in the list and should stop (**while**-loop condition on line 6 below) at the node before the `last` node.

```python
node_type reverse(node_type head, node_type first, node_type last)
 1  pre_head = new node_type
 2  pre_head.next = head
 3  head = pre_head
 4  while (head != NULL and head.next != first)
 5      head = head.next
 6  while (head != NULL and head != last):
 7      head_next = head.next
 8      head.next = pre_head.next
 9      pre_head.next = head
10      head = head_next
11  if (first != NULL):
12      first.next = head
13  return dummy_head.next
```
It can be verified that the above algorithm takes care of all the edge cases
1. Empty range, `[node, node)`, including `[NULL, NULL)`
1. Any node to the end of the list, `[node, NULL)`
1. Entire list, `[head, NULL)`

If the range is expressed as `[first, last]` instead, replace the **while**-loop condition on line 6 above with:
```python
 6  while (head != NULL and head != last.next):
```
**Note:** An empty range may not be specified using inclusive bounds

### Determine if a list is palindromic <a name="palindrome"></a>
Steps:
1. Find the mid-point of the list
1. Reverse the second-half of the list
1. Compare the two halves of the list
1. Reverse the second-half of the list again to restore the original list

### Uniquify the successively repeating elements in a list <a name="uniquify"></a>
**_Note that if the list is sorted, it uniquifies the entire list list_**

### Remove duplicate items from a list <a name="remove_dups"></a>

### Rotate a list <a name="rotate"></a>
By `0 < k < n`, `n` is the length of the list, nodes

#### Variant: `0 < k`
Steps:
1. Find the length of the list, `n`
1. Compute `k` modulo `n`
1. Rotate the list by `k` nodes

### Splice a list in another list <a name="splice"></a>

#### Variant: Splice part of a list in another list

### Merge two sorted lists <a name="merge"></a>

### Interleave two lists <a name="interleave"></a>

### Split a list into two lists <a name="split"></a>
One with odd numbered nodes and the other with the rest of the nodes

### Partition a list <a name="partition"></a>

## Copy Problems <a name="cp_problems"></a>

### Deep clone a list <a name="clone"></a>

### Increment arbitrary length number <a name="increment"></a>

### Add two arbitrary length numbers <a name="add"></a>



