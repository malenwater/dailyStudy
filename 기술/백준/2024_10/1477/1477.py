# 2024/10/04
# 6 7 800
# 622 411 201 555 755 82
# ===> 70
import math
N,M,L = input().split(" ")
place = ["0",L]
place_dict = []
place_dict_len = []
place_dict_number = []
if N != "0":
  place += input().split(" ")
place = sorted([int(x) for x in place])
for index in range(len(place) - 1):
  place_dict.append(place[index+1]-place[index])
  place_dict_len.append(place[index+1]-place[index])
  place_dict_number.append(1)
for _ in range(int(M)):
  max_int = max(place_dict_len)
  max_index = place_dict_len.index(max_int)
  place_dict_number[max_index] += 1
  place_dict_len[max_index] = math.ceil(place_dict[max_index] / place_dict_number[max_index])
max_int = max(place_dict_len)
print( max_int)