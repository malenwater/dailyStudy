# 2024/10/07
class Tree:
  def __init__(self,value):
    self.value = value
    self.child = {}
  def add_child(self,child):
    self.child[child.value] = child
  def get_child_value(self):
    return [path for path in self.child]

T = int(input())
for _ in range(1,T+1):
  user_input = input()
  user_input = user_input.split(" ")
  N, M = int(user_input[0]),int(user_input[1])
  root = Tree('')
  count = 0

  for __ in range(N):
    user_input = input()
    user_input = user_input.split("/")
    it = root
    for path in user_input:
      if path == '':
        continue
      if path not in it.get_child_value():
        it.add_child(Tree(path))
      it = it.child[path]

  for __ in range(M):
    user_input = input()
    user_input = user_input.split("/")
    it = root
    for path in user_input:
      if path == '':
        continue
      if path not in it.get_child_value():
        it.add_child(Tree(path))
        count += 1
      it = it.child[path]

  print(f"Case #{_}: {count}")
  