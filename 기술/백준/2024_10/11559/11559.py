lines =[]
for _ in range(12):
  lines.append(list(input()))
  
floor_num = 11
ceil_num = 0
room_max = 5
room_min = 0
up_num = -1
down_num = 1
shape = 0
data = 1

stack = []
isBoob = True
count = 0
for x in range(floor_num, ceil_num - 1,up_num):
  lines[x] = [[item,0] for item in lines[x]]
  # print(lines[x])

def check(floor,room):
  if lines[floor][room][data] == 1:
    return
  lines[floor][room][data] = 1
  # print(lines[floor][room])
  stack.append([floor,room])
  if floor - 1 >= ceil_num and lines[floor - 1][room][data] == 0 and lines[floor][room][shape] == lines[floor - 1][room][shape]:
    check(floor - 1, room)
  if floor + 1 <= floor_num and lines[floor + 1][room][data] == 0 and lines[floor][room][shape] == lines[floor + 1][room][shape]:
    check(floor + 1, room)
  if room - 1 >= room_min and lines[floor][room - 1][data] == 0 and lines[floor][room][shape] == lines[floor][room - 1][shape]:
    check(floor, room - 1)
  if room + 1 <= room_max and lines[floor][room + 1][data] == 0 and lines[floor][room][shape] == lines[floor][room + 1][shape]:
    check(floor, room + 1)

while isBoob:
  isBoob = False

  # print("count1")
  # for x in range(floor_num, ceil_num - 1,up_num):
  #   print(lines[x])

  for room in range(room_min,room_max + 1):
    for floor in range(floor_num,ceil_num - 1,up_num):
      if lines[floor][room][shape] == '.':
        continue
      check(floor,room)

      if len(stack) >= 4:
        isBoob = True
        for item in stack:
          lines[item[0]][item[1]][shape] = "."
          lines[item[0]][item[1]][data] = 0
      stack.clear()

      pass
    pass
  pass

  # print("count2")
  # for x in range(floor_num, ceil_num - 1,up_num):
  #   print(lines[x])

  for room in range(room_min,room_max + 1):
    top = floor_num
    for floor in range(floor_num,ceil_num - 1,up_num):
      if lines[floor][room][data] == 0:
        continue
      elif lines[floor][room][data] == 1:
        lines[top][room], lines[floor][room] = lines[floor][room] ,lines[top][room]
        lines[top][room][data] = 0
        top -= 1

  if isBoob:
    count += 1

print(count)