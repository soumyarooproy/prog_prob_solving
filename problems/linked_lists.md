# Linked list problems

## Read-only Problems
In this class of problems, the input list is not modified.

### Find an element in a list
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

### Find the length of a list
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

### Find the `k`-th node in the list
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

### Find the middle node of a list
Use `slow` and `fast` iterators such that the `fast` iterator moves at twice the speed of the `slow` iterator:
```python
node_type find_mid(node_type head):
1   slow = fast = head
2   while (fast != NULL and fast.next != NULL):
3       slow = node.next
4       fast = fast.next.next
5   return slow
```

### Find the `k`-th last node from the list
Use `leader` and `follower` iterators such that 'leader' iterator is `k` steps ahead of `follower` iterator:
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

### Determine if a list has a cycle

#### Variant: Find the intersecting node

### Determine if two lists intersect

#### Variant: What if there is a cycle?

## Write/Modify Problems
In this class of problems, the input list is modified.

**Important Tip:** Use a terminal/sentinel node for all the problems **_where the original list head may not be the new list head_**

### Insert an element into a list
#### Variants
1. Insert a key before a node
   * Find the **_node before the target node_** and **_use a dummy_** head because the new head may be different than the old head
1. Insert a key after a node
   * Find the target node but **_no need to use a dummy head_** because the new head will be the same as the old head
1. Insert a key in a sorted list
   * Find the node before the first node whose key is **_not less than_** `key` and use a dummy head

The **while**-loop condition in line 4 compares `node.next` with `target`. Contrast this with the **while**-loop in the `insert_after()` method further below where `node` and not `node.next` is compared with `target`. Lines `1-3` set up the dummy head and initializes the `node` iterator to point to it. Lines `8-9` insert the new node created in lines 6-7 with the key `key`.
```python
node_ptr insert_before(node_type head, node_type target, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node.next != NULL and node.next != target):
 5      node = node.next
 6  new_node = new node_type
 7  new_node.key = key
 8  node.next = new_node
 9  new_node.next = target
10  return pre_head.next
```

Note the signature of `insert_after()`. It does not return anything. If it is needed to return `node_type`, just return `head`.
```python
void insert_after(node_type head, node_type target, key_type key):
 1  node = head
 2  while (node != NULL and node != target):
 3      node = node.next
 4  if (node == NULL)
 5      return
 6  new_node = new node_type
 7  new_node.key = key
 8  next_node = node.next
 9  node.next = new_node
10  new_node.next = next_node
```

This is same as `insert_before()` above except for the second part of the **while**-loop condition on line 4 where the key is compared instead of the node itself.
```python
node_ptr insert_key(node_type head, key_type key):
 1  pre_head = new node_type
 2  pre_head.next = head
 3  node = pre_head
 4  while (node.next != NULL and node.next.key > key):
 5      node = node.next
 6  new_node = new node_type
 7  new_node.key = key
 8  next_node = node.next
 9  node.next = new_node
10  new_node.next = next_node
11  return pre_head.next
```

### Delete list element(s)
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
1   node = head
2   while (node != NULL and node != target):
3       node = node.next
4   if (node == NULL or node.next == NULL):
5       return
6   target = node.next
7   node.next = node.next.next
8   delete target
```

### Reverse a list

#### Variant: Reverse a sublist

### Determine if a list is palindromic
Steps:
1. Find the mid-point of the list
1. Reverse the second-half of the list
1. Compare the two halves of the list
1. Reverse the second-half of the list again to restore the original list

### Uniquify the successively repeating elements in a list
**_Note that if the list is sorted, it uniquifies the entire list list_**

### Remove duplicate items from a list

### Rotate a list (by `0 < k < n`, `n` is the length of the list, nodes)

#### Variant: `0 < k`
Steps:
1. Find the length of the list, `n`
1. Compute `k` modulo `n`
1. Rotate the list by `k` nodes

### Splice a list in another list

#### Variant: Splice part of a list in another list

### Merge two sorted lists

### Interleave two lists 

### Split a list into two lists -- one with odd numbered nodes and the other with the rest of the nodes

### Partition a list

## Copy Problems

### Deep clone a list

### Increment arbitrary length number

### Add two arbitrary length numbers




